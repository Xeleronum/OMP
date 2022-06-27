#include "View.h"
#include <QMouseEvent>
#include <ranges>

#include "MRect.h"
#include "MEllipse.h"
#include "MTriangle.h"

View::View(QWidget* parent) : QGraphicsView(parent)
{
	setFrameStyle(Sunken | StyledPanel);
	setRenderHint(QPainter::Antialiasing, false);
	setOptimizationFlags(QGraphicsView::DontSavePainterState);
	setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

View::View(QGraphicsScene* scene, QWidget* parent)
	: QGraphicsView(scene, parent)
{
	setFrameStyle(Sunken | StyledPanel);
	setRenderHint(QPainter::Antialiasing, false);
	setOptimizationFlags(QGraphicsView::DontSavePainterState);
	setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

View::~View() = default;

void View::addedItems(QMouseEvent* event)
{
	MAbstractItem* item{ nullptr };
	auto posCenter = mapToScene(event->pos());
	switch (modeClck)
	{
	case ModeClick::AddRect:	 item = new MRect(posCenter, { 50,50 }, Qt::red); break;
	case ModeClick::AddEllipse:	 item = new MEllipse(posCenter, { 50,50 }, Qt::green); break;
	case ModeClick::AddTriangle: item = new MTriangle(posCenter, { 50, 50 }, Qt::blue); break;
	default: break;
	}
	if (item != nullptr) {
		scene()->addItem(item);
		items.push_back(std::move(item));
		return;
	}
}

void View::addedConnect()
{
	if (ModeClick::Connect == modeClck)
	{
		auto sel = std::ranges::find_if(items, [](auto it) { return it->isSelected(); });
		if (sel != items.end() && (*sel)->type() != static_cast<int>(MItemType::Connector)) {
			if (bufAddConn.first == nullptr) {
				bufAddConn.first = *sel;
			}
			else if (bufAddConn.second == nullptr && *sel != bufAddConn.first)
			{
				bufAddConn.second = *sel;
				auto newConnection = new MConnector(bufAddConn.first, bufAddConn.second, Qt::black);
				scene()->addItem(newConnection);
				connectors.push_back(newConnection);
				bufAddConn = {};
			}
		}
	}
}
void View::delItems()
{
	if (ModeClick::Del == modeClck && !items.empty())
	{
		auto sel = std::ranges::find_if(items, [](auto it) { return it->isSelected(); });
		if (sel != items.end()) {
			while (true)
			{
				auto conForDelet = std::ranges::find_if(connectors, [sel](MConnector* it) { return it->containItem((*sel)); });
				if (conForDelet == connectors.end()) {
					break;
				}
				else
				{
					delete (*conForDelet);
					connectors.erase(conForDelet);
				}
			}
			delete (*sel);
			items.erase(sel);
		}
	}
}

void View::mousePressEvent(QMouseEvent* event)
{
	addedItems(event);
	QGraphicsView::mousePressEvent(event);
	addedConnect();
	
	delItems();
	update();
}

void View::mouseDoubleClickEvent(QMouseEvent* event)
{
	return;
}

void View::setUpModeMouseLeft(ModeClick mode)
{
	modeClck = mode;
	auto moveble = mode == ModeClick::Move ? true : false;
	for (auto i : items)
	{
		i->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsMovable, moveble);
	}

	setInteractive(mode == ModeClick::Nothing ? false : true);
}
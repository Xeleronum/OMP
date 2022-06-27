#include "MConnector.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

MConnector::MConnector(QColor clr, QGraphicsItem* parent)
	: QGraphicsItem(parent)
	, color(clr)
{
	setZValue(100);
	setFlags(ItemIsSelectable);
	setAcceptHoverEvents(true);
	setCacheMode(QGraphicsItem::NoCache);
}

MConnector::MConnector(MAbstractItem* first, MAbstractItem* second, QColor clr, QGraphicsItem* parent)
	: QGraphicsItem(parent)
	, color(clr)
	, connectionItems{ first, second }
{
	setZValue(100);
	setFlags(ItemIsSelectable);
	setAcceptHoverEvents(true);
	setCacheMode(QGraphicsItem::NoCache);
}

QRectF MConnector::boundingRect() const
{
	if (connectionItems.first == nullptr || connectionItems.second == nullptr) return {};

	QPolygonF pol{ connectionItems.first->getCenter(), connectionItems.second->getCenter() };
	return pol.boundingRect();
}

QPainterPath MConnector::shape() const
{
	QPainterPath pp;
	pp.addPolygon({ connectionItems.first->getCenter(), connectionItems.second->getCenter() });
	return pp;
}

void MConnector::paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget)
{
	if (connectionItems.first != nullptr && connectionItems.second != nullptr)
	{
		QColor fillColor = (item->state & QStyle::State_Selected) ? color.darker(150) : color;
		if (item->state & QStyle::State_MouseOver)
			fillColor = fillColor.lighter(125);

		QBrush b = painter->brush();
		painter->setBrush(fillColor);

		painter->drawLine(connectionItems.first->getCenterInScene(), connectionItems.second->getCenterInScene());
		painter->setBrush(b);
	}
}

void MConnector::setFirstItem(MAbstractItem* first)
{
	connectionItems.first = first;
}

void MConnector::setSecondItem(MAbstractItem* second)
{
	connectionItems.second = second;
}

bool MConnector::containItem(MAbstractItem* itm) const
{
	if (itm == connectionItems.first || itm == connectionItems.second) {
		return true;
	}
	return false;
}
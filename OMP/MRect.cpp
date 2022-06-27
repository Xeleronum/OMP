#include "MRect.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

MRect::MRect(QGraphicsItem* parent) :
	MAbstractItem(parent)
{
}

MRect::MRect(const QRectF& rct, QColor clr, QGraphicsItem* parent)
	: MAbstractItem(parent)
	, rect{ rct }
	, color(clr)
{
}

MRect::MRect(QPointF center, QVector2D size, QColor clr, QGraphicsItem* parent)
	: MAbstractItem(parent)
	, rect(center.x() - size.x() / 2., center.y() - size.y() / 2., size.x(), size.y())
	, color(clr)
{
}

void MRect::setCenter(QPointF pointCentr)
{
	auto delta = pointCentr - getCenter();
	rect.setX(rect.x() + delta.x());
	rect.setY(rect.y() + delta.y());
	return;
}

QRectF MRect::boundingRect() const
{
	return rect;
}

QPainterPath MRect::shape() const
{
	QPainterPath pp;
	pp.addRect(rect);
	return pp;
}

void MRect::paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget)
{
	Q_UNUSED(widget);

	QColor fillColor = (item->state & QStyle::State_Selected) ? color.darker(150) : color;
	if (item->state & QStyle::State_MouseOver)
		fillColor = fillColor.lighter(125);

	QBrush b = painter->brush();
	painter->setBrush(fillColor);
	painter->drawRect(rect);
	painter->setBrush(b);
	return;
}

void MRect::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsItem::mouseMoveEvent(event);
}
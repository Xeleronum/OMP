#include "MEllipse.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

MEllipse::MEllipse(QGraphicsItem* parent) :
	MAbstractItem(parent)
{
}

MEllipse::MEllipse(const QRectF& rct, QColor clr, QGraphicsItem* parent)
	: MAbstractItem(parent)
	, rect{ rct }
	, color(clr)
{
}

MEllipse::MEllipse(QPointF center, QVector2D size, QColor clr, QGraphicsItem* parent)
	: MAbstractItem(parent)
	, rect(center.x() - size.x() / 2., center.y() - size.y() / 2., size.x(), size.y())
	, color(clr)
{
}

void MEllipse::setCenter(QPointF pointCentr)
{
	auto delta = pointCentr - getCenter();
	rect.setX(rect.x() + delta.x());
	rect.setY(rect.y() + delta.y());
	return;
}

QRectF MEllipse::boundingRect() const
{
	return rect;
}

QPainterPath MEllipse::shape() const
{
	QPainterPath pp;
	pp.addEllipse(rect);
	return pp;
}

void MEllipse::paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget)
{
	Q_UNUSED(widget);

	QColor fillColor = (item->state & QStyle::State_Selected) ? color.darker(150) : color;
	if (item->state & QStyle::State_MouseOver)
		fillColor = fillColor.lighter(125);

	QBrush b = painter->brush();
	painter->setBrush(fillColor);
	painter->drawEllipse(rect);
	painter->setBrush(b);
	return;
}
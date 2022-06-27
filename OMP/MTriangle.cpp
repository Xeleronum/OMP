#include "MTriangle.h"
#include <QVector2D>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

MTriangle::MTriangle(QPointF p1, QPointF p2, QPointF p3, QColor color, QGraphicsItem* parent)
	: MAbstractItem(parent)
	, triangle{ p1, p2, p3 }
	, color(color)
{}

MTriangle::MTriangle(QPointF center, QVector2D radius, QColor color, QGraphicsItem* parent)
	: MAbstractItem(parent)
	, color(color)
{
	auto constexpr seg1 = M_PI_2;
	auto constexpr seg2 = (7 * M_PI) / 6;
	auto constexpr seg3 = (11 * M_PI) / 6;

	triangle << QPointF(center.x() + radius.x() / 2 * cos(seg1), center.y() + radius.y() / 2 * sin(seg1));
	triangle << QPointF(center.x() + radius.x() / 2 * cos(seg2), center.y() + radius.y() / 2 * sin(seg2));
	triangle << QPointF(center.x() + radius.x() / 2 * cos(seg3), center.y() + radius.y() / 2 * sin(seg3));
}

void MTriangle::setCenter(QPointF pointCentr)
{
	auto delta = pointCentr - getCenter();
	for (auto& i : triangle)
	{
		i += delta;
	}

	return;
}

QPointF MTriangle::getCenter() const
{
	QPointF point{ 0,0 };

	for (auto& i : triangle)
	{
		point += i;
	}
	return (point / 3.);
}

QRectF MTriangle::boundingRect() const
{
	return triangle.boundingRect();
}

QPainterPath MTriangle::shape() const
{
	QPainterPath pp;
	pp.addPolygon(triangle);

	return pp;
}

void MTriangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget)
{
	Q_UNUSED(widget);

	QColor fillColor = (item->state & QStyle::State_Selected) ? color.darker(150) : color;
	if (item->state & QStyle::State_MouseOver)
		fillColor = fillColor.lighter(125);

	QBrush b = painter->brush();
	painter->setBrush(fillColor);
	painter->drawPolygon(triangle);
	painter->setBrush(b);
	return;
}
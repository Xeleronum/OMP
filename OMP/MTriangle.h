#pragma once
#include "MAbstractItem.h"

struct MTriangle :
	public MAbstractItem
{
	explicit MTriangle(QPointF p1, QPointF p2, QPointF p3, QColor color, QGraphicsItem* parent = nullptr);

	MTriangle(QPointF center, QVector2D radius, QColor color, QGraphicsItem* parent = nullptr);

	enum { Type = MItemType::Triangle };
	int type() const override { return Type; };
	MItemType Mtype() const override { return MItemType::Triangle; };

	void setCenter(QPointF pointCentr)override;
	QPointF getCenter() const override;
	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget) override;
private:
	QPolygonF triangle;
	QColor color{};
};

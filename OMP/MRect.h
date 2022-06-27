#pragma once
#include "MAbstractItem.h"
#include <qvector2d.h>

struct MRect :
	public MAbstractItem
{
	explicit MRect(QGraphicsItem* parent = nullptr);
	explicit MRect(const QRectF& rct, QColor color, QGraphicsItem* parent = nullptr);
	explicit MRect(QPointF center, QVector2D size, QColor color, QGraphicsItem* parent = nullptr);

	enum { Type = MItemType::Rect };
	int type() const override { return Type; };
	MItemType Mtype() const override { return MItemType::Rect; };

	void setCenter(QPointF pointCentr)override;

	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget) override;

	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
private:
	QRectF rect{};
	QColor color{};
};

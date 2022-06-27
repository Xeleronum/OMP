#pragma once
#include "MAbstractItem.h"
#include <qvector2d.h>

struct MEllipse :
	public MAbstractItem
{
	explicit MEllipse(QGraphicsItem* parent = nullptr);
	explicit MEllipse(const QRectF& rct, QColor color, QGraphicsItem* parent = nullptr);
	explicit MEllipse(QPointF center, QVector2D size, QColor color, QGraphicsItem* parent = nullptr);

	enum { Type = MItemType::Ellipse };
	int type() const override { return Type; };
	MItemType Mtype() const override { return MItemType::Ellipse; };

	void setCenter(QPointF pointCentr)override;

	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget) override;
private:
	QRectF rect{};
	QColor color{};
};

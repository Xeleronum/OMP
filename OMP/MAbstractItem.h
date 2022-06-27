#pragma once
#include <QGraphicsItem>
#include "MItemType.h"

struct MAbstractItem :
	public QGraphicsItem
{
	explicit MAbstractItem(QGraphicsItem* parent = nullptr);

	enum { Type = MItemType::Base };
	int type() const override { return Type; };
	virtual MItemType Mtype() const { return MItemType::Base; };

	virtual QPointF getCenter()const;
	virtual QPointF getCenterInScene()const;

	virtual void setCenter(QPointF) = 0;

protected:

	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
signals:
	[[maybe_unused]]void destroy();
};

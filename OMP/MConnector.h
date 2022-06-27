#pragma once

#include <QGraphicsItem>
#include "MItemType.h"
#include "MAbstractItem.h"

struct MConnector :
	public QGraphicsItem
{
	explicit MConnector(QColor color, QGraphicsItem* parent = nullptr);
	explicit MConnector(MAbstractItem* first, MAbstractItem* second, QColor color, QGraphicsItem* parent = nullptr);

	enum { Type = MItemType::Connector };
	int type() const override { return Type; };
	virtual MItemType Mtype() const { return MItemType::Connector; };

	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget) override;

	void setFirstItem(MAbstractItem* first);
	void setSecondItem(MAbstractItem* second);
	bool containItem(MAbstractItem* itm) const;
private:
	QColor color{ };
	std::pair<MAbstractItem*, MAbstractItem*> connectionItems{ nullptr, nullptr };
};

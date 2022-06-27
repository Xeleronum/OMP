#include "MAbstractItem.h"
#include <QGraphicsSceneMouseEvent>

MAbstractItem::MAbstractItem(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	setZValue(0);
	setFlags(ItemIsSelectable | ItemIsMovable);
	setAcceptHoverEvents(true);
}

QPointF MAbstractItem::getCenter() const
{
	return boundingRect().center();
}

QPointF MAbstractItem::getCenterInScene() const
{
	auto posCS = boundingRect().center() + pos();
	return posCS;
}


void MAbstractItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

//void MAbstractItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
//{
//    QGraphicsItem::mouseMoveEvent(event);
//}

void MAbstractItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}

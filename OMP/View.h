#pragma once
#include <QGraphicsView>
#include <list>
#include <memory>

#include "MAbstractItem.h"
#include "MConnector.h"

enum class ModeClick
{
	Nothing
	, AddRect
	, AddEllipse
	, AddTriangle
	, Connect
	, Move
	, Del
};
struct View :
	public QGraphicsView
{
	View(QWidget* parent = nullptr);
	View(QGraphicsScene* scene, QWidget* parent = nullptr);
	~View()override;


	void mousePressEvent(QMouseEvent* event)override;
	void mouseDoubleClickEvent(QMouseEvent* event) override;

public slots:
	void setUpModeMouseLeft(ModeClick);
private:

	void addedItems(QMouseEvent* event);

	void addedConnect();

	void delItems();
private:
	ModeClick modeClck{ ModeClick::Nothing };
	std::list<MAbstractItem*> items;
	std::list<MConnector*> connectors;//maybe use smart_ptr??
	std::pair <MAbstractItem*, MAbstractItem*> bufAddConn{ nullptr ,nullptr };
};

#include "OMP.h"
#include <QGraphicsScene>

#include "MRect.h"

OMP::OMP(QWidget* parent)
	: QMainWindow(parent)
{
	setupUi(this);
	scene.setParent(graphicsView);
	scene.setSceneRect(0, 0, 640, 480);
	graphicsView->setScene(&scene);

	connect(this, &OMP::setUpModeLeftClick, graphicsView, &View::setUpModeMouseLeft);
	graphicsView->update();
}

OMP::~OMP() = default;

void OMP::on_bRect_clicked()
{
	if (bEllipse->isEnabled() && bTriangle->isEnabled())
	{
		bEllipse->setEnabled(false);
		bTriangle->setEnabled(false);
		gbModItem->setEnabled(false);
		emit setUpModeLeftClick(ModeClick::AddRect);
	}
	else
	{
		bEllipse->setEnabled(true);
		bTriangle->setEnabled(true);
		gbModItem->setEnabled(true);

		emit setUpModeLeftClick(ModeClick::Nothing);
	}
}

void OMP::on_bEllipse_clicked()
{
	if (bRect->isEnabled() && bTriangle->isEnabled())
	{
		bRect->setEnabled(false);
		bTriangle->setEnabled(false);
		gbModItem->setEnabled(false);
		emit setUpModeLeftClick(ModeClick::AddEllipse);
	}
	else
	{
		bRect->setEnabled(true);
		bTriangle->setEnabled(true);
		gbModItem->setEnabled(true);

		emit setUpModeLeftClick(ModeClick::Nothing);
	}
}

void OMP::on_bTriangle_clicked()
{
	if (bEllipse->isEnabled() && bRect->isEnabled())
	{
		bEllipse->setEnabled(false);
		bRect->setEnabled(false);
		gbModItem->setEnabled(false);
		emit setUpModeLeftClick(ModeClick::AddTriangle);
	}
	else
	{
		bEllipse->setEnabled(true);
		bRect->setEnabled(true);
		gbModItem->setEnabled(true);

		emit setUpModeLeftClick(ModeClick::Nothing);
	}
}

void OMP::on_bConnect_clicked()
{
	if (bDel->isEnabled() && bDrag->isEnabled())
	{
		bDel->setEnabled(false);
		bDrag->setEnabled(false);
		gbAddItem->setEnabled(false);
		emit setUpModeLeftClick(ModeClick::Connect);
	}
	else
	{
		bDel->setEnabled(true);
		bDrag->setEnabled(true);
		gbAddItem->setEnabled(true);

		emit setUpModeLeftClick(ModeClick::Nothing);
	}
}

void OMP::on_bDrag_clicked()
{
	if (bDel->isEnabled() && bConnect->isEnabled())
	{
		bDel->setEnabled(false);
		bConnect->setEnabled(false);
		gbAddItem->setEnabled(false);
		emit setUpModeLeftClick(ModeClick::Move);
	}
	else
	{
		bDel->setEnabled(true);
		bConnect->setEnabled(true);
		gbAddItem->setEnabled(true);

		emit setUpModeLeftClick(ModeClick::Nothing);
	}
}

void OMP::on_bDel_clicked()
{
	if (bConnect->isEnabled() && bDrag->isEnabled())
	{
		bConnect->setEnabled(false);
		bDrag->setEnabled(false);
		gbAddItem->setEnabled(false);
		emit setUpModeLeftClick(ModeClick::Del);
	}
	else
	{
		bConnect->setEnabled(true);
		bDrag->setEnabled(true);
		gbAddItem->setEnabled(true);

		emit setUpModeLeftClick(ModeClick::Nothing);
	}
}
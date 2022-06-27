#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OMP.h"

class OMP : public QMainWindow, public Ui::OMPClass
{
	Q_OBJECT

public:
	OMP(QWidget* parent = nullptr);
	~OMP();

signals:
	void setUpModeLeftClick(ModeClick);

private slots:
	void on_bRect_clicked();

	void on_bEllipse_clicked();

	void on_bTriangle_clicked();

	void on_bConnect_clicked();

	void on_bDrag_clicked();

	void on_bDel_clicked();

private:
	QGraphicsScene scene{};
};

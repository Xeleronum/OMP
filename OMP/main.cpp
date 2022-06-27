#include "OMP.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	OMP w;
	w.show();
	return a.exec();
}
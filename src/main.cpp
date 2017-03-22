#include "controller.h"
#include "view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	Controller controller;
	View view(controller);
	view.showMaximized();

	return application.exec();
}

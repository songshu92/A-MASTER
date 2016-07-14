#include <QApplication>
#include "MainDialog.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainDialog* mainDialog = new MainDialog;
	mainDialog->show();
	return app.exec();
}
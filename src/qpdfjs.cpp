
#include "src/qpdfjswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QPdfJsWindow w;
	w.resize(1000,1000);
	w.show();

	return a.exec();
}

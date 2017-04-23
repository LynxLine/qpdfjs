
#include "src/qpdfjswindow.h"
#include <QApplication>
#include <QFileInfo>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QString app_path = qApp->applicationDirPath();
#ifdef Q_OS_MACOS
	QDir app_path_dir(app_path);
	app_path_dir.cdUp();
	app_path_dir.cdUp();
	app_path_dir.cdUp();
	app_path = app_path_dir.absolutePath();
#endif

	QVector<QWidget *> windows;

	bool no_one = true;
	for(auto pdf_path : a.arguments()) {
		QFileInfo pdf_fi(pdf_path);
		if (!pdf_fi.exists()) continue;
		if (!pdf_path.endsWith(".pdf", Qt::CaseInsensitive)) continue;

		no_one = false;
		QPdfJsWindow * w = new QPdfJsWindow(pdf_path);
		w->resize(1000,1000);
		w->show();
		windows.push_back(w);
	}

	if (no_one) {
		QString pdf_path = app_path+"/empty.pdf";
		QPdfJsWindow * w = new QPdfJsWindow(pdf_path);
		w->resize(1000,1000);
		w->show();
		windows.push_back(w);
	}

	int code = a.exec();

	for (auto w : windows) {
		delete w;
	}

	return code;
}

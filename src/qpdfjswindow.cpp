
#include <QTimer>
#include <QApplication>
#include <QWebEngineView>
#include <QFile>
#include <QDir>

#include "src/qpdfjswindow.h"

class QPdfJsWindow::Private {
public:
	int progress;
	QWebEngineView * view;
};

QPdfJsWindow::QPdfJsWindow(QWidget *parent) :
	QMainWindow(parent)
	,d(new Private)
{
	QString app_path = qApp->applicationDirPath();
#ifdef Q_OS_MACOS
	QDir app_path_dir(app_path);
	app_path_dir.cdUp();
	app_path_dir.cdUp();
	app_path_dir.cdUp();
	app_path = app_path_dir.absolutePath();
#endif
	auto url = QUrl::fromLocalFile(app_path+"/minified/web/viewer.html");

	d->progress = 0;
	d->view = new QWebEngineView(this);

	d->view->load(url);
	setCentralWidget(d->view);

	connect(d->view, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
	connect(d->view, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));
}

QPdfJsWindow::~QPdfJsWindow() {
	delete d;
}

void QPdfJsWindow::setProgress(int p) {
	d->progress = p;
	qDebug() << "progress" << p;
}

void QPdfJsWindow::finishLoading(bool) {
	d->progress = 100;
	qDebug() << "finishLoading";
}

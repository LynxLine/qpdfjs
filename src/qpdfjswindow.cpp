
#include <QTimer>
#include <QApplication>
#include <QWebEngineView>
#include <QWebChannel>
#include <QFile>
#include <QDir>

#include "src/qpdfjswindow.h"
#include "src/communicator.h"

class QPdfJsWindow::Private {
public:
	int progress;
	QWebEngineView * view;
	Communicator m_comm;
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

	QDir dir(app_path+"/minified/web/");
	QString pdf_path = app_path+"/1.pdf";
	pdf_path = dir.relativeFilePath(pdf_path);
	qDebug() << pdf_path;

	d->m_comm.setData(pdf_path);

	d->progress = 0;
	d->view = new QWebEngineView(this);

	QWebChannel * channel = new QWebChannel(this);
	channel->registerObject(QStringLiteral("communicator"), &d->m_comm);
	d->view->page()->setWebChannel(channel);

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

#ifndef QPdfJsWindow_H
#define QPdfJsWindow_H

#include <QMainWindow>

class QWebEngineView;
class Communicator;

class QPdfJsWindow : public QMainWindow {
	Q_OBJECT
	QWebEngineView * m_webView;
	Communicator * m_communicator;
public:
	explicit QPdfJsWindow(QString pdf_file
						  ,QWidget *parent = 0);
	~QPdfJsWindow();
};

#endif

#ifndef QPdfJsWindow_H
#define QPdfJsWindow_H

#include <QMainWindow>

class QPdfJsWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit QPdfJsWindow(QWidget *parent = 0);
	~QPdfJsWindow();

public slots:
	void setProgress(int p);
	void finishLoading(bool);

private:
	class Private;
	Private * d;

};

#endif

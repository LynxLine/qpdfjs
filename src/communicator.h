#ifndef Communicator_H
#define Communicator_H

#include <QObject>

class Communicator : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
	QString m_url;
public:
	explicit Communicator(QObject * p = nullptr) : QObject(p) {}

	QString url() const { return m_url; }
	void setUrl(const QString &url);

signals:
	void urlChanged(const QString &);
};

#endif

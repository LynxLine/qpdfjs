#ifndef Communicator_H
#define Communicator_H

#include <QObject>

class Communicator : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)
	QString m_data;
public:
	explicit Communicator(QObject *parent = nullptr) : QObject(parent) {}

	QString data() const { return m_data; }
	void setData(const QString &data);

signals:
	void dataChanged(const QString &);
};

#endif

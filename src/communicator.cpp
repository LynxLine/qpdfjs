
#include <QFile>
#include <QSize>
#include <QImage>
#include <QApplication>
#include <QDebug>

#include "communicator.h"

#include <iostream>
using namespace std;

void Communicator::setData(const QString & data) {
	if (data == m_data) return;
	m_data = data;

	emit dataChanged(m_data);
	qApp->quit();
}

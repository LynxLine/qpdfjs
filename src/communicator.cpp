
#include <QApplication>
#include "communicator.h"

void Communicator::setUrl(const QString & data) {
	if (data == m_url) return;
	m_url = data;
	emit urlChanged(m_url);
}

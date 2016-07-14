#include "MainDialog.h"

MainDialog::MainDialog(QWidget * parent, Qt::WindowFlags f)
	: QDialog(parent,f)
{
	m_ui.setupUi(this);
	m_ui.beginTimeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
	m_ui.endTimeLabel->setText(QTime::currentTime().addSecs(99).toString("hh:mm:ss"));
	m_ui.horizontalSlider->setBeginTimeLabel(QTime::currentTime());
	m_ui.horizontalSlider->setEndTimeLabel(QTime::currentTime().addSecs(99));
	m_ui.horizontalSlider->setMinimum(0);
	m_ui.horizontalSlider->setMaximum(99);
}
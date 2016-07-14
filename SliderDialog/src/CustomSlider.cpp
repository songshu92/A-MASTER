#include "CustomSlider.h"

CustomSlider::CustomSlider(QWidget * parent)
	: QSlider(parent)
	, m_parentWidget(parent)
	, m_uiSliderDisplay(NULL)
{

}

CustomSlider::~CustomSlider()
{

}

void CustomSlider::setBeginTimeLabel(QTime beginTime)
{
	m_beginTime = beginTime;
}

void CustomSlider::setEndTimeLabel(QTime endTime)
{
	m_endTime = endTime;
}

void CustomSlider::updateInterval()
{
	m_interval = m_beginTime.secsTo(m_endTime)/(maximum()-minimum());
}

void CustomSlider::mousePressEvent(QMouseEvent *ev)
{
	if (!m_uiSliderDisplay)
	{
		updateInterval();
		m_uiSliderDisplay = new UiSliderDisplay(this);
		m_uiSliderDisplay->setSliderDisplayLabel(m_beginTime.addSecs(sliderPosition()*m_interval).toString("hh:mm:ss"));
		m_uiSliderDisplay->move(m_parentWidget->mapToGlobal(pos()).x()+sliderPosition()*(frameGeometry().width()-11)/(maximum()-minimum())-41,m_parentWidget->mapToGlobal(pos()).y()-25);
		m_uiSliderDisplay->setVisible(true);
	}
	return QSlider::mousePressEvent(ev);
}

void CustomSlider::mouseReleaseEvent(QMouseEvent *ev)
{
	if (m_uiSliderDisplay)
	{
		delete m_uiSliderDisplay;
		m_uiSliderDisplay = NULL;
	}
	return QSlider::mouseReleaseEvent(ev);
}

void CustomSlider::mouseMoveEvent(QMouseEvent *ev)
{
	if (m_uiSliderDisplay)
	{
		m_uiSliderDisplay->setSliderDisplayLabel(m_beginTime.addSecs(sliderPosition()*m_interval).toString("hh:mm:ss"));
		m_uiSliderDisplay->move(m_parentWidget->mapToGlobal(pos()).x()+sliderPosition()*(frameGeometry().width()-11)/(maximum()-minimum())-41,m_parentWidget->mapToGlobal(pos()).y()-25);
		m_uiSliderDisplay->setVisible(true);
	}
	return QSlider::mouseMoveEvent(ev);
}
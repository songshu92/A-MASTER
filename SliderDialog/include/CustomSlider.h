#pragma once
#include <QSlider>
#include <QWidget>
#include <QTime>
#include "UiSliderDisplay.h"

class CustomSlider : public QSlider
{
public:
	CustomSlider(QWidget * parent = 0);
	~CustomSlider();
	void setBeginTimeLabel(QTime beginTime);
	void setEndTimeLabel(QTime endTime);
protected:
	virtual void mousePressEvent(QMouseEvent *ev);
	virtual void mouseReleaseEvent(QMouseEvent *ev);
	virtual void mouseMoveEvent(QMouseEvent *ev);
private:
	void updateInterval();
private:
	QWidget*			m_parentWidget;
	UiSliderDisplay*	m_uiSliderDisplay;
	QTime				m_beginTime;
	QTime				m_endTime;
	int					m_interval;
};
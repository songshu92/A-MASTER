#pragma once
#include "ui_SliderDisplay.h"
#include <QDialog>

class UiSliderDisplay : public QDialog
{
public:
	UiSliderDisplay(QWidget * parent = 0, Qt::WindowFlags f = 0);
	~UiSliderDisplay();
	void setSliderDisplayLabel(QString text);
private:
	Ui::SliderDisplay	m_ui;
};

#include "UiSliderDisplay.h"

UiSliderDisplay::UiSliderDisplay(QWidget * parent, Qt::WindowFlags f)
	: QDialog(parent,f)
{
	m_ui.setupUi(this);
	setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
}

UiSliderDisplay::~UiSliderDisplay()
{

}

void UiSliderDisplay::setSliderDisplayLabel(QString text)
{
	m_ui.label->setText(text);
}


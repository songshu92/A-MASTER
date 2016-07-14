#include "ui_MainDialog.h"
#include <QDialog>
#include <QWidget>

class MainDialog : public QDialog
{
	Q_OBJECT
public:
	MainDialog(QWidget * parent = 0, Qt::WindowFlags f = 0);
protected:
	Ui::MainDialog	m_ui;
};
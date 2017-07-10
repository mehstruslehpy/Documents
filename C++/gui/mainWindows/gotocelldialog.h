#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

#include "ui_gotocelldialog.h"

//our GoToCellDialog class inherits from QDialog and from the prev GoToCellDialog
class GoToCellDialog : public QDialog, public Ui::GoToCellDialog
{
	//qt boilerplate that emits a ton of code for qt's moc
	Q_OBJECT

public:
	//constructor for the new class
	GoToCellDialog(QWidget *parent = 0);

//slots is just more boilerplate for qt
private slots: 
	//a private method to execute when the line widget changes
	void on_lineEdit_textChanged();
};

#endif

#include <QtGui>

#include "gotocelldialog.h"

//implementation of the constructor gor GoToCellDialog
GoToCellDialog::GoToCellDialog(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	//setup a validator for he lineEdit widget using a regular expression
	QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
	lineEdit->setValidator(new QRegExpValidator(regExp, this));

	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged()
{
	okButton->setEnabled(lineEdit->hasAcceptableInput());
}

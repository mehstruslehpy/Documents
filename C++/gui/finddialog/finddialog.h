#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    //constructor with default param as null pointer
    FindDialog(QWidget *parent = nullptr);

//signals is a macro defn by qt
signals:
    void findNext(const QString & str, Qt::CaseSensitivity cs);
    void findPrevious(const QString & str, Qt::CaseSensitivity cs);

//slots is also a macro
private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};
#endif


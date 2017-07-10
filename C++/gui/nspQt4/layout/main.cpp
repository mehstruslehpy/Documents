//layout/main.cpp

#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window; //the parent to all the other widgets/elements

    QVBoxLayout* mainLayout = new QVBoxLayout(&window); //QVBoxLayout::QVBoxLayout(QWidget *parent)
    QLabel* label1 = new QLabel("One");
    QLabel* label2 = new QLabel("Two");

    mainLayout->addWidget(label1);
    mainLayout->addWidget(label2);

    window.show();

    return a.exec();



}

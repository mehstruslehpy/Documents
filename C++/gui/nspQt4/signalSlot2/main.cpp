//signalSlot2/main.cpp

#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>

#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;

    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    QLabel *label = new QLabel("0");
    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    QPushButton *button = new QPushButton("Quit");

    mainLayout->addWidget(label);
    mainLayout->addWidget(spinBox);
    mainLayout->addWidget(slider);
    mainLayout->addWidget(button);

    QObject::connect(spinBox, SIGNAL( valueChanged(int) ), label,   SLOT( setNum(int)   ) );
    QObject::connect(spinBox, SIGNAL( valueChanged(int) ), slider,  SLOT( setValue(int) ) );
    QObject::connect(slider, SIGNAL( valueChanged(int) ), label,   SLOT( setNum(int)   ) );
    QObject::connect(slider, SIGNAL( valueChanged(int) ), spinBox, SLOT( setValue(int) ) );
    QObject::connect(button,SIGNAL( clicked()), &a, SLOT(quit()));

    window.show();

    return a.exec();

}

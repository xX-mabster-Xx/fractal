#include "fractal.h"

#include <QApplication>
#include <QMainWindow>
#include <QSpinBox>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
//    const int X = 1280;
//    const int Y = 720;
    QApplication a(argc, argv);

    QWidget *ww = new QWidget();
    ww->setMinimumWidth(200);
    ww->setMinimumHeight(200);
    QVBoxLayout *mainLayout = new QVBoxLayout();
    fractal * widget = new fractal(ww);
    QSpinBox * spinbox = new QSpinBox(ww);
    spinbox->setGeometry(10, 10, 100, 30);
    spinbox->setValue(5);
    spinbox->setRange(0, 20);
    mainLayout->addWidget(widget, 1);
    //mainLayout->addWidget(spinbox, 0);
    ww->setLayout(mainLayout);
    ww->show();
    QObject::connect(spinbox, SIGNAL(valueChanged(int)),
                     widget, SLOT(setValue(int)));
    return a.exec();
}

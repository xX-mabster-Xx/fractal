#ifndef FRACTAL_H
#define FRACTAL_H

#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <iostream>
#include <cmath>

class fractal : public QWidget
{
    int N = 5;
    Q_OBJECT
public:
    fractal(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event);
private:
    void paint(int k, double x0, double y0, double x1, double y1, QPainter & painter);
public slots:
    void setValue(int);
};

#endif // FRACTAL_H

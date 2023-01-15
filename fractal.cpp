#include "fractal.h"

fractal::fractal(QWidget *parent) : QWidget(parent)
{
}

void fractal::paint(int k, double x0, double y0, double x1, double y1, QPainter & painter) {

    //std::cout << k << ": " << x0 << " " << y0 << " - " << x1 << " " << y1 << std::endl;
    if (k == 0) {
        painter.drawLine(QPointF(x0, height() - y0), QPointF(x1, height() - y1));
        //std::cout << x0 << " " << y0 << " - " << x1 << " " << y1 << std::endl;
    }
    else {
        double x2 = x0 + (x1 - x0) / 3;
        double y2 = y0 + (y1 - y0) / 3;
        double x3 = x0 + 2 * (x1 - x0) / 3;
        double y3 = y0 + 2 * (y1 - y0) / 3;

        double xmid = x2 + (x3 - x2) / 2 - (y3 - y2) * sqrt(3) / 2;
        double ymid = y2 + (x3 - x2) * sqrt(3) / 2 + (y3 - y2) / 2;
        paint(k - 1, x0, y0, x2, y2, painter);
        paint(k - 1, x2, y2, xmid, ymid, painter);
        paint(k - 1, xmid, ymid, x3, y3, painter);
        paint(k - 1, x3, y3, x1, y1, painter);
    }
}

void fractal::paintEvent(QPaintEvent * event) {
    Q_UNUSED(event);
    QPainter p(this);
    if (N == 0)
        paint(N, 0, height() / 2, width() - 1, height() / 2, p);
    else if (N > 0)
        paint(N, 0, height() / 2 - (width() * sqrt(3) / 12), width() - 1, height() / 2 - (width() * sqrt(3) / 12), p);
}

void fractal::setValue(int val)
{
    N = val;
    repaint();
}

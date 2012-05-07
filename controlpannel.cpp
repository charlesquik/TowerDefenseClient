#include "controlpannel.h"
#include <QtGui>

ControlPannel::ControlPannel(QRect ecran,QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(100,ecran.height());
    setAutoFillBackground(false);
    ecranpannel=ecran;
}
void ControlPannel::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval());
    repaint();
}
void ControlPannel::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black,2));
    painter.drawRect(ecranpannel.width()-100,0,100,ecranpannel.height());
    painter.end();

}

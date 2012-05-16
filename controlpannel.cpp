#include "controlpannel.h"
#include <QtGui>

ControlPannel::ControlPannel(QRect ecran,QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(ecran.width()/2,ecran.height()-ecran.height()*0.95);

    this->setGeometry(0,ecran.height()*0.95,ecran.width()/2,ecran.height()*0.95);
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
    painter.fillRect(this->rect(),Qt::white);
    painter.drawRect(this->rect());
    painter.setPen(QPen(Qt::black,2));
    painter.drawText(this->rect().x()+5,this->rect().y()+15,QString::number(elapsed),sizeof(elapsed));
    painter.drawText(this->rect().x()+5,this->rect().y()+25,"allo",sizeof("allo"));
    painter.end();

}

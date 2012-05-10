#include "towerdefence.h"
#include "ui_towerdefence.h"
#include <QPainter>
#include "mapgrid.h"
#include <QPaintEvent>
#include <QApplication>
#include <QDesktopWidget>
#include "mapgrid.h"
#include <iostream>
#include "gestionnaire.h"
#include "controlpannel.h"
#include <QRgb>
#include <QImage>

TowerDefence::TowerDefence(QString carte, int vie, int credit):QMainWindow(),
    ui(new Ui::TowerDefence)
{
    ui->setupUi(this);
    QRect ecran=QApplication::desktop()->rect();
    this->setFixedSize(ecran.width(),ecran.height());      
    QImage map=construiremap(carte,ecran);
    gest=new gestionnaire(map);
    mavue=new MapGrid(ecran,gest,this);
    moncontrole=new ControlPannel(ecran,this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),moncontrole,SLOT(animate()));
    connect(timer, SIGNAL(timeout()), mavue, SLOT(animate()));
    //connect(mavue, SIGNAL(updatelabel()), this, SLOT(SetLabel()));
    timer->start(30);
}

TowerDefence::~TowerDefence()
{
    delete ui;
}
//void TowerDefence::paintEvent(QPaintEvent *paint)
//{
 //   QPainter painter(this);
 //   painter.setRenderHint(QPainter::Antialiasing);
//}
void TowerDefence::abandonner()
{

}
QImage TowerDefence::construiremap(QString map,QRect ecran)
{


    QFile f(map);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QImage *p;
    QImage *ima;
    QByteArray a;
    ima=new QImage(ecran.width(),ecran.height(),QImage::Format_ARGB32_Premultiplied);
    int mapx=(int)(ecran.width()/24);
    int mapy=(int)(ecran.height()/24);
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {

                a=f.read(1);
                a.replace("\n","");
                    switch(a.toInt())
                    {
                    case 0:
                        p=new QImage("image/herbe.jpg");
                        break;
                    case 2:
                        p=new QImage("image/Est.jpg");
                        break;
                    case 4:
                        p=new QImage("image/Nord_Ouest.jpg");
                        break;
                    case 6:
                        p=new QImage("image/Sud_Est.jpg");
                        break;
                    case 8:
                        p=new QImage("image/Nord_Est.jpg");
                        break;
                   case 10:
                        p=new QImage("image/Sud_Ouest.jpg");
                        break;
    //                case 12:
    //                    p=new QImage("image/herbe.jpg");
    //                    break;
    //                case 14:
    //                    p=new QImage("image/herbe.jpg");
    //                    break;

                    }
                    p=new QImage(p->scaled(mapx,mapy));
                    for(int f=1;f<mapx;f++)
                    {
                        for(int k=1;k<mapy;k++)
                        {
                           QRgb r=p->pixel(f,k);
                           ima->setPixel(j*mapx+f,i*mapy+k,r);
                        }
                    }
        }
    }
    f.close();
    return *ima;
}

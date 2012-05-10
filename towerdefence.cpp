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
    mavue=new MapGrid(ecran,gridc,gest,this);
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
    int z=0;

    QByteArray a;
    ima=new QImage(ecran.width(),ecran.height(),QImage::Format_ARGB32_Premultiplied);
    int mapx=(int)(ecran.width()/24);
    int mapy=(int)(ecran.height()/24);
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {

                a=f.read(1);
                if(a=="\n")
                {
                    a=f.read(1);
                }
                    switch(a[0])
                    {
                    case 'h':
                        p=new QImage("image/herbe.jpg");
                        break;
                    case 'n':
                        p=new QImage("image/Nord.jpg");
                        break;
                    case 's':
                        p=new QImage("image/Sud.jpg");
                        break;
                    case 'e':
                        p=new QImage("image/Est.jpg");
                        break;
                    case 'o':
                        p=new QImage("image/Ouest.jpg");
                        break;
                    case 'w':
                        p=new QImage("image/Nord_Ouest.jpg");
                        break;
                   case  'x':
                        p=new QImage("image/Sud_E.jpg");
                        break;
                    case 'y':
                        p=new QImage("image/Sud_Ouest.jpg");
                        break;
                    case 'z':
                        p=new QImage("image/Nord_Est.jpg");
                        break;
                    case '1':
                        p=new QImage("image/Mabase.jpg");
                        break;
                    case '2':
                        p=new QImage("image/Cabase.jpg");
                        break;

                    }
                    p=new QImage(p->scaled(mapx,mapy));
                    if(a[0]=='n' || a[0]=='s' ||a[0]=='e' ||a[0]=='o' ||a[0]=='w' ||a[0]=='x' ||a[0]=='y' ||a[0]=='z' )
                    gridc[z][1]=i;
                    gridc[z][2]=j;
                    gridc[z][3]=a[0];
                    z++;
                    for(int f=0;f<mapx;f++)
                    {
                        for(int k=0;k<mapy;k++)
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

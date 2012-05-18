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
#include <QList>
#include <QVector2D>


TowerDefence::TowerDefence(QString carte, int vie, int credit,int joueur,int socketdescriptor):QMainWindow(),
    ui(new Ui::TowerDefence)
{
    this->joueur=joueur;
    this->vie=vie;
    this->money=credit;
    ui->setupUi(this);
    if(joueur==1)
        Adversaire=new Joueur1(2);
    else
        Adversaire=new Joueur1(1);
    m_socket=new QTcpSocket();
    m_socket->setSocketDescriptor(socketdescriptor);
    ecran=QApplication::desktop()->rect();
    this->setFixedSize(ecran.width(),ecran.height());
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(Lecture()));
   // QImage map=construiremap(carte,ecran);
    //gest=new gestionnaire(map,&chemin,this->vie,this->money);
    //mavue=new MapGrid(ecran,&chemin,gest,Adversaire,this);
    //moncontrole=new ControlPannel(ecran,this->vie,this->money,joueur,this);
    //timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),moncontrole,SLOT(animate()));
    //connect(timer, SIGNAL(timeout()), mavue, SLOT(animate()));
   // connect(mavue, SIGNAL(updatelabelmoney(int)), this, SLOT(SetLabelmoney(int)));
    connect(gest, SIGNAL(updatelabelvie(int)), this, SLOT(SetLabelvie(int)));
    connect(gest, SIGNAL(updatelabelmoney(int)), this, SLOT(SetLabelmoney(int)));
    connect(this,SIGNAL(AjoutTourEnemie(int,int,int,QRect)),gest,SLOT(ajouttouren(int,int,int,QRect)));
   // timer->start(30);
}

TowerDefence::~TowerDefence()
{
    delete ui;
}
void TowerDefence::SetLabelmoney(int money)
{
    this->money=money;
    this->moncontrole->money=this->money;
}
void TowerDefence::SetLabelvie(int vie)
{
    this->vie=vie;
    this->moncontrole->vie=this->vie;
//    if(this->vie<=0)
//    {
//        GameOver();
//    }
}
void TowerDefence::Lecture()
{

   QByteArray recept=m_socket->read(m_socket->bytesAvailable());
   if(recept.at(0)=='#')
   {
        gest->ListeMonstre.clear();
        gest->EListeMonstre.clear();
        recept=recept.remove(0,1);
        QStringList Reception = QString(recept).split('#');
        QStringList coordmes=Reception.at(0).split('/');
        QStringList coordces=Reception.at(1).split('/');
        foreach(QString donne,coordmes)
        {
           QStringList coord=donne.split('.');
           int x,y;
           x=atoi(coord.at(0));
           y=atoi(coord.at(1));
           Monstre *monstre;
           QVector2D me(x,y);
           monstre=new Monstre(me,(float)0.10,(float)20,1,(float)20,QColor(Qt::green),&chemin);
           gest->ListeMonstre.append(monstre);
        }
        foreach(QString donne,coordces)
        {
           QStringList coord=donne.split('.');
           int x,y;
           x=atoi(coord.at(0));
           y=atoi(coord.at(1));
           Monstre *monstre;
           QVector2D me(x,y);
           monstre=new Monstre(me,(float)0.10,(float)20,1,(float)20,QColor(Qt::green),&chemin);
           gest->EListeMonstre.append(monstre);
        }


       moncontrole->animate();
       mavue->animate();
   }
   else if(recept.at(0)=='@')
   {
       recept=recept.remove(0,1);
       QStringList Reception = QString(recept).split('#');
       QImage map(Reception.at(0).toAscii());
       Reception.removeAt(0);
       foreach(QString donne,Reception)
       {
           QStringList coord=donne.split('.');
           int x,y;
           x=atoi(coord.at(0));
           y=atoi(coord.at(1));
           chemin.append(QPoint(x,y));
       }
       gest=new gestionnaire(map,&chemin,this->vie,this->money);

       mavue=new MapGrid(ecran,&chemin,gest,Adversaire,this);
       moncontrole=new ControlPannel(ecran,this->vie,this->money,joueur,this);
   }
   else if(recept.at(0)=='%')
   {
       recept=recept.remove(0,1);
       QStringList Reception = QString(recept).split('#');
       emit AjoutTourEnemie(Reception.at(0).toInt(),Reception.at(1).toInt(),Reception.at(2).toInt(),ecran);
   }
}
void TowerDefence::GameOver()
{
    timer->stop();
    QMessageBox::critical(0,"Game over", "You lose");
    //this->close();
}
//QImage TowerDefence::construiremap(QString map,QRect ecran)
//{


//    QFile f(map);
//    f.open(QIODevice::ReadOnly | QIODevice::Text);
//    QImage *p;
//    QImage *ima;
//    int z=0;

//    QByteArray a;
//    ima=new QImage(ecran.width(),ecran.height(),QImage::Format_ARGB32_Premultiplied);
//    int mapx=(int)(ecran.width()/24);
//    int mapy=(int)(ecran.height()/24);
//    for(int i=0;i<24;i++)
//    {
//        for(int j=0;j<24;j++)
//        {

//                a=f.read(1);
//                if(a=="\n")
//                {
//                    a=f.read(1);
//                }
//                    switch(a[0])
//                    {
//                    case 'h':
//                        p=new QImage("image/herbe.jpg");
//                        break;
//                    case 'n':
//                        p=new QImage("image/Nord.jpg");
//                        break;
//                    case 's':
//                        p=new QImage("image/Sud.jpg");
//                        break;
//                    case 'e':
//                        p=new QImage("image/Est.jpg");
//                        break;
//                    case 'o':
//                        p=new QImage("image/Ouest.jpg");
//                        break;
//                    case 'w':
//                        p=new QImage("image/Nord_Ouest.jpg");
//                        break;
//                   case  'x':
//                        p=new QImage("image/Sud_E.jpg");
//                        break;
//                    case 'y':
//                        p=new QImage("image/Sud_Ouest.jpg");
//                        break;
//                    case 'z':
//                        p=new QImage("image/Nord_Est.jpg");
//                        break;
//                    case '1':
//                        p=new QImage("image/Mabase.jpg");
//                        break;
//                    case '2':
//                        p=new QImage("image/Cabase.jpg");
//                        break;
//                    default:
//                        p=new QImage("image/herbe.jpg");
//                        break;


//                    }
//                    p=new QImage(p->scaled(mapx,mapy));
//                    if(a[0]=='n' || a[0]=='s' ||a[0]=='e' ||a[0]=='o' ||a[0]=='w' ||a[0]=='x' ||a[0]=='y' ||a[0]=='z'||a[0]=='1'||a[0]=='2' )
//                    {

//                    int index = 0;
//                    if (chemin.count() - 1 >= index)
//                    {
//                            while (j>=chemin.at(index).x())
//                            {
//                                index++;
//                            }
//                    }

//                    QPoint im(j,i);
//                    if (a[0] == 'y' || a[0] == 'n')
//                    {
//                        index--;
//                        if (test.count() -1>=index && index-1>=0)
//                        {
//                            while (test.at(index-1) == "y" || test.at(index-1) == "n")
//                            {
//                                index --;
//                            }
//                        }
//                    }

//                    test.insert(index,a.left(1));
//                    chemin.insert(index,im);

//                    //chemin.at(z)[2]=a[0];
//                  //  z++;

//                    }
//                    for(int f=0;f<mapx;f++)
//                    {
//                        for(int k=0;k<mapy;k++)
//                        {
//                           QRgb r=p->pixel(f,k);
//                           ima->setPixel(j*mapx+f,i*mapy+k,r);
//                        }
//                    }
//        }
//    }
//    f.close();
//    return *ima;
//}

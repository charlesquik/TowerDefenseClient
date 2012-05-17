#include "gestionnaire.h"
#include <QtGui>
#include <QTransform>
#include <QPixmap>
#include <QRgb>
#include "mapgrid.h"

gestionnaire::gestionnaire(QImage map,QList<QPoint> *chemin,int vie,int money)
{
   // MapX=(ecran.width()-100)/12;
   // MapY=(ecran.height()/12;
    //QColor a(50,50,50);
     //m_chemin=chemin;
 //     map.setPixel(100,100,a.rgb());
  //  QPixmap b(map);
    //background = QBrush(b);
      background = QBrush(map);
      this->money=money;
      this->vie=vie;
  ////  t=new Tower(2,2,10,10,10,10,10,10,Qt::blue,Qt::blue,100);
  //  ListeTower[0]=t;

}
void gestionnaire::paint(QPainter *painter, QPaintEvent *event,long elapsed)
{
     painter->fillRect(event->rect(),background);
     painter->save();
    for(int i=0;i<ListeMonstre.size();i++)
    {
        ListeMonstre.at(i)->avancer(elapsed);
        ListeMonstre.at(i)->paint(painter);

    }
    for(int i=0;i<ListeProjectile.size();i++)
    {
        ListeProjectile.at(i)->avancer(elapsed);
        ListeProjectile.at(i)->paint(painter);
    }
    for(int i=0;i<ListeTower.size();i++)
    {
        int j=0;
        ListeTower.at(i)->paint(painter);
        while(ListeTower.at(i)->havetarget==false && j<ListeMonstre.size())
        {
            if((ListeTower.at(i)->m_center - ListeMonstre.at(j)->monstre).length()<ListeTower.at(i)->m_portee)
            {
                Projectile *p=ListeTower.at(i)->Shoot(ListeMonstre.at(j),elapsed);
                ListeTower.at(i)->havetarget=true;
                ListeTower.at(i)->suivre(ListeMonstre.at(j)->monstre);
                if(p!=NULL)
                {
                    ListeProjectile.append(p);
                }
            }
            j++;

        }
    }
    for(int i=0;i<ListeTower.size();i++)
    {
        ListeTower.at(i)->havetarget=false;
    }
    for(int i=0;i<ListeProjectile.size();i++)
    {
        Projectile* b = ListeProjectile.at(i);
        if(ListeProjectile.at(i)->cibletoucher==true)
        {
            if(ListeMonstre.contains(b->monstre))
            {
                b->monstre->hit(b->degat);
            }
            delete ListeProjectile.at(i);
            ListeProjectile.removeAt(i);

       }
    }
    for(int i=0;i<ListeMonstre.size();i++)
    {
        if(ListeMonstre.at(i)->vie<0)
        {
            money+=10;
            emit updatelabelmoney(money);
            delete ListeMonstre.at(i);
            ListeMonstre.removeAt(i);
        }
        else if(ListeMonstre.at(i)->isDelete==true)
        {
            vie-=1;
            ListeMonstre.at(i)->Delete();
            ListeMonstre.removeAt(i);
            if(vie>0)
            {
            emit updatelabelvie(vie);
            }
            else
            {
            emit finpartie();
            return;
            }

        }
    }

    painter->restore();
}
void gestionnaire::ajouttour(int type, int x, int y, QRect ecran)
{
    Tower *t;
    int mapx=(int)(ecran.width()/24);
    int mapy=(int)(ecran.height()/24);
    switch(type)
    {
        case 1:

            t=new Tower(x*mapx+mapx/4,y*mapy+mapy/4,1000,250,50,10,1,10,Qt::black,Qt::blue,mapx/2);
            if(money>=t->m_prixbase)
            {
                money-=t->m_prixbase;
                emit updatelabelmoney(money);
                ListeTower.append(t);
            }
            break;

        case 2:
            t=new Tower(x*mapx+mapx/4,y*mapy+mapy/4,500,500,60,4,2,5,Qt::black,Qt::red,mapx/2);
            if(money>=t->m_prixbase)
            {
                money-=t->m_prixbase;
                emit updatelabelmoney(money);
                ListeTower.append(t);
            }
            break;
//        case 3:
//            t=new Tower(x,y,20,20,50,10,1,10,Qt::black,Qt::blue,ecran.x()/24-5);
//            ListeTower.append(t);
//            break;
//        default:
//            t=new Tower(x,y,20,20,50,10,1,10,Qt::black,Qt::blue,ecran.x()/24-5);
//            ListeTower.append(t);
//            break;
    }
}

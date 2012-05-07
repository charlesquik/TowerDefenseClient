#include "gestionnaire.h"
#include <QtGui>
#include <QTransform>
#include <QPixmap>

gestionnaire::gestionnaire(QPixmap map)
{
  //  MapX=(ecran.width()-100)/12;
   // MapY=(ecran.height()/12;
    background = QBrush(map);
}
void gestionnaire::paint(QPainter *painter, QPaintEvent *event,long elapsed)
{
    painter->fillRect(event->rect(),background);
    painter->save();

    for(int i=0;i<ListeMonstre.size();i++)
    {
        ListeMonstre.at(i)->avancer(elapsed,1);
        ListeMonstre.at(i)->paint(painter);

    }
    for(int i=0;i<ListeProjectile.size();i++)
    {
        ListeProjectile.at(i)->avancer(elapsed);
        ListeProjectile.at(i)->paint(painter);
    }
    for(int i=0;i<ListeTower.size();i++)
    {
        ListeTower.at(i)->paint(painter);
        for(int j=0;j<ListeMonstre.size();j++)
        {
            if((ListeTower.at(i)->center - ListeMonstre.at(j)->monstre).length()<ListeTower.at(i)->portee)
            {
                Projectile *p=ListeTower.at(i)->Shoot(ListeMonstre.at(j),elapsed);
                if(p!=NULL)
                    ListeProjectile.append(p);
                ListeTower.at(i)->suivre(&ListeMonstre.at(j)->monstre);
            }
        }
        if(ListeMonstre.isEmpty()==false)
        {
           ListeTower.at(i)->suivre(&ListeMonstre.first()->monstre);
        }

    }
    for(int i=0;ListeProjectile.size();i++)
    {
        Projectile* b = ListeProjectile.at(i);
        if(ListeProjectile.at(i)->cibletoucher)
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
            delete ListeMonstre.at(i);
            ListeMonstre.removeAt(i);
        }
    }
    painter->restore();
}

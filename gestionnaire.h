#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include "monstre.h"
#include "projectile.h"
#include "tower.h"
#include <QList>
#include <QPixmap>

class gestionnaire
{
public:
    gestionnaire(QImage map,QList<QPoint> *chemin);
    void paint(QPainter *painter, QPaintEvent *event,long elapsed);
        QList<Tower*> ListeTower;
        QList<Monstre*> ListeMonstre;
private:
    int money;
   // int MapX, MapY;
 //   QList<Monstre*> ListeMonstre;
   // QList<Tower*> ListeTower;
    QList<Projectile*> ListeProjectile;
    QBrush background;
    Tower *t;
    char *m_chemin;
//public slots:
  //  void ajouttour(int type,int x,int y,QRect ecran);

};

#endif // GESTIONNAIRE_H

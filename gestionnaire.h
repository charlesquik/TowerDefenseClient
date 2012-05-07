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
    gestionnaire(QPixmap map);
    void paint(QPainter *painter, QPaintEvent *event,long elapsed);
private:
    int money;
   // int MapX, MapY;
    QList<Monstre*> ListeMonstre;
    QList<Tower*> ListeTower;
    QList<Projectile*> ListeProjectile;
    QBrush background;
    Tower *t;

};

#endif // GESTIONNAIRE_H

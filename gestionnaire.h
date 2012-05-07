#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include "monstre.h"
#include "projectile.h"
#include "tower.h"
#include <QList>

class gestionnaire
{
public:
    gestionnaire(QRect ecran,QBrush map);
private:
    int money;
    int MapX, MapY;
    QList<Monstre> ListeMonstre;
    QList<Tower*> ListeTower;
    QList<Projectile*> ListeProjectile;
    QBrush background;
    bool cibleaquise;

};

#endif // GESTIONNAIRE_H

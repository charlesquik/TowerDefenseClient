#ifndef JOUEUR1_H
#define JOUEUR1_H
#include "tower.h"
#include "monstre.h"
#include "projectile.h"
#include <QObject>

class Joueur1 : public QObject
{
    Q_OBJECT
public:
    explicit Joueur1(int numero,QObject *parent = 0);
    int numero;
    QList<Tower*> ListeTower;
    QList<Monstre*> ListeMonstre;
    QList<Projectile*> ListeProjectile;

    
signals:
    
public slots:
    
};

#endif // JOUEUR1_H

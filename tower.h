#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QVector2D>
#include <QColor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <projectile.h>

class Tower
{
public:
    explicit Tower(int x,int y,float cadence,float portee,int prixbase,float damage,int type,float tailleprojectile,QColor canon,QColor base,int lh);

    int x;
    int y;
    float cadence;
    float portee;
    int prixbase;
    float damage;
    int type;
    float   tailleprojectile;
    QColor    canon;
    QColor    base;
    int   lh;
    QVector2D center;
    int rotation;
    long derniertire;
    int level;

  //  QVector2D GetInterSect(  QVector2D source,
    //                         QVector2D destination,
    //                         float vitesseprojectile,
    //                         float vitessemonstre,
     //                        QVector2D projectile_pos,
     //                        QVector2D monstre_pos);

    void suivre(QVector2D *posmonstre)  ;

    int revendre();

    void paint (QPainter * painter);
    Projectile* Shoot(Monstre *monstre, long elapsed);
};

#endif // TOWER_H

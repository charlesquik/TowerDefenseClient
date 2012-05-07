#include "tower.h"
#include <qmath.h>
#include "projectile.h"



Tower::Tower(int x,int y,float cadence,float portee,int prixbase,float damage,int type,float tailleprojectile,QColor canon,QColor base,int lh)
{
    this->x=x;
    this->y=y;
    this->cadence=cadence;
    this->portee=portee;
    this->level=1;
    this->prixbase=prixbase;
    this->damage=damage;
    this->type=type;
    this->canon=canon;
    this->tailleprojectile=tailleprojectile;
    this->canon=canon;
    this->base=base;
    this->lh=lh;
    center.setX((qreal)(x+lh/2));
    center.setY((qreal)(y+lh/2));
}
int Tower::revendre()
{
    return (this->level/10)*prixbase+prixbase;
}
void Tower::suivre(QVector2D *posmonstre)
{

    int angle=acos(QVector2D::dotProduct(*posmonstre,center));
    angle=angle+sqrt(posmonstre->lengthSquared()*center.lengthSquared());
    rotation=angle;
}
void Tower::paint (QPainter * painter)
{
    painter->setPen(QPen(Qt::NoPen));
    painter->setBrush(base);
    painter->drawEllipse(x,y,lh,lh);
    painter->setBrush(canon);
    painter->drawRect(x+lh/2,y+lh/2,lh/10,lh);
    painter->rotate(rotation);
}
Projectile* Tower::Shoot(Monstre *monstre, long elapsed)
{
    if (elapsed - derniertire < cadence) return 0;
    QVector2D tcenter(center.x(), center.y());
    QVector2D target(monstre->monstre.x(),monstre->monstre.y());
    if (target.isNull() || (this->center - target).length() > this->portee)
        return 0;
    derniertire = elapsed;
    Projectile*projectile = new Projectile(tcenter, target,tailleprojectile,10,1,damage*level,base,elapsed);
    projectile->monstre = monstre;
    return projectile;
}

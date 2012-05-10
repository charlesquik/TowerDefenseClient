#include "tower.h"
#include <qmath.h>
#include "projectile.h"



Tower::Tower(int x,int y,float cadence,float portee,int prixbase,float damage,int type,float tailleprojectile,QColor canon,QColor base,int lh)
{
    m_x=x;
    m_y=y;
    m_cadence=cadence;
    m_portee=portee;
    m_level=1;
    m_prixbase=prixbase;
    m_damage=damage;
    m_type=type;
    m_canon=canon;
    m_tailleprojectile=tailleprojectile;
    m_canon=canon;
    m_base=base;
    m_lh=lh;
    m_rotation=0;
    m_center.setX(x+lh/2);
    m_center.setY(y+lh/2);
}
int Tower::revendre()
{
    return (this->m_level/10)*m_prixbase+m_prixbase;
}
void Tower::suivre(QVector2D *posmonstre)
{

    int angle=acos(QVector2D::dotProduct(*posmonstre,m_center));
    angle=angle+sqrt(posmonstre->lengthSquared()*m_center.lengthSquared());
    m_rotation=angle;
}
void Tower::paint(QPainter *painter)
{
   // painter->drawLine(10,10,100,199);
    painter->setPen(QPen(Qt::NoPen));
    painter->setBrush(m_base);
    painter->drawEllipse(m_x,m_y,m_lh,m_lh);
    painter->setBrush(m_canon);
   painter->drawRect(m_x+m_lh/2,m_y+m_lh/2,m_lh/10,m_lh);
    //painter->rotate(rotation);
}
Projectile* Tower::Shoot(Monstre *monstre, long elapsed)
{
    if (elapsed - m_derniertire < m_cadence) return 0;
    QVector2D tcenter(m_center.x(), m_center.y());
    QVector2D target(monstre->monstre.x(),monstre->monstre.y());
    if (target.isNull() || (this->m_center - target).length() > 1000)//this->m_portee)
        return 0;
    m_derniertire = elapsed;
    Projectile*projectile = new Projectile(tcenter, target,m_tailleprojectile,10,1,m_damage*m_level,m_base,elapsed);
    projectile->monstre = monstre;
    return projectile;
}

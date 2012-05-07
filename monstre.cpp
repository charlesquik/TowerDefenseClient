#include "monstre.h"

Monstre::Monstre(QVector2D monstre,float vitesse,float vie,int type,float taille,QColor carapace)
{
    this->monstre=monstre;
    this->vitesse=vitesse;
    this->vie=vie;
    this->type=type;
    this->taille=taille;
    this->carapace=carapace;
}
void Monstre::paint ( QPainter * painter)
{
    painter->setPen(QPen(Qt::NoPen));
    painter->setBrush(carapace);
    painter->drawEllipse(this->monstre.x()-(taille/2), this->monstre.y()-(taille/2), taille, taille);
}
void Monstre::avancer(long elapsed,int etape)
{
    if(etape==1)
    {
        switch(terraintype)
        {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
           // if(lastterraintype=="haut")
          //      rotation=-90;
        //   else
        //        rotation=90;
        break;
        }
    }
}
void Monstre::hit(float damage)
{
    vie-=damage;
}

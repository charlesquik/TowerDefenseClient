#ifndef MONSTRE_H
#define MONSTRE_H

#include <QObject>
#include <QVector2D>
#include <QColor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QColor>

class Monstre
{
public:
    explicit Monstre(QVector2D monstre,float vitesse,float vie,int type,float taille,QColor carapace);
    void paint(QPainter * painter);
    void avancer(long elapsed,int etape);
    QVector2D monstre;
   float vitesse;
    int vie;
     int type;
    float taille;
    QColor carapace;
    void hit(float damage);
private:
    QString terraintype;
        
};

#endif // MONSTRE_H

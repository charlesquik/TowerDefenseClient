#ifndef MONSTRE_H
#define MONSTRE_H

#include <QObject>
#include <QVector2D>
#include <QColor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Monstre
{
public:
    explicit Monstre(QVector2D monstre,float vitesse,float vie,int type,float taille,QColor carapace);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option);
    void avancer(long elapsed,int etape);
        
};

#endif // MONSTRE_H

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include "monstre.h"
#include "projectile.h"
#include "tower.h"
#include <QList>
#include <QPixmap>
#include <QObject>
#include "joueur.h"

class gestionnaire: public QWidget
{
    Q_OBJECT
public:
    gestionnaire(QImage map,QList<QPoint> *chemin,int vie,int money);
    void paint(QPainter *painter, QPaintEvent *event,long elapsed);
        QList<Tower*> ListeTower;
        QList<Monstre*> ListeMonstre;
        QList<Projectile*> ListeProjectile;
        QList<Tower*> EListeTower;
        QList<Monstre*> EListeMonstre;
        QList<Projectile*> EListeProjectile;
        Joueur1* m_Adversaire;
        int money;
        int vie;
private:
   // int MapX, MapY;
 //   QList<Monstre*> ListeMonstre;
   // QList<Tower*> ListeTower;
    QBrush background;
    Tower *t;

    char *m_chemin;
public slots:
    void ajouttour(int,int,int,QRect);
    void ajouttouren(int,int,int,QRect);
signals:
    void updatelabelmoney(int);
    void updatelabelvie(int);
    void finpartie();


};

#endif // GESTIONNAIRE_H

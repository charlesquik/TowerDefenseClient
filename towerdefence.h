#ifndef TOWERDEFENCE_H
#define TOWERDEFENCE_H

#include <QMainWindow>
#include "mapgrid.h"
#include "gestionnaire.h"
#include <QTimer>
#include <QPixmap>
#include "controlpannel.h"
#include "joueur.h"


namespace Ui {
class TowerDefence;
}

class TowerDefence : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TowerDefence(QString carte, int vie, int credit,int joueur);
    ~TowerDefence();
    QImage construiremap(QString map,QRect ecran);
    void GameOver();
    
private:
    int money;
    int vie;
    int joueur;
    Ui::TowerDefence *ui;
    gestionnaire *gest;
    MapGrid *mavue;
    Joueur1 *Adversaire;
    ControlPannel *moncontrole;
    QTimer *timer;
    QList<QPoint> chemin;
    QStringList test;

private slots:
   void SetLabelmoney(int);
   void SetLabelvie(int);
};

#endif // TOWERDEFENCE_H

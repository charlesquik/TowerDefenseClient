#ifndef TOWERDEFENCE_H
#define TOWERDEFENCE_H

#include <QMainWindow>
#include "mapgrid.h"
#include "gestionnaire.h"
#include <QTimer>
#include <QPixmap>
#include "controlpannel.h"
#include "joueur.h"
#include <QtNetwork/QTcpSocket>
#include <QRect>


namespace Ui {
class TowerDefence;
}

class TowerDefence : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TowerDefence(QString carte, int vie, int credit,int joueur, int socketdescriptor);
    ~TowerDefence();
    //QImage construiremap(QString map,QRect ecran);
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
    QTcpSocket* m_socket;
    QList<QPoint> chemin;
    QRect ecran;
    QStringList test;

private slots:
   void SetLabelmoney(int);
   void SetLabelvie(int);
   void Lecture();
signals:
   void AjoutTourEnemie(int,int,int,QRect);
};

#endif // TOWERDEFENCE_H

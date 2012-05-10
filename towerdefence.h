#ifndef TOWERDEFENCE_H
#define TOWERDEFENCE_H

#include <QMainWindow>
#include "mapgrid.h"
#include "gestionnaire.h"
#include <QTimer>
#include <QPixmap>
#include "controlpannel.h"


namespace Ui {
class TowerDefence;
}

class TowerDefence : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TowerDefence(QString carte, int vie, int credit);
    ~TowerDefence();
    void abandonner();
    QImage construiremap(QString map,QRect ecran);
    
private:
    Ui::TowerDefence *ui;
    gestionnaire *gest;
    MapGrid *mavue;
    ControlPannel *moncontrole;
    QTimer *timer;
    char gridc[576][3];

private slots:
   //void paintEvent(QPaintEvent *paint);
};

#endif // TOWERDEFENCE_H

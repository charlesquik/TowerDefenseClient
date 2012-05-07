#ifndef TOWERDEFENCE_H
#define TOWERDEFENCE_H

#include <QMainWindow>
#include "mapgrid.h"
#include "gestionnaire.h"
#include <QTimer>
#include <QBrush>


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
    
private:
    Ui::TowerDefence *ui;
    gestionnaire Gestionnaire;
    MapGrid *mavue;
    QTimer *timer;
    QBrush map;

private slots:
   void paintEvent(QPaintEvent *paint);
};

#endif // TOWERDEFENCE_H

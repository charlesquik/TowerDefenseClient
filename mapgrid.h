#ifndef MAPGRID_H
#define MAPGRID_H

#include <QObject>
#include "gestionnaire.h"
#include "tower.h"
#include <QMouseEvent>


class MapGrid : public QWidget
{
    Q_OBJECT
public:
    explicit MapGrid(QRect ecran,gestionnaire *gest,QWidget *parent);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *e);
public slots:
    void animate();


protected:
    void paintEvent(QPaintEvent *event);
signals:
    void AjoutTour(int newt);
    void updatelabel();
    void mousepress(int x,int y,bool valide);
private:
    gestionnaire *gest;
    long elapsed;
    int newtower;
    int mapx,mapy;
    int grido[24][12];
};

#endif // MAPGRID_H

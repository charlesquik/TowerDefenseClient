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
    void AjoutTour(Tower *newt);
    void updatelabel();
private:
    gestionnaire *gest;
    long elapsed;
    int newtower;
};

#endif // MAPGRID_H

#ifndef MAPGRID_H
#define MAPGRID_H

#include <QObject>
#include "gestionnaire.h"
#include "tower.h"


class MapGrid : public QWidget
{
    Q_OBJECT
public:
    explicit MapGrid(gestionnaire gest,QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
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

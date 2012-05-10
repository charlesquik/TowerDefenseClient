#ifndef MAPGRID_H
#define MAPGRID_H

#include <QObject>
#include "gestionnaire.h"
#include "tower.h"
#include <QMouseEvent>
#include <QtGui>


class MapGrid : public QWidget
{
    Q_OBJECT
public:
    explicit MapGrid(QRect ecran,char gridc[576][3],gestionnaire *gest,QWidget *parent);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void batirmap();
public slots:
    void animate();


protected:
    void paintEvent(QPaintEvent *event);
signals:
   // void AjoutTour(int,int,int,QRect);
    void updatelabel();
    void mousepress(int x,int y,bool valide);
private:
    gestionnaire *gesti;
    long elapsed;
    int newtower;
    //QPainter painter;
    bool phaseini;
    QRect m_ecran;
    char m_gridc[576][3];
    int mapx,mapy;
    int grido[24][24];
};

#endif // MAPGRID_H

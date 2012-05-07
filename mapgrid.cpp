#include "mapgrid.h"
#include <QtGui>
#include "gestionnaire.h"

MapGrid::MapGrid(QRect ecran,gestionnaire *gest,QWidget *parent) :
    QWidget(parent), gest(gest)
{
    elapsed=0;
    setFixedSize((ecran.width()-50)/2);
    setAutoFillBackground(false);
    mapx=(ecran.width()-100)/12;
    mapy=(ecran.height()/12;
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<12;j++)
        {
             if(i<=12 && j<=12)
             {
                Grido[i][j]=true;
             }
             else
             {
                Grido[i][j]=false;
             }
        }
    }
}

void MapGrid::animate()
{
   // if (gestionnaire->gameresult == 1)
   // {
   //     gameOverW();
  //      return;
  // else if (gestionnaire->gameresult == 2)
  //  {
  //      gameOverL();
  //      return;
  //  }
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval());
    repaint();
}
void MapGrid::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    gestionnaire->paint(&painter,event,elapsed);
    painter.end();
}
void MapGrid::mousePressEvent(QMouseEvent *event)
{
    int x=event->x()/mapx;
    int y=event->y()/mapy;
    if(map[x][y])
    {
        bool valide=map[x][y];
        emit mousepress(x,y,valide);
    }
}
void MapGrid::mouseDoubleClickEvent(QMouseEvent *e)
{
    int x=e->x()/mapx;
    int y=e->y()/mapy;
    if(map[x][y]==true)
    {
        emit AjoutTour(newtower);
    }
}

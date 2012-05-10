#include "mapgrid.h"
#include <QtGui>
#include "gestionnaire.h"

MapGrid::MapGrid(QRect ecran,gestionnaire *gest,QWidget *parent) :
    QWidget(parent), gesti(gest)
{
    elapsed=0;
  //  setFixedSize((ecran.width()-(ecran.width()/10)),ecran.height());
    setFixedSize(ecran.width(),ecran.height());
    this->showFullScreen();
    setAutoFillBackground(false);
    m_ecran=ecran;
    phaseini=true;
   // mapx=(ecran.width()-(ecran.width()/10))/24;
    mapx=(int)(ecran.width()/24);
    mapy=(int)(ecran.height()/24);
    //connect(this,SIGNAL(AjoutTour(int,int,int,QRect)),gesti,SLOT(ajouttour(int,int,int,QRect)));

    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {
             if(i<=12 && j<=24)
             {             
                grido[i][j]=1;
             }
             else
             {
                grido[i][j]=0;
             }
        }
    }
    for(int i=0;i<24;i++)
    {
        grido[i][11]=0;
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

    gesti->paint(&painter,event,elapsed);
   // painter.end();
}
void MapGrid::mousePressEvent(QMouseEvent *event)
{
//    int x=event->x()/mapx;
//    int y=event->y()/mapy;
//    if(grido[x][y])
//    {
//        bool valide=grido[x][y];
//        emit mousepress(x,y,valide);
//    }
}
void MapGrid::mouseDoubleClickEvent(QMouseEvent *e)
{
    int x=(int)(e->x()/mapx);
    int y=(int)(e->y()/mapy);
    if(grido[x][y]==1)
    {
        Tower *t;
        Monstre *m;
        QVector2D me(100,100);
       // m=new Monstre(me,10,100,1,20,Qt::green);
        //  t=new Tower(e->x() - e->x() % mapx + mapx/2,e->y() - e->y() % mapy + mapy/2,20,20,50,10,1,10,Qt::black,Qt::blue,40);
         t=new Tower(x*mapx+mapx/4,y*mapy+mapy/4,20,20,50,10,1,10,Qt::black,Qt::blue,mapx/2);
        //emit AjoutTour(1,e->x(),e->y(),m_ecran);
        gesti->ListeTower.append(t);
     //   gesti->ListeMonstre.append(m);
        grido[x][y]==false;
    }
}
void MapGrid::batirmap()
{

}

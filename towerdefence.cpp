#include "towerdefence.h"
#include "ui_towerdefence.h"
#include <QPainter>
#include "mapgrid.h"
#include <QPaintEvent>
#include <QApplication>
#include <QDesktopWidget>
#include "mapgrid.h"
#include "gestionnaire.h"
#include "controlpannel.h"

TowerDefence::TowerDefence(QString carte, int vie, int credit):QMainWindow(),
    ui(new Ui::TowerDefence)
{
    ui->setupUi(this);
    QRect ecran=QApplication::desktop()->rect();
    this->setFixedSize(ecran.width(),ecran.height());
    QPixmap map("lol.jpg");
    gest=new gestionnaire(map);
    mavue=new MapGrid(ecran,gest,this);
    moncontrole=new ControlPannel(ecran,this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),moncontrole,SLOT(animate()));
    connect(timer, SIGNAL(timeout()), mavue, SLOT(animate()));
    //connect(mavue, SIGNAL(updatelabel()), this, SLOT(SetLabel()));
    timer->start(30);
}

TowerDefence::~TowerDefence()
{
    delete ui;
}
//void TowerDefence::paintEvent(QPaintEvent *paint)
//{
 //   QPainter painter(this);
 //   painter.setRenderHint(QPainter::Antialiasing);
//}
void TowerDefence::abandonner()
{

}

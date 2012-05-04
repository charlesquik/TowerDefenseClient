#include "towerdefence.h"
#include "ui_towerdefence.h"
#include <QPainter>
#include "mapgrid.h"
#include <QPaintEvent>
#include <QApplication>
#include <QDesktopWidget>
#include "mapgrid.h"

TowerDefence::TowerDefence(QString carte, int vie, int credit):QMainWindow(),
    ui(new Ui::TowerDefence)
{
    ui->setupUi(this);
    //this->showFullScreen();
    QRect ecran=QApplication::desktop()->rect();
    this->setFixedSize(ecran.width(),ecran.height());
    MapGrid *mavue=new MapGrid(&Gestionnaire,this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), mavue, SLOT(animate()));
    connect(mavue, SIGNAL(updatelabel()), this, SLOT(SetLabel()));

   //  connect(glw, SIGNAL(gameOverL()) , this, SLOT(EndGameL()));
   // connect(glw, SIGNAL(gameOverW()) , this, SLOT(EndGameW()));

    timer->start(30);

   // graphics = new scene(carte,this->joueur1, this);
}

TowerDefence::~TowerDefence()
{
    delete ui;
}
void TowerDefence::paintEvent(QPaintEvent *paint)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

}
void TowerDefence::abandonner()
{

}

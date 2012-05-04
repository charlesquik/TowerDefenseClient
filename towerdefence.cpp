#include "towerdefence.h"
#include "ui_towerdefence.h"
#include <QPainter>
#include "mapgrid.h"
#include "scene.h"
#include <QPaintEvent>
#include <QApplication>
#include <QDesktopWidget>

TowerDefence::TowerDefence(QString carte, int vie, int credit):QMainWindow(),
    ui(new Ui::TowerDefence)
{
    ui->setupUi(this);
    //this->showFullScreen();
    QRect ecran=QApplication::desktop()->rect();
    this->setFixedSize(ecran.width(),ecran.height());

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


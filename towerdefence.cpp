#include "towerdefence.h"
#include "ui_towerdefence.h"
#include <QPainter>
#include <QPaintEvent>

TowerDefence::TowerDefence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TowerDefence)
{
    ui->setupUi(this);
}

TowerDefence::~TowerDefence()
{
    delete ui;
}
void TowerDefence::paintEvent(QPaintEvent *paint)
{
    QPainter painter(this);
  //  painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(100,100,100,100);
    painter.setBrush(Qt::black);
    painter.drawRect(140,150,20,100);
}


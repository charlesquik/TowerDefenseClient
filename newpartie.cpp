#include "newpartie.h"
#include "ui_newpartie.h"
#include "qpalette.h"
#include <QMouseEvent>
#include "towerdefence.h"

newpartie::newpartie(QTcpSocket socket,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newpartie)
{
    //m_socket = socket;
    ui->setupUi(this);
    ui->frame->setAutoFillBackground(true);
    ui->frame_2->setAutoFillBackground(true);
    ui->frame_3->setAutoFillBackground(true);
    ui->frame_4->setAutoFillBackground(true);
    QPixmap map("allo.jpg");

    map.scaled(ui->frame->width(),ui->frame->height());

    p.setBrush(QPalette::Window, QBrush(QPixmap(map)));
    ui->frame->setPalette(p);
    p.setBrush(QPalette::Window, QBrush(QPixmap(map)));
    ui->frame_2->setPalette(p);
    p.setBrush(QPalette::Window, QBrush(QPixmap(map)));
    ui->frame_3->setPalette(p);
    p.setBrush(QPalette::Window, QBrush(QPixmap(map)));
    ui->frame_4->setPalette(p);
    vie=20;
    argent=200;
    difficulte=1;
    lamap="map1";
    p.setColor(QPalette::Foreground,Qt::blue);
    reset();
}

newpartie::~newpartie()
{
    delete ui;
}
void newpartie::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        if((e->pos().x() > ui->frame->x()) && (e->pos().y() >ui->frame->pos().y()) && (e->pos().x() < (ui->frame->x()+ui->frame->width()) )&&( e->pos().y()<(ui->frame->y()+ui->frame->height())))
        {
            reset();
            ui->frame->setFrameStyle(QFrame::Box);
            ui->frame->setLineWidth(3);
            ui->frame->setPalette(p);
        }
        else if((e->pos().x() > ui->frame_2->x()) && (e->pos().y() >ui->frame_2->pos().y()) && (e->pos().x() < (ui->frame_2->x()+ui->frame_2->width()) )&&( e->pos().y()<(ui->frame_2->y()+ui->frame_2->height())))
        {
            reset();
            ui->frame_2->setFrameStyle(QFrame::Box);
            ui->frame_2->setLineWidth(3);
            ui->frame_2->setPalette(p);
        }
        else if((e->pos().x() > ui->frame_3->x()) && (e->pos().y() >ui->frame_3->pos().y()) && (e->pos().x() < (ui->frame_3->x()+ui->frame_3->width()) )&&( e->pos().y()<(ui->frame_3->y()+ui->frame_3->height())))
        {
            reset();
            ui->frame_3->setFrameStyle(QFrame::Box);
            ui->frame_3->setLineWidth(3);
            ui->frame_3->setPalette(p);
        }
        else if((e->pos().x() > ui->frame_4->x()) && (e->pos().y() >ui->frame_4->pos().y()) && (e->pos().x() < (ui->frame_4->x()+ui->frame_4->width()) )&&( e->pos().y()<(ui->frame_4->y()+ui->frame_4->height())))
        {
            reset();
            ui->frame_4->setFrameStyle(QFrame::Box);
            ui->frame_4->setLineWidth(3);
            ui->frame_4->setPalette(p);
        }
    }
}
void newpartie::reset()
{
    ui->frame->setFrameStyle(QFrame::NoFrame);
    ui->frame_2->setFrameStyle(QFrame::NoFrame);
    ui->frame_3->setFrameStyle(QFrame::NoFrame);
    ui->frame_4->setFrameStyle(QFrame::NoFrame);
}

void newpartie::on_btnok_clicked()
{
    if(!ui->txtargent->text().isNull())
    {
       argent=atoi(ui->txtargent->text().toAscii());
       if(argent==0)
            argent=200;
    }
    if(!ui->txtvie->text().isNull())
    {
        vie=atoi(ui->txtvie->text().toAscii());
        if(vie==0)
            vie=20;
    }

    //m_socket.write("1");

    TowerDefence *lobby=new TowerDefence(lamap,vie,argent);
    lobby->showFullScreen();
    this->close();
}

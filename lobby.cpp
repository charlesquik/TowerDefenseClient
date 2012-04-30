#include "lobby.h"
#include "ui_lobby.h"
#include "mainmenu.h"
#include "towerdefence.h""


Lobby::Lobby(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
}

Lobby::~Lobby()
{
    delete ui;
}

void Lobby::on_btn_retour_clicked()
{

    MainMenu *dmainmenu=new MainMenu();
    dmainmenu->show();
    this->close();
}

void Lobby::on_btn_Creer_clicked()
{
    TowerDefence *dmainmenu=new TowerDefence();
    dmainmenu->show();
    this->close();
}

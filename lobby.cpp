#include "lobby.h"
#include "ui_lobby.h"
#include "mainmenu.h"
#include "towerdefence.h""
#include "newpartie.h"


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
    newpartie *dmainmenu=new newpartie();
    dmainmenu->show();
    this->close();
}

#include "lobby.h"
#include "ui_lobby.h"
#include "mainmenu.h"
#include "towerdefence.h"
#include "newpartie.h"
#include <QtNetwork>
#include <QMessageBox>


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
    if (m_socket.state() != QAbstractSocket::ConnectedState)
    {
        if (connectionServeur())
        {
            newpartie *dmainmenu=new newpartie(m_socket);
            dmainmenu->show();
            this->close();
        }
    }
}

void Lobby::on_btn_rafraichir_clicked()
{
    if (m_socket.state() != QAbstractSocket::ConnectedState)
    {
        if (connectionServeur())
        {
            m_socket.write("2");
        }
    }
}

bool Lobby::connectionServeur()
{
    bool connecter = false;
    m_socket.connectToHost(QHostAddress::LocalHost, 87878);
    m_socket.waitForConnected(10000);
    if (m_socket.state() == QAbstractSocket::ConnectedState)
    {
        connecter = true;
        QMessageBox msg(QMessageBox::Information,"Connection","La connection au serveur à été effectuer avec succès", QMessageBox::Ok);
        msg.show();
    }
    else
    {
        QMessageBox msg(QMessageBox::Critical, "Connection", "La connection au serveur à échouée", QMessageBox::Ok);
        msg.show();
    }
    return connecter;
}

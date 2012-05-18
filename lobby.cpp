#include "lobby.h"
#include "ui_lobby.h"
#include "mainmenu.h"
#include "towerdefence.h"
#include "newpartie.h"
#include <QtNetwork>
#include <QMessageBox>
#include <QModelIndexList>
#include <QApplication>
#include <QDesktopWidget>


Lobby::Lobby(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
    m_socket = new QTcpSocket();
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
//    vérifie si le socket est connecter avec un serveur
    if (m_socket->state() != QAbstractSocket::ConnectedState)
    {
//        connecte le socket au serveur
        connectionServeur();
    }

//    afficher la page de création de partie lorsque connecter
    if (m_socket->state() == QAbstractSocket::ConnectedState)
    {
        newpartie *dmainmenu = new newpartie(m_socket, ui->txt_Joueur->text(), ui->txt_Partie->text());
        dmainmenu->show();
        this->close();
    }
}

void Lobby::on_btn_rafraichir_clicked()
{
    ui->listPartie->clear();
    //vérifie si le socket est connecter avec un serveur
    if (m_socket->state() != QAbstractSocket::ConnectedState)
    {
        //connecte le socket au serveur
        connectionServeur();
    }
    //éffectu la recherche des parite lorsque connecté
    if (m_socket->state() == QAbstractSocket::ConnectedState)
    {
        //le code "2" demande des parties au serveur

        m_socket->write(QString("2").toAscii());
        m_socket->waitForBytesWritten(500);
        if (m_socket->waitForReadyRead(500))
        {
            QByteArray bParam = m_socket->read(m_socket->bytesAvailable());
            QStringList parties = QString(bParam).split('#');
            foreach (QString partie, parties)
            {
                if(partie!="")
                    ui->listPartie->addItem(partie);
            }
        }
        else
        {
           // QMessageBox::critical(this, "Recherche des parties", QString::fromUtf8("Echec de la recherche des parties, le serveur ne répond pas"),QMessageBox::Ok);
        }
    }
}

void Lobby::connectionServeur()
{
    m_socket->connectToHost("172.16.15.10", 12345);
    m_socket->waitForConnected(10000);
    if (m_socket->state() == QAbstractSocket::ConnectedState)
    {
      //  QMessageBox::information(this, "Connection",QString::fromUtf8("La connection au serveur c'est effectuer avec succès"),QMessageBox::Ok);
    }
    else
    {
       // QMessageBox::critical(this, "Connection", QString::fromUtf8("La connection au serveur à échoué"),QMessageBox::Ok);
    }
}

void Lobby::on_btn_joindre_clicked()
{
    QByteArray recept="";
    if (m_socket->state() == QAbstractSocket::ConnectedState)
    {
        QModelIndex a;
        a=ui->listPartie->currentIndex();
        int i=a.row();
        m_socket->write(QString("3#").toAscii() +  QString::number(i).toAscii()+'#'+QString::number(QApplication::desktop()->rect().width()).toAscii()+'#'+QString::number(QApplication::desktop()->rect().height()).toAscii());
        m_socket->waitForBytesWritten(500);
        if(m_socket->waitForReadyRead(500)==true)
        {
            recept=m_socket->read(m_socket->bytesAvailable());
            QStringList partie=QString(recept).split('.');
            if(partie.at(0)=="#")
            {


                //newpartie *dmainmenu = new newpartie(m_socket, ui->txt_Joueur->text(), QString::number(ui->listPartie->currentIndex()).toAscii());
                //dmainmenu->show();
                //this->close();
                TowerDefence *nouvgame=new TowerDefence(partie.at(1),partie.at(2).toInt(),partie.at(3).toInt(),2,m_socket->socketDescriptor());
                nouvgame->showFullScreen();
                this->close();

            }
            else if(partie.at(0)=="@")
            {
                QMessageBox::information(this,"Erreur partie pleine","La partie est pleine!");
            }
        }
    }
}

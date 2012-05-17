#include "attentejoueur.h"
#include "ui_attentejoueur.h"
#include "towerdefence.h"

AttenteJoueur::AttenteJoueur(int socketDescriptor, QString nomMap, int vie, int argent) :
    ui(new Ui::AttenteJoueur)
{
    ui->setupUi(this);
    ui->setupUi(this);

    m_joueurConnecte = false;

    m_socket = new QTcpSocket(this);
    m_socket->setSocketDescriptor(socketDescriptor);
    connect(m_socket,SIGNAL(readyRead()),this, SLOT(slLectureSocket()));

    m_nomMap = nomMap;
    m_vie = vie;
    m_argent = argent;
}

void AttenteJoueur::slLectureSocket()
{
    QByteArray bChaine = m_socket->readAll();
    QStringList Param = QString(bChaine).split("#");
    if (Param.at(0).toInt() == 2 && m_joueurConnecte == true)
    {
        ui->lblTemps->setText(Param.at(1));
    }
    else if (Param.at(0).toInt() == 3 && m_joueurConnecte == false)
    {
        m_joueurConnecte = true;
        ui->lblInfo->setText("Un deuxième joueur est maintenant connecté");
        ui->lblInfo2->setText("La partie commence dans:");
        ui->lblinfo3->setText("secondes");
        ui->label->setText("Nom du joueur:");
        ui->lblNomJoueur->setText(Param.at(1));
    }
    if (Param.at(1).toInt() <= 0)
    {
        TowerDefence *lobby=new TowerDefence(m_nomMap,m_vie,m_argent,1);
        lobby->showFullScreen();
        this->close();
    }
}

AttenteJoueur::~AttenteJoueur()
{
    delete ui;
}

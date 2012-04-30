#ifndef LOBBY_H
#define LOBBY_H

#include <QWidget>

namespace Ui {
class Lobby;
}

class Lobby : public QWidget
{
    Q_OBJECT
    
public:
    explicit Lobby(QWidget *parent = 0);
    ~Lobby();
    
private slots:
    void on_btn_retour_clicked();

    void on_btn_Creer_clicked();

private:
    Ui::Lobby *ui;
};

#endif // LOBBY_H

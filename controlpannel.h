#ifndef CONTROLPANNEL_H
#define CONTROLPANNEL_H

#include <QWidget>
#include <QFrame>
#include "joueur.h"

class ControlPannel : public QWidget
{
    Q_OBJECT
public:

    explicit ControlPannel(QRect ecran,int vie,int money,int joueur, QWidget *parent = 0);
    int money;
    int vie;
    QFrame *q;
    int joueur;
    
signals:

protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void animate();
private:
    long elapsed;
    QRect ecranpannel;
    QImage tour1;
    QImage tour2;
};

#endif // CONTROLPANNEL_H

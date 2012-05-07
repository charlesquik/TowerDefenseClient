#ifndef CONTROLPANNEL_H
#define CONTROLPANNEL_H

#include <QWidget>

class ControlPannel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPannel(QRect ecran,QWidget *parent = 0);
    
signals:

protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void animate();
private:
    long elapsed;
    QRect ecranpannel;
};

#endif // CONTROLPANNEL_H

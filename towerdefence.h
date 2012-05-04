#ifndef TOWERDEFENCE_H
#define TOWERDEFENCE_H

#include <QMainWindow>

namespace Ui {
class TowerDefence;
}

class TowerDefence : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TowerDefence(QString carte, int vie, int credit);
    ~TowerDefence();
    
private:
    Ui::TowerDefence *ui;
private slots:
   void paintEvent(QPaintEvent *paint);
};

#endif // TOWERDEFENCE_H

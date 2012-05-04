#ifndef NEWPARTIE_H
#define NEWPARTIE_H

#include <QWidget>

namespace Ui {
class newpartie;
}

class newpartie : public QWidget
{
    Q_OBJECT
    
public:
    explicit newpartie(QWidget *parent = 0);
    ~newpartie();
    void reset();
    QPalette p;
   int  vie;
   int argent;
   int difficulte;
    QString lamap;
    
private:
    Ui::newpartie *ui;
protected:
    void mousePressEvent(QMouseEvent *e);
private slots:
    void on_btnok_clicked();
};

#endif // NEWPARTIE_H

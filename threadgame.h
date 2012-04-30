#ifndef THREADGAME_H
#define THREADGAME_H

#include <QThread>

class ThreadGame : public QThread
{
    Q_OBJECT
public:
    explicit ThreadGame(QObject *parent = 0);
    
signals:
    
public slots:
protected:
    void run();
};

#endif // THREADGAME_H

#-------------------------------------------------
#
# Project created by QtCreator 2012-04-29T21:14:22
#
#-------------------------------------------------

QT       += core gui
QT += qt3support

TARGET = TowerDefence
TEMPLATE = app


SOURCES += main.cpp\
        towerdefence.cpp \
    mainmenu.cpp \
    lobby.cpp \
    mapgrid.cpp \
    projectile.cpp \
    monstre.cpp \
    tower.cpp \
    joueur.cpp \
    newpartie.cpp \
    gestionnaire.cpp

HEADERS  += towerdefence.h \
    mainmenu.h \
    lobby.h \
    mapgrid.h \
    projectile.h \
    monstre.h \
    tower.h \
    joueur.h \
    newpartie.h \
    gestionnaire.h

FORMS    += towerdefence.ui \
    mainmenu.ui \
    lobby.ui \
    newpartie.ui

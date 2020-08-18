#-------------------------------------------------
#
# Project created by QtCreator 2020-08-14T10:17:29
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlantsVsZombies
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    Bullet.cpp \
    CherryIcon.cpp \
    GroundRect.cpp \
    Level1Button.cpp \
    Level2Button.cpp \
    Level3Button.cpp \
    Level4Button.cpp \
    Level5Button.cpp \
    Level6Button.cpp \
    Loading.cpp \
    LoadingRect.cpp \
    Menu.cpp \
    MenuButton.cpp \
    NutIcon.cpp \
    Plant.cpp \
    PlayButton.cpp \
    Shooter.cpp \
    ShooterIcon.cpp \
    ShovelIcon.cpp \
    SunFlowerIcon.cpp \
        main.cpp \
    Zombie.cpp \
    Sun.cpp \
    Score.cpp \
    Controller.cpp \
    View.cpp \
    Nut.cpp \
    SunFlower.cpp \
    CherryBomb.cpp

HEADERS += \
    Bullet.h \
    CherryIcon.h \
    GroundRect.h \
    Level1Button.h \
    Level2Button.h \
    Level3Button.h \
    Level4Button.h \
    Level5Button.h \
    Level6Button.h \
    Loading.h \
    LoadingRect.h \
    Menu.h \
    MenuButton.h \
    NutIcon.h \
    Plant.h \
    PlayButton.h \
    Shooter.h \
    ShooterIcon.h \
    ShovelIcon.h \
    SunFlowerIcon.h \
    Zombie.h \
    Sun.h \
    Score.h \
    Controller.h \
    View.h \
    Nut.h \
    SunFlower.h \
    CherryBomb.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rs.qrc

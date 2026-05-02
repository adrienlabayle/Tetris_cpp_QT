QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    I_tetro.cpp \
    J_tetro.cpp \
    L_tetro.cpp \
    O_tetro.cpp \
    S_tetro.cpp \
    T_tetro.cpp \
    Z_tetro.cpp \
    game.cpp \
    grid.cpp \
    main.cpp \
    mainwindow.cpp \
    tetromino.cpp

HEADERS += \
    I_tetro.h \
    J_tetro.h \
    L_tetro.h \
    O_tetro.h \
    S_tetro.h \
    T_tetro.h \
    Z_tetro.h \
    game.h \
    grid.h \
    mainwindow.h \
    tetromino.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

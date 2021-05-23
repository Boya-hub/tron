QT += widgets

LIBS += -L"$$PWD\lib"

INCLUDEPATH += .\include
DEPENDPATH += .\include

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

SOURCES += \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    smileyface.cpp

HEADERS += \
    gamewindow.h \
    main.h \
    mainwindow.h \
    player.h \
    smileyface.h

RESOURCES += \
    resources.qrc


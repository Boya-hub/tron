QT += widgets

LIBS += -L"$$PWD\lib"

INCLUDEPATH += .\include
DEPENDPATH += .\include

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    main.h \
    mainwindow.h


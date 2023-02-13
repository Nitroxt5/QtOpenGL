#-------------------------------------------------
#
# Project created by QtCreator 2022-04-30T16:59:42
#
#-------------------------------------------------

QT       += core gui
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTest
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mainWindow.cpp \
    buttonsWidget.cpp

HEADERS  += widget.h \
    mainWindow.h \
    buttonsWidget.h

FORMS    += widget.ui

win32: LIBS += -L$$PWD/../Qt5.2.1/Tools/mingw48_32/i686-w64-mingw32/lib/ -lglut32

INCLUDEPATH += $$PWD/../Qt5.2.1/Tools/mingw48_32/i686-w64-mingw32/include
DEPENDPATH += $$PWD/../Qt5.2.1/Tools/mingw48_32/i686-w64-mingw32/include

TARGET = demo
TEMPLATE = app
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) {
    CONFIG += c++11
    QT += widgets
} else {
    QMAKE_CXXFLAGS += -std=c++0x
}

HEADERS += demo.h
SOURCES += main.cpp demo.cpp
FORMS += demo.ui

include(../QtDateTimeEditor/QtDateTimeEditor.pri)

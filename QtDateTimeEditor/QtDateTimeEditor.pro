TARGET = QtDateTimeEditor
TEMPLATE = lib
CONFIG += staticlib
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) {
    CONFIG += c++11
    QT += widgets
} else {
    QMAKE_CXXFLAGS += -std=c++0x
}

SOURCES += dateTimeEditor.cpp
HEADERS += dateTimeEditor.h

isEmpty(PREFIX) {
    unix {
        PREFIX = /usr
    } else {
        PREFIX = $$[QT_INSTALL_PREFIX]
    }
}

install_headers.files = $$HEADERS
install_headers.path = $$PREFIX/include/QtDateTimeEditor
target.path = $$PREFIX/lib
INSTALLS += install_headers target

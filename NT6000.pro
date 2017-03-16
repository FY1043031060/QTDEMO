#-------------------------------------------------
#
# Project created by QtCreator 2017-03-12T14:45:04
#
#-------------------------------------------------

QT       += core gui charts quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NT6000
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS\
            QT_DLL QWT_DLL
INCLUDEPATH += QWT
LIBS += -L"./LIBS" -lqwtd
LIBS += -L"./LIBS" -lqwt


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        Monitor.cpp \
    Workbench.cpp \
    ToolWindow.cpp \
    SettingWindow.cpp \
    CompassFactory.cpp \
    attitude_indicator.cpp \
    speedo_meter.cpp \
    qtest.cpp

HEADERS  += Monitor.h \
    Workbench.h \
    ToolWindow.h \
    SettingWindow.h \
    attitude_indicator.h \
    speedo_meter.h \
    CompassFactory.h \
    qtest.h

FORMS    += Monitor.ui \
    Workbench.ui \
    ToolWindow.ui \
    SettingWindow.ui

RESOURCES += \
    resource.qrc


CONFIG+=declarative_debug
CONFIG+=qml_debug

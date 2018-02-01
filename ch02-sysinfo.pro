#-------------------------------------------------
#
# Project created by QtCreator 2018-01-26T11:42:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

TARGET = SysInfoMonitor
TEMPLATE = app
CONFIG += C++14

SOURCES += main.cpp\
        mainwindow.cpp \
    sysinfo.cpp \
    sysinfowidget.cpp \
    cpuwindget.cpp \
    memorywidget.cpp

HEADERS  += mainwindow.h \
    sysinfo.h \
    sysinfowidget.h \
    cpuwindget.h \
    memorywidget.h

# Linux specific files
linux{
SOURCES += sysinfolinuximpl.cpp

HEADERS  += sysinfolinuximpl.h

message(Compile for Linux)
}

#Windows specific files
windows{
SOURCES += sysinfowindowsimpl.cpp

HEADERS  += sysinfowindowsimpl.h
message(Compile for windows)
}

FORMS    += mainwindow.ui

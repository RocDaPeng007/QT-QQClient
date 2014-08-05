#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T16:20:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQClient
TEMPLATE = app
RC_FILE = icon.rc

#语言国际化
#中文
TRANSLATIONS+=cn.ts
#英文
TRANSLATIONS+=en.ts

SOURCES += main.cpp\
        mainwindow.cpp \
    chatdialog.cpp \
    informationform.cpp \
    logindialog.cpp \
    pushbuttonex.cpp \
    moreform.cpp \
    qqlistwidget.cpp \
    qqlistviewgroup.cpp \
    qqlistviewchild.cpp \
    qqcell.cpp \
    qqpopmenuwidget.cpp \
    addfrienddialog.cpp \
    addgroupdialog.cpp \
    qqsystemtraydialog.cpp \
    qqtrayiconwidget.cpp

HEADERS  += mainwindow.h \
    chatdialog.h \
    informationform.h \
    logindialog.h \
    pushbuttonex.h \
    moreform.h \
    qqlistwidget.h \
    qqlistviewgroup.h \
    qqlistviewchild.h \
    qqcell.h \
    qqpopmenuwidget.h \
    addfrienddialog.h \
    addgroupdialog.h \
    qqsystemtraydialog.h \
    qqtrayiconwidget.h

FORMS    += mainwindow.ui \
    chatdialog.ui \
    informationform.ui \
    logindialog.ui \
    moreform.ui \
    qqlistviewgroup.ui \
    qqlistviewchild.ui \
    addfrienddialog.ui \
    addgroupdialog.ui \
    qqsystemtraydialog.ui \
    qqtrayiconwidget.ui

RESOURCES += \
    rec.qrc

OTHER_FILES += \
    icon.rc


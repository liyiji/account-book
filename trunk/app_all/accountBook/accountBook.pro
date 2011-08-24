
TEMPLATE = app
TARGET = accountBook
DEPENDPATH += .
INCLUDEPATH += . \
               ../../lib_all/md5

QMAKE_CC = gcc
QMAKE_CXX = g++
QMAKE_LINK = g++

DESTDIR = ../../../bin_accountBook

OBJECTS_DIR = .obj
MOC_DIR     = .moc
RCC_DIR     = .rcc
UI_DIR      = .uidir

QT      +=  gui sql
CONFIG 	+=  warn_on

#DEFINES += DEBUG_VERSION

HEADERS +=
SOURCES +=
FORMS   +=

HEADERS +=
SOURCES +=
FORMS   +=

SOURCES +=  accountBookMain.cpp

HEADERS +=  ABMainWindow.h
SOURCES +=  ABMainWindow.cpp
FORMS   +=  ABMainWindow.ui

HEADERS +=  ABInputPassword.h
SOURCES +=  ABInputPassword.cpp
FORMS   +=  ABInputPassword.ui

HEADERS +=  ABTransactionDetail.h
SOURCES +=  ABTransactionDetail.cpp
FORMS   +=  ABTransactionDetail.ui

HEADERS +=  ABManageAccount.h
SOURCES +=  ABManageAccount.cpp
FORMS   +=  ABManageAccount.ui

HEADERS +=  ABManageCategory.h
SOURCES +=  ABManageCategory.cpp
FORMS   +=  ABManageCategory.ui

HEADERS +=  ABFunction.h
SOURCES +=  ABFunction.cpp

HEADERS +=  ABSqlQuery.h
SOURCES +=  ABSqlQuery.cpp

HEADERS +=  ABDefines.h

LIBS    +=  -L../../../bin_accountBook/ -lmd5


TEMPLATE = app
TARGET = accountBook
DEPENDPATH += ./src
INCLUDEPATH += ./src

QMAKE_CC = gcc
QMAKE_CXX = g++
QMAKE_LINK = g++

DESTDIR = ../bin_accountBook

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

SOURCES +=  ./src/accountBookMain.cpp

HEADERS +=  ./src/ABMainWindow.h
SOURCES +=  ./src/ABMainWindow.cpp
FORMS   +=  ./src/ABMainWindow.ui

HEADERS +=  ./src/ABInputPassword.h
SOURCES +=  ./src/ABInputPassword.cpp
FORMS   +=  ./src/ABInputPassword.ui

HEADERS +=  ./src/ABTransactionDetail.h
SOURCES +=  ./src/ABTransactionDetail.cpp
FORMS   +=  ./src/ABTransactionDetail.ui

HEADERS +=  ./src/ABManageAccount.h
SOURCES +=  ./src/ABManageAccount.cpp
FORMS   +=  ./src/ABManageAccount.ui

HEADERS +=  ./src/ABManageCategory.h
SOURCES +=  ./src/ABManageCategory.cpp
FORMS   +=  ./src/ABManageCategory.ui

HEADERS +=  ./src/ABFunction.h
SOURCES +=  ./src/ABFunction.cpp

HEADERS +=  ./src/ABSqlQuery.h
SOURCES +=  ./src/ABSqlQuery.cpp

HEADERS +=  ./src/ABDefines.h

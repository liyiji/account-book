
TEMPLATE = app
TARGET = accountBook
DEPENDPATH += .
INCLUDEPATH += . \
               ../../lib_all/md5

include(../../compile_parameter/compile_parameter.mk)
QT      +=  gui sql

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

RESOURCES += ../../qrc/accountBook.qrc
RC_FILE   += ../../qrc/accountBook.rc

LIBS    +=  -L../../../bin_accountBook/ -lmd5

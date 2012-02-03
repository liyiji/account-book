
TEMPLATE = lib
TARGET = md5
DEPENDPATH += .
INCLUDEPATH += $$DEPENDPATH

include(../../compile_parameter/compile_parameter.mk)

HEADERS +=  md5.h
SOURCES +=  md5.cpp

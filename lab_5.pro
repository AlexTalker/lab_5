TEMPLATE = app
TARGET = lab5
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11

SOURCES += main.cpp \
    text.cpp \
	editabletext.cpp

HEADERS += \
    text.h \
	editabletext.h

OTHER_FILES += \
	test.txt

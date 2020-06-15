include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_calculator.h \
    ../Project_for_tests/IKeypad.h \
    ../Project_for_tests/ILatch.h \
    ../Project_for_tests/lockcontroller.h

SOURCES +=     main.cpp \
    ../Project_for_tests/lockcontroller.cpp

INCLUDEPATH += ../Project_for_tests


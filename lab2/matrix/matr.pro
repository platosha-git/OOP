TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    matrix.h \
    rowConstructors.h \
    errors.h \
    matrixConstructors.h \
    rowOperators.h \
    matrixOperators.h \
    matrixMethods.h \
    iterator.h \
    iteratorConstructors.h \
    iteratorMethods.h \
    iteratorOperators.h \
    matrixFriendOperators.h \
    matrixBaseFunc.h \
    matrixBase.h \
    row.h \
    rowMethods.h \
    rowBaseFunc.h \
    errorsBase.h

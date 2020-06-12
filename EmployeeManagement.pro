TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        EmployeeCheckIn.cpp \
        employee.cpp \
        main.cpp

HEADERS += \
    EmployeeCheckIn.h \
    employee.h

DISTFILES += \
    data.csv

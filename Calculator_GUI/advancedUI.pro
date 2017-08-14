QT += widgets

HEADERS += calwidget.h \
    button.h \
    expression.h \
    advanced_mainwindow.h \
    advanced_calwidget.h \
    mainwindow.h \
    st_mainwindow.h \
    statistics.h \
    randomwidget.h \
    randmainwindow.h \
    memory.h \
    fractin.h \
    fraction_expression.h \
    equationmainwindow.h \
    sdf_mainwindow.h \
    variable.h \
    complex.h \
    mainwindow_complex.h \
    mainwindow_poly.h \
    poly.h  \
    nu_mainwindow.h \
    numberchange.h



SOURCES += main.cpp \
    calwidget.cpp \
    button.cpp \
    expressionfunc.cpp \
    advanced_mainwindow.cpp \
    advanced_calwidget.cpp \
    mainwindow.cpp \
    st_mainwindow.cpp \
    statistics.cpp \
    randomwidget.cpp \
    memory.cpp \
    fractin.cpp \
    fraction_expression.cpp \
    equationmainwindow.cpp \
    sdf_mainwindow.cpp \
    variable.cpp \
    complex.cpp \
    mainwindow_complex.cpp \
    mainwindow_poly.cpp \
    poly.cpp \
    nu_mainwindow.cpp \
    numberchange.cpp


FORMS    +=st_mainwindow.ui \
    randomwidget.ui \
    fractin.ui \
    equationmainwindow.ui \
    sdf_mainwindow.ui \
    mainwindow_complex.ui \
    mainwindow_poly.ui \
    NUMainWindow.ui


RESOURCES += \
    icon.qrc

RC_ICONS = images/Calculator.ico

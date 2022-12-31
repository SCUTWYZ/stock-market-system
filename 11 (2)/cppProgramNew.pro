QT       += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    afterloginin.cpp \
    business.cpp \
    commissionBusiness.cpp \
    company.cpp \
    Daccount.cpp \
    Dfinance.cpp \
    finance.cpp \
    god.cpp \
    holdshares.cpp \
    innovationPlateStock.cpp \
    listedcompany.cpp \
    main.cpp \
    mainPlateStock.cpp \
    mainwindow.cpp \
    mystock.cpp \
    pbmore.cpp \
    sign1.cpp \
    sign2.cpp \
    stock.cpp \
    stockbase.cpp \
    stockholder.cpp \
    stockPerDay.cpp \
    subscriptionofnewshares.cpp \
    success.cpp \
    totalaccount.cpp \
    totalclass.cpp \
    transaction.cpp \
    transactioninformation.cpp \
    widget.cpp \
    candlestickdatareader.cpp

HEADERS += \
    account.h \
    afterloginin.h \
    business.h \
    commissionBusiness.h \
    company.h \
    Daccount.h \
    Dfinance.h \
    finance.h \
    god.h \
    holdshares.h \
    innovationPlateStock.h \
    listedcompany.h \
    mainPlateStock.h \
    mainwindow.h \
    mystock.h \
    pbmore.h \
    sign1.h \
    sign2.h \
    stock.h \
    stockbase.h \
    stockholder.h \
    stockPerDay.h \
    subscriptionofnewshares.h \
    success.h \
    totalaccount.h \
    totalclass.h \
    transaction.h \
    transactioninformation.h \
    widget.h \
    candlestickdatareader.h

FORMS += \
    afterloginin.ui \
    Daccount.ui \
    Dfinance.ui \
    god.ui \
    holdshares.ui \
    listedcompany.ui \
    mainwindow.ui \
    pbmore.ui \
    sign1.ui \
    sign2.ui \
    subscriptionofnewshares.ui \
    success.ui \
    transaction.ui \
    transactioninformation.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc \
    res.qrc \
    candlestickdata.qrc

SUBDIRS += \
    cppProgram.pro

DISTFILES += \
    cppProgram.pro.user

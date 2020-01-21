QT -= gui
QT += core network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#INCLUDEPATH += ..//omniORB-4.1.4//include
#LIBS += ..//omniORB-4.1.4//lib

#INCLUDEPATH += ..\omniORB-4.2.0\include
#LIBS += ..\omniORB-4.2.0\lib\x86_win32\omniORB4.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniORB4_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniORB4_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniORB4d.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniORB420_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniORB420_rtd.lib \
##
#        ..\omniORB-4.2.0\lib\x86_win32\omnithread.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnithread_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnithread_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnithread40_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnithread40_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnithreadd.lib \
##
#        ..\omniORB-4.2.0\lib\x86_win32\omnisslTP4.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnisslTP4_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnisslTP4_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnisslTP4d.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnisslTP420_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omnisslTP420_rtd.lib \
##
#        ..\omniORB-4.2.0\lib\x86_win32\omniDynamic4.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniDynamic4_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniDynamic4_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniDynamic4d.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniDynamic420_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniDynamic420_rtd.lib \
##
#        ..\omniORB-4.2.0\lib\x86_win32\omniConnectionMgmt4.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniConnectionMgmt4_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniConnectionMgmt4_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniConnectionMgmt4d.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniConnectionMgmt420_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniConnectionMgmt420_rtd.lib \
##
#        ..\omniORB-4.2.0\lib\x86_win32\omniCodeSets4.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniCodeSets4_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniCodeSets4_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniCodeSets4d.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniCodeSets420_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\omniCodeSets420_rtd.lib \
##
#        ..\omniORB-4.2.0\lib\x86_win32\msvcstub.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\msvcstubd.lib \
##
#        ..\omniORB-4.2.0\lib\x86_win32\COSDynamic4.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COSDynamic4_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COSDynamic4_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COSDynamic4d.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COSDynamic420_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COSDynamic420_rtd.lib \
##
#        ..\omniORB-4.2.0\lib\x86_win32\COS4.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COS4_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COS4_rtd.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COS4d.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COS420_rt.lib \
#        ..\omniORB-4.2.0\lib\x86_win32\COS420_rtd.lib
#        ..\omniORB-4.2.0\bin\x86_win32\omniORB420_vc10_rt.dll
#!win32:LIBS += -lomniORB4 -lomnithread -lssl -lcrypto


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        #echo.cpp \
        main.cpp \
        pstatus.cpp \
        tserver.cpp \
        tsocket.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    core.h \
    #echo.h \
    pstatus.h \
    tserver.h \
    tsocket.h

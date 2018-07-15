#-------------------------------------------------
#
# Project created by QtCreator 2018-07-14T15:36:55
#
#-------------------------------------------------

QT       += core gui network websockets testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyIPAddress
TEMPLATE = app


CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    jcon/json_rpc_client.cpp \
    jcon/json_rpc_debug_logger.cpp \
    jcon/json_rpc_endpoint.cpp \
    jcon/json_rpc_error.cpp \
    jcon/json_rpc_file_logger.cpp \
    jcon/json_rpc_logger.cpp \
    jcon/json_rpc_request.cpp \
    jcon/json_rpc_success.cpp \
    jcon/json_rpc_tcp_client.cpp \
    jcon/json_rpc_tcp_socket.cpp \
    jcon/json_rpc_websocket.cpp \
    jcon/json_rpc_websocket_client.cpp \
    jcon/string_util.cpp \

HEADERS += \
        mainwindow.h \
    jcon/jcon.h \
    jcon/jcon_assert.h \
    jcon/json_rpc_client.h \
    jcon/json_rpc_debug_logger.h \
    jcon/json_rpc_endpoint.h \
    jcon/json_rpc_error.h \
    jcon/json_rpc_file_logger.h \
    jcon/json_rpc_logger.h \
    jcon/json_rpc_request.h \
    jcon/json_rpc_result.h \
    jcon/json_rpc_socket.h \
    jcon/json_rpc_success.h \
    jcon/json_rpc_tcp_client.h \
    jcon/json_rpc_tcp_socket.h \
    jcon/json_rpc_websocket.h \
    jcon/json_rpc_websocket_client.h \
    jcon/string_util.h \

FORMS += \
        mainwindow.ui

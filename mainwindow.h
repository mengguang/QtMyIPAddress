#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <jcon/json_rpc_tcp_client.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_getButton_clicked();
    void http_request_finished();
    void http_ready_read();
    void read_ping_output();
    void on_pingButton_clicked();
    void on_stopButton_clicked();

    void on_rpcButton_clicked();

    void on_MainWindow_destroyed();

private:
    QByteArray data;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    Ui::MainWindow *ui;
    QProcess ping;
    jcon::JsonRpcClient* rpc_client;
};

#endif // MAINWINDOW_H

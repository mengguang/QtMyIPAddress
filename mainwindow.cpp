#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QtNetwork>
#include <QJsonDocument>
#include <QString>
#include <QProcess>
#include <jcon/json_rpc_file_logger.h>
#include <jcon/json_rpc_tcp_client.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getButton_clicked()
{
    auto url = QUrl("https://learndevops.cn/json.php");
    reply = qnam.get(QNetworkRequest(url));
    connect(reply,&QNetworkReply::finished,this,&MainWindow::http_request_finished);
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::http_ready_read);
}

void MainWindow::http_ready_read() {
    data += reply->readAll();
}


void MainWindow::http_request_finished(){
    auto json = QJsonDocument::fromJson(data);
    qDebug(json.toJson());
    auto val = json.object().value("REMOTE_ADDR");
    if (val.isString()) {
        ui->result->setText(val.toString());
    }
    //ui->result->setText(data);
    //qnam.deleteLater();
    data="";
}

void MainWindow::on_pingButton_clicked()
{
    //ping = QProcess();
    ping.setProgram("ping");
    QStringList args;
    args.append("-t");
    args.append("learndevops.cn");
    ping.setArguments(args);
    connect(&ping,&QProcess::readyReadStandardOutput,this,&MainWindow::read_ping_output);
    ping.start();

}

void MainWindow::read_ping_output() {
    qDebug(ping.readAll());
}

void MainWindow::on_stopButton_clicked()
{
    ping.kill();
}

void MainWindow::on_rpcButton_clicked()
{
    jcon::JsonRpcClient* rpc_client;
    rpc_client = new jcon::JsonRpcTcpClient(this);
    rpc_client->connectToServer("testnet.cloud.diynova.com",8900);
    auto req = rpc_client->callAsync("Math.Add", 10,20);

    req->connect(req.get(), &jcon::JsonRpcRequest::result,
                 [](const QVariant& result) {
                     qDebug() << "result of asynchronous RPC call:" << result;
                 });

    req->connect(req.get(), &jcon::JsonRpcRequest::error,
                 [](int code, const QString& message, const QVariant& data) {
                     qDebug() << "RPC error:" << message
                              << " (" << code << ")";
                 });
}

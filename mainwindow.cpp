#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QtNetwork>
#include <QJsonDocument>
#include <QString>

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

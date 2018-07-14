#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

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

private:
    QByteArray data;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

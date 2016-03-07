#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void onNewConnection();
    void onReadyRead();
    void onConnected();
    void onDisConnected();

private slots:
    void on_pushButton_clicked();

    void on_pbEnvoyer_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *serveur;
    QTcpSocket *sock;
    QList<QTcpSocket *> listeClients;
};

#endif // MAINWINDOW_H

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

private slots:
    void onNewConnection();
    void onReadyRead();
    void onDisConnected();
    void on_pbEnvoyer_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *serveur;
    QTcpSocket *sock;
    QList<QTcpSocket *> listeClients;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serveur = new QTcpServer(this);
    connect(serveur,SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    serveur->listen(QHostAddress::Any, 2222);
}

MainWindow::~MainWindow()
{
    delete serveur;
    delete ui;
}

void MainWindow::onNewConnection()
{
    sock = serveur->nextPendingConnection();
    connect(sock, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(sock, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(sock, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    listeClients.append(sock);
    ui->cbClients->addItem(sock->objectName());
}

void MainWindow::onReadyRead()
{
    ui->teTexte->append(sock->readAll());
}

void MainWindow::onConnected()
{
    ui->teTexte->append("Client connecté ");
}

void MainWindow::onDisConnected()
{
    ui->teTexte->append("Client déconnecté ");
}

void MainWindow::on_pbEnvoyer_clicked()
{

}

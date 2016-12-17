#include "espclient.h"
#include "ui_espclient.h"
#include "QMessageBox"

EspClient::EspClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EspClient)
{
    ui->setupUi(this);

    espSocket = new QTcpSocket(this);
    espJson = new QJsonObject();

    connect(espSocket,SIGNAL(connected()),this,SLOT(on_espConnected()));
    connect(espSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));
}

EspClient::~EspClient()
{
    delete ui;
    delete espSocket;
}

void EspClient::espConnect(QString addr, int port)
{
    espSocket->connectToHost(addr, port);
}

void EspClient::espSendData(char *data)
{
    espSocket->write(data);
}

void EspClient::displayError(QAbstractSocket::SocketError)
{
    ui->buttonConnect->setEnabled(true);
    QMessageBox::information(this, "network error!", espSocket->errorString());
}

void EspClient::on_espConnected()
{
    ui->buttonConnect->setEnabled(false);
}

void EspClient::on_buttonConnect_clicked()
{
    espConnect(ui->lineEditAddress->text(), ui->lineEditPort->text().toInt());
    ui->buttonConnect->setEnabled(false);
}

void EspClient::on_buttonSend_clicked()
{
    QByteArray temp = ui->textEdit->toPlainText().toLatin1();

    espSendData(temp.data());
}

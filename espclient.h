#ifndef ESPCLIENT_H
#define ESPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>

namespace Ui {
class EspClient;
}

class EspClient : public QWidget
{
    Q_OBJECT

public:
    explicit EspClient(QWidget *parent = 0);
    ~EspClient();

private:
    Ui::EspClient *ui;
    QTcpSocket *espSocket;

    QJsonObject *espJson;

    void espConnect(QString addr, int port);
    void espSendData(char *data);

private slots:
    void displayError(QAbstractSocket::SocketError);
    void on_espConnected();
    void on_buttonConnect_clicked();
    void on_buttonSend_clicked();
};

#endif // ESPCLIENT_H

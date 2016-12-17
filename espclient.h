#ifndef ESPCLIENT_H
#define ESPCLIENT_H

#include <QWidget>

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
};

#endif // ESPCLIENT_H

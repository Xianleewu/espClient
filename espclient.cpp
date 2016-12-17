#include "espclient.h"
#include "ui_espclient.h"

EspClient::EspClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EspClient)
{
    ui->setupUi(this);
}

EspClient::~EspClient()
{
    delete ui;
}

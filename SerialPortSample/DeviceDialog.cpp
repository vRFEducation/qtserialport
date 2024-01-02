#include "CommandStruct.h"
#include "DeviceDialog.h"
#include "ui_DeviceDialog.h"

DeviceDialog::DeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceDialog)
{
    ui->setupUi(this);
    connect(&_port, &SerialPort::dataReceived, this, &DeviceDialog::dataReady);
}

DeviceDialog::~DeviceDialog()
{
    delete ui;
}

void DeviceDialog::on_btnConnect_clicked()
{
    _port.connect("COM2");
}


void DeviceDialog::on_btnSend_clicked()
{
    _port.write(ui->lnMessage->text().toUtf8());
}

void DeviceDialog::dataReady(QByteArray data)
{
    ui->lstMessages->addItem("Command Received...");
    CommandStruct command;
    memcpy(reinterpret_cast<char *>(&command), data.data(), data.size());
    if (command.command == 1) {
        ui->lblState->setText("Started...");
    } else if (command.command == 0) {
        ui->lblState->setText("Stopped...");
    } else if(command.command == 2) {
        ui->lblState->setText("change speed...");
        ui->lblSpeed->setNum(command.data);
    }
}


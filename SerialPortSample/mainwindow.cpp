#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadPorts();

//    connect(&_port, &SerialPort::dataReceived, this, &MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadPorts()
{
    foreach (auto &port, QSerialPortInfo::availablePorts()) {
        ui->cmbPorts->addItem(port.portName());
    }
}

void MainWindow::on_btnOpenPort_clicked()
{
//    auto isConnected = _port.connect(ui->cmbPorts->currentText());
    _device = new DeviceController(ui->cmbPorts->currentText());
    auto isConnected = _device->connect();
    if (!isConnected) {
        QMessageBox::critical(this, "Error", "There is a problem connecting to port");
    }
}


void MainWindow::on_btnSend_clicked()
{
//    auto numBytes = _port.write(ui->lnMessage->text().toUtf8());
//    if (numBytes == -1) {
//        QMessageBox::critical(this, "Error", "Something went wrong");
//    }
}

void MainWindow::readData(QByteArray data)
{
//    ui->lstMessages->addItem(QString(data));
}


void MainWindow::on_btnStart_clicked()
{
    _device->start();
}


void MainWindow::on_btnStop_clicked()
{
    _device->stop();
}


void MainWindow::on_btnChangeSpeed_clicked()
{
    _device->changeSpeed(ui->spnSpeed->value());
}


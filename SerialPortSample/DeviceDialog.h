#ifndef DEVICEDIALOG_H
#define DEVICEDIALOG_H

#include <QDialog>
#include "SerialPort.h"

namespace Ui {
class DeviceDialog;
}

class DeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceDialog(QWidget *parent = nullptr);
    ~DeviceDialog();

private slots:
    void on_btnConnect_clicked();

    void on_btnSend_clicked();

    void dataReady(QByteArray);

private:
    Ui::DeviceDialog *ui;
    SerialPort _port;
};

#endif // DEVICEDIALOG_H

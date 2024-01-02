#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include "DeviceController.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnOpenPort_clicked();

    void on_btnSend_clicked();

    void readData(QByteArray data);

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnChangeSpeed_clicked();

private:
    Ui::MainWindow *ui;
    DeviceController *_device;
    void loadPorts();
};
#endif // MAINWINDOW_H

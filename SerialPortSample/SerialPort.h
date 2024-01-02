#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>

class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = nullptr);

    bool connect(QString portName);

    qint64 write(QByteArray data);

    ~SerialPort();
signals:
    void dataReceived(QByteArray b);

private slots:
    void dataReady();

private:
    QSerialPort *_serialPort;

};

#endif // SERIALPORT_H

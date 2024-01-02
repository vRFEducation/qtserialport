#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include "SerialPort.h"
#include "CommandStruct.h"


class DeviceController
{
public:
    DeviceController(QString portName);

    bool connect();

    bool start();

    bool stop();

    bool changeSpeed(quint16 speed);

private:
    SerialPort _port;
    QString _portName;
    CommandStruct _struct;


    quint64 sendCommand();
};

#endif // DEVICECONTROLLER_H

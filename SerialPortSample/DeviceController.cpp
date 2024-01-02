#include "DeviceController.h"

DeviceController::DeviceController(QString portName)
{
    _portName = portName;
}

bool DeviceController::connect()
{
    return _port.connect(_portName);
}

bool DeviceController::start()
{
    _struct.command = 1;
    auto result = sendCommand();
    return result != 0;
}

bool DeviceController::stop()
{
    _struct.command = 0;
    auto result = sendCommand();
    return result != 0;
}


bool DeviceController::changeSpeed(quint16 speed)
{
    _struct.command = 2;
    _struct.data = speed;
    auto result = sendCommand();
    return result != 0;
}

quint64 DeviceController::sendCommand()
{
    QByteArray ba(reinterpret_cast<char *>(&_struct), sizeof(CommandStruct));
    return _port.write(ba);
}

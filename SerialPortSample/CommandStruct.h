#ifndef COMMANDSTRUCT_H
#define COMMANDSTRUCT_H


#include "qglobal.h"
struct CommandStruct
{
    quint8 header[2];
    quint8 command;
    quint8 data;
    quint8 footer[2];
};

#endif // COMMANDSTRUCT_H

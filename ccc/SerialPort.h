#pragma once

#ifndef SERIALPORT_H
#define SERIALPORT_H

constexpr auto ARDUINO_WAIT_TIME = 2000;
constexpr auto MAX_DATA_LENGTH = 255;

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

class SerialPort
{
private:
    HANDLE handler;
    bool connected;
    COMSTAT status;
    DWORD errors;
public:
    SerialPort(const char* portName);
    ~SerialPort();

    int readSerialPort(char* buffer, unsigned int buf_size);
    bool writeSerialPort(char* buffer, unsigned int buf_size);
    bool isConnected();
    void closeSerial();
};

#endif // SERIALPORT_H

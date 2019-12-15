#include <iostream>
#include "SerialPort.h"
#include <stdio.h>
#include <string.h>

using namespace std;

char* portName = "\\\\.\\COM3";

#define MAX_DATA_LENGTH 255

char incomingData[MAX_DATA_LENGTH];

//Control signals for turning on and turning off the led
//Check arduino code
char ledON[] = "ON\n";
char ledOFF[] = "OFF\n";

//Arduino SerialPort object
SerialPort *arduino;

//Blinking Delay
const unsigned int BLINKING_DELAY = 1000;

//If you want to send data then define "SEND" else comment it out
#define SEND

void exampleReceiveData(void)
{
    int readResult = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
    printf("%s", incomingData);
    Sleep(10);
}

void exampleWriteData(unsigned int delayTime)
{
    arduino->writeSerialPort(ledON, MAX_DATA_LENGTH);
    Sleep(delayTime);
    arduino->writeSerialPort(ledOFF, MAX_DATA_LENGTH);
    Sleep(delayTime);
}

void autoConnect(void)
{
    //wait connection
	while (!arduino->isConnected()) {
		Sleep(100);
		arduino = new SerialPort(portName);
	}

    //Checking if arduino is connected or not
	if (arduino->isConnected()) {
		std::cout << "Connection established at port " << portName << endl;
	}

	#ifdef SEND
        while(arduino->isConnected()) exampleWriteData(BLINKING_DELAY);
    #else // SEND
        while(arduino->isConnected()) exampleReceiveData();
    #endif // SEND

    //if the serial connection is lost
	autoConnect();
}

int main()
{
    arduino = new SerialPort(portName);

    if (arduino->isConnected()){

      char input[2];
      input[1] = '\n';
      while(true){

        printf("Nummer: ");
        scanf("%c", &input[0]);
        printf("Eingegebene Nummer: %s", input);
        bool hasWritten = arduino->writeSerialPort(input, MAX_DATA_LENGTH);

        if (hasWritten)
          std::cout << "Data Written Successfully" << std::endl;
        else
          std::cout << "Data was not written" << std::endl;
      }
  }

return 0;
}

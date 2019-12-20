#pragma once
#include "SerialPort.h"
#include "Track.h"
class Train
{
public:
	Train(int id, SerialPort* arduino);
	~Train();

public:
	Track* position;

	int id;
	int enable;
	bool inputA;
	bool inputB;

private:
	SerialPort* arduino;

public:
	void updateTrain();
	void getPosition();
	

private:
	virtual bool sendData(char* input);
	virtual char* recieveData();

};


#include "Train.h"
#include <sstream>


#define MAX_DATA_LENGTH 255

using namespace std;
Train::Train(int id, SerialPort* arduino) {
	this->id = id;
	
	this->enable = 0;
	this->inputA = true;
	this->inputB = false;

	this->arduino = arduino;
}
Train::~Train()
{
}

bool Train::sendData(char* input)
{
	bool hasWritten = false;

	if (arduino->isConnected()) 
		hasWritten = arduino->writeSerialPort(input, MAX_DATA_LENGTH);
	
	return hasWritten;
}

char* Train::recieveData()
{
	char output[MAX_DATA_LENGTH];

	if (arduino->isConnected()) {
		int readResult = arduino->readSerialPort(output, MAX_DATA_LENGTH);
	}
	return output;
}

void Train::updateTrain()
{
	std::string str;
	str.append("T");
	str.append(";");
	str.append(to_string(id));
	str.append(";");
	str.append("U");
	str.append(";");
	str.append(to_string(enable));
	str.append(";");
	str.append(to_string(inputA));
	str.append(";");
	str.append(to_string(inputB));
	str.append(";");
	str.append("\n");


	char* input = new char[str.length() + 1];
	strcpy_s(input, str.length() + 1,str.c_str());

	sendData(input);
	delete[] input;
}

void Train::getPosition()
{
	std::string str;
	str.append("T");
	str.append(";");
	str.append(to_string(id));
	str.append(";");
	str.append("P");
	str.append(";");
	str.append("\n");

	char* input = new char[str.length() + 1];
	strcpy_s(input, str.length() + 1, str.c_str());

	sendData(input);
	delete[] input;

	char* output = recieveData();

	//TODO
	/*
		hier: Track aus Trackliste als Position deklarieren
	*/


}

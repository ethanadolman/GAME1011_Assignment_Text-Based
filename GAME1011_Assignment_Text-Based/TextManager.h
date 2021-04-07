#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TextManager
{
private:
	
	// String arrays
	string Descriptions[20];
	string Responses[20];
	string Endings[5];
	string Riddles[2];
	string Doors[3];

public:

	TextManager();

	// Getters
	string getDescription(int index);
	string getResponse(int index);
	string getEnding(int index);
	string getRiddle(int index);
	string getDoors(int index);
};


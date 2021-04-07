#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TextManager
{
private:

	TextManager();
	void BuildStringArrays();

	// String arrays
	string Descriptions[20];
	string Responses[20];
	string Endings[5];

public:

	// Setters
	void setDescription(int index, string desc);
	void setResponse(int index, string respo);
	void setEndings(int index, string ending);

	// Getters
	string getDescription(int index);
	string getResponse(int index);
	string getEnding(int index);

};


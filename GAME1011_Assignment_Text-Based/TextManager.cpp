#include "TextManager.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TextManager::TextManager()
{
	ifstream textFile;

	textFile.open("InputFile.txt");

	int index = 0;
	int descIndex = 0;
	int responseIndex = 0;
	int endingIndex = 0;
	int riddleIndex = 0;
	int doorIndex = 0;

	if (textFile.fail())
	{
		cout << "EROOOROROROR" << endl;
	}

	while (!textFile.eof())
	{
		textFile >> index;
		if (index == 0)	// Descriptions
		{
			getline(textFile, Descriptions[descIndex]);
			descIndex++;
		}
		else if (index == 1) // Responses
		{
			getline(textFile, Responses[responseIndex]);
			responseIndex++;

		}
		else if (index == 2) // Endings
		{
			getline(textFile, Endings[endingIndex]);
			endingIndex++;
		}
		else if (index == 3) // Endings
		{
			getline(textFile, Riddles[riddleIndex]);
			endingIndex++;
		}
		else if (index == 4) // Endings
		{
			getline(textFile, Doors[doorIndex]);
			endingIndex++;
		}
	}
	textFile.close();
}


string TextManager::getDescription(int index)
{
	return Descriptions[index];
}

string TextManager::getResponse(int index)
{
	return Responses[index];
}

string TextManager::getEnding(int index)
{
	return Endings[index];
}

string TextManager::getRiddle(int index)
{
	return Riddles[index];
}

string TextManager::getDoors(int index)
{
	return Doors[index];
}

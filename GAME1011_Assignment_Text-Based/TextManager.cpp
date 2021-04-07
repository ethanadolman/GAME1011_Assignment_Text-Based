#include "TextManager.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TextManager::TextManager()
{
	BuildStringArrays();
}

void TextManager::BuildStringArrays()
{
	ifstream textFile;

	textFile.open("InputFile.txt");

	int index = 0;
	int descIndex = 0;
	int responseIndex = 0;
	int endingIndex = 0;
	int riddleIndex = 0;
	int doorIndex = 0;
	while (textFile)
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

void TextManager::setDescription(int index, string desc)
{
	Descriptions[index] = desc;
}

void TextManager::setResponse(int index, string respo)
{
	Responses[index] = respo;
}

void TextManager::setEndings(int index, string ending)
{
	Endings[index] = ending;
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

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

	int index;
	int descIndex;
	int responseIndex;
	int endingIndex;
	while (textFile)
	{
		textFile >> index;
		if (index == 0)	// Descriptions
		{
			getline(textFile, Descriptions[descIndex]);
		}
		else if (index == 1) // Responses
		{
			getline(textFile, Responses[responseIndex]);

		}
		else if (index == 2) // Endings
		{
			getline(textFile, Endings[endingIndex]);

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

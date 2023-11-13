#include <iostream>
#include <fstream>
#include <Windows.h>

#include "FileManager.h"

std::string Input(std::string question)
{
	std::string input;
	std::cout << question;
	std::cin >> input;
	return input;
}

int main()
{
	bool read = Input("Read or write? (r/w): ") == "r";
	if (!read)
	{
		float frequency = std::atof(Input("Frequency: ").c_str());
		float duration = std::atof(Input("Duration: ").c_str());

		FileManager::FQ newFQ = { frequency, duration };

		std::string newFilename = Input("New filename (no extension): ");
		newFilename += ".fq";

		FileManager::get().WriteToFile(newFQ, newFilename.c_str());
		return 0;
	}

	std::string filename = Input("Filename: ");

	FileManager::FQ readObject;
	FileManager::get().ReadFromFile(readObject, filename.c_str());

	Beep(readObject.frequency, readObject.duration);

	return 0;
}
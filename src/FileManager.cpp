#include "FileManager.h"

FileManager* FileManager::instance = nullptr;

FileManager::FileManager() {}
FileManager::~FileManager() {}

FileManager& FileManager::get()
{
    if (instance == nullptr)
    {
        instance = new FileManager();
    }
    return *instance;
}

void FileManager::WriteToFile(const FQ& data, const char* filename)
{
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char*>(&data), sizeof(FQ));
        file.close();
    }
    else
    {
        std::cerr << "Error opening file for writing." << std::endl;
    }
}

void FileManager::ReadFromFile(FQ& data, const char* filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        file.read(reinterpret_cast<char*>(&data), sizeof(FQ));
        file.close();
    }
    else
    {
        std::cerr << "Error opening file for reading." << std::endl;
    }
}
#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>

class FileManager
{
public:
    struct FQ
    {
        DWORD frequency;
        DWORD duration;
    };

    static FileManager& get();

    void WriteToFile(const FQ& data, const char* filename);
    void ReadFromFile(FQ& data, const char* filename);

protected:
    FileManager();
    virtual ~FileManager();

private:
    static FileManager* instance;
};
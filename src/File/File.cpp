
#include "File.hpp"

File::File(const std::string &filepath) : _filePath(filepath)
{
    _fileStream.open(_filePath);
}

File::~File()
{
    _fileStream.close();
    _fileStream.clear();
}

bool File::getDataLine(std::string &line)
{
    if (std::getline(_fileStream, line))
        return true;
    return false;
}
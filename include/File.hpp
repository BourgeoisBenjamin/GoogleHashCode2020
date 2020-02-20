
#include <string>
#include <iostream>
#include <fstream>

class File {
    public:
        File(const std::string &filepath);
        ~File();
        bool getDataLine(std::string &line);

    private:
        const std::string &_filePath;
        std::fstream _fileStream;
};

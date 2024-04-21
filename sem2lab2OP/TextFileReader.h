#ifndef TEXTFILEREADER_H
#define TEXTFILEREADER_H

#include <fstream>
#include <string>

class TextFileReader {
private:
    std::ifstream fileStream;
    std::string filename;

public:
    TextFileReader() = default;
    TextFileReader(const std::string& filename);
    bool openFile(const std::string& filename);
    void closeFile();
    std::string getFilename() const;
    bool isOpen() const;
    bool isEndOfFile() const;
    bool getNextLine(std::string& line);
    bool getNextWord(std::string& word);
    TextFileReader(const TextFileReader&) = delete;
    TextFileReader& operator=(const TextFileReader&) = delete;
};

#endif
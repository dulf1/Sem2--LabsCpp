#include "TextFileReader.h"
#include <iostream>

TextFileReader::TextFileReader(const std::string& filename) : filename(filename) {
    fileStream.open(filename);
}

bool TextFileReader::openFile(const std::string& filename) {
    closeFile();
    fileStream.open(filename);
    if (fileStream.is_open()) {
        this->filename = filename;
        return true;
    }
    return false;
}

void TextFileRedader::closeFile() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

std::string TextFileReader::getFilename() const {
    return filename;
}

bool TextFileReader::isOpen() const {
    return fileStream.is_open();
}

bool TextFileReader::isEndOfFile() const {
    return fileStream.eof();
}

bool TextFileReader::getNextLine(std::string& line) {
    if (std::getline(fileStream, line)) {
        return true;
    } else {
        return false;
    }
}

bool TextFileReader::getNextWord(std::string& word) {
    if (fileStream >> word) {
        return true;
    } else {
        return false;
    }
}

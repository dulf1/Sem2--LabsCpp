#include <iostream>
#include "TextFileReader.h"

int main() {
    std::string filename;
    std::cout << "Enter file name to read: ";
    std::getline(std::cin, filename);

    TextFileReader reader(filename);
    if (!reader.isOpen()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::cout << "File opened successfully: " << reader.getFilename() << std::endl;
    std::string choice;
    do {
        std::cout << "Choose an action: \n"
                  << "1 - Read file line by line\n"
                  << "2 - Read file word by word\n"
                  << "3 - Close the file and exit\n"
                  << "Your choice: ";
        std::getline(std::cin, choice);

        if (choice == "1") {
            std::string line;
            while (reader.getNextLine(line)) {
                std::cout << line << std::endl;
            }
            if (reader.isEndOfFile()) {
                std::cout << "End of file reached." << std::endl;
            }
        } else if (choice == "2") {
            std::string word;
            while (reader.getNextWord(word)) {
                std::cout << word << " ";
            }
            if (reader.isEndOfFile()) {
                std::cout << "\nEnd of file reached." << std::endl;
            }
        } else if (choice == "3") {
            reader.closeFile();
            std::cout << "The file is closed. Exit the program." << std::endl;
        } else {
            std::cout << "Invalid input, please try again." << std::endl;
        }
    } while (choice != "3");

    return 0;
}
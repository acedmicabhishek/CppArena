#include <iostream>
#include <fstream> 
#include <string>
#include <vector>


const std::string FILENAME = "file_handling/meow.txt";


void writeToFile() {
    
    
    std::ofstream outFile(FILENAME);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return;
    }

    std::cout << "Writing to file: " << FILENAME << std::endl;
    outFile << "Hello from the C++ program!" << std::endl;
    outFile << "This is the first line." << std::endl;
    outFile << "This is the second line." << std::endl;

    
    std::cout << "Finished writing." << std::endl;
}



void readFromFile() {
    
    std::ifstream inFile(FILENAME);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open the file for reading." << std::endl;
        return;
    }

    std::cout << "\nReading from file: " << FILENAME << std::endl;
    std::string line;
    
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "Finished reading." << std::endl;
}

void appendToFile() {
    
    std::ofstream outFile(FILENAME, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file for appending." << std::endl;
        return;
    }

    std::cout << "\nAppending to file: " << FILENAME << std::endl;
    outFile << "This is an appended line." << std::endl;
    outFile << "Another appended line." << std::endl;
    std::cout << "Finished appending." << std::endl;
}

int main() {
    
    writeToFile();

    
    readFromFile();

    
    appendToFile();
    
    readFromFile();

    return 0;
}
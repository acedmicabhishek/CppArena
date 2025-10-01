#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

void printIntArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void cStyleArrays() {
    std::cout << "\n--- C-style Arrays ---" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    printIntArray(numbers, 5);

    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void stdVector() {
    std::cout << "\n--- std::vector ---" << std::endl;
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    vec.push_back(60);
    
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Element at index 2: " << vec.at(2) << std::endl;
}

void cStyleStrings() {
    std::cout << "\n--- C-style Strings ---" << std::endl;
    char greeting[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    std::cout << greeting << std::endl;

    char farewell[] = "Goodbye";
    std::cout << farewell << std::endl;

    char str1[50] = "Hello";   
    const char* str2 = "World";
    char str3[50];             

    strcpy(str3, str1);        
    strcat(str1, " ");         
    strcat(str1, str2);        

    std::cout << str1 << std::endl;
    std::cout << "Length of str1: " << strlen(str1) << std::endl;
}

void stdString() {
    std::cout << "\n--- std::string ---" << std::endl;
    std::string s1 = "Hello";
    std::string s2 = "World";
    std::string s3 = s1 + " " + s2;
    std::cout << s3 << std::endl;

    std::cout << "Length of s3: " << s3.length() << std::endl;
    std::cout << "Substring: " << s3.substr(6, 5) << std::endl;

    size_t pos = s3.find("World");
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl;
    }

    std::string sentence = "The quick brown fox";
    std::reverse(sentence.begin(), sentence.end());
    std::cout << "Reversed sentence: " << sentence << std::endl;
}

int main() {
    cStyleArrays();
    stdVector();
    cStyleStrings();
    stdString();

    return 0;
}

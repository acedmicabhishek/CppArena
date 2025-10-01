#include <iostream>
#include <string>
#include <vector>

template <typename T>
T add(T a, T b) {
    return a + b;
}


template <typename T, typename U>
void printPair(T first, U second) {
    std::cout << "(" << first << ", " << second << ")" << std::endl;
}



template <typename T>
class Box {
private:
    T content;
public:
    Box(T c) : content(c) {}
    T getContent() const {
        return content;
    }
};


template <typename T>
void print(T value) {
    std::cout << "Generic print: " << value << std::endl;
}


template <>
void print<std::string>(std::string value) {
    std::cout << "Specialized print for string: \"" << value << "\"" << std::endl;
}


template <typename T>
class Container {
public:
    Container(T val) { std::cout << "Generic container for type." << std::endl; }
};

template <>
class Container<char> {
public:
    Container(char val) { std::cout << "Specialized container for char: " << val << std::endl; }
};


int main() {
    std::cout << "--- Function Templates Example ---" << std::endl;
    std::cout << "add(5, 10) = " << add(5, 10) << std::endl;
    std::cout << "add(3.14, 1.618) = " << add(3.14, 1.618) << std::endl;
    std::cout << "add(std::string(\"Hello\"), std::string(\" World\")) = " << add(std::string("Hello"), std::string(" World")) << std::endl;
    
    printPair(10, "apples");
    printPair(3.5, true);

    std::cout << "\n--- Class Templates Example ---" << std::endl;
    Box<int> intBox(123);
    std::cout << "Content of intBox: " << intBox.getContent() << std::endl;

    Box<std::string> stringBox("Generic Programming");
    std::cout << "Content of stringBox: " << stringBox.getContent() << std::endl;

    std::cout << "\n--- Template Specialization Example ---" << std::endl;
    print(100);
    print(6.28);
    print(std::string("A specialized string."));

    Container<int> intContainer(5);
    Container<char> charContainer('X');

    return 0;
}
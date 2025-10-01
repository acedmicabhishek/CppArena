#include <iostream>
#include <stdexcept> 
#include <string>
#include <vector>

double divide(int numerator, int denominator) {
    if (denominator == 0) {
        
        throw "Division by zero condition!";
    }
    return static_cast<double>(numerator) / denominator;
}
void checkValue(int value) {
    if (value < 0) {
        throw std::invalid_argument("Value cannot be negative.");
    }
    if (value > 100) {
        throw std::out_of_range("Value cannot be greater than 100.");
    }
    if (value == 42) {
        throw 42; 
    }
    std::cout << "Value is valid: " << value << std::endl;
}



class MyCustomException : public std::exception {
private:
    std::string message;
public:
    MyCustomException(const std::string& msg) : message(msg) {}

    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void processData(const std::vector<int>& data) {
    if (data.empty()) {
        throw MyCustomException("Data vector cannot be empty.");
    }
    
    std::cout << "Data processed successfully." << std::endl;
}

int main() {
    
    std::cout << "--- Basic Exception Example ---" << std::endl;
    try {
        double result = divide(10, 0);
        std::cout << "This will not be printed. Result: " << result << std::endl;
    } catch (const char* msg) {
        
        std::cerr << "Error caught: " << msg << std::endl;
    }

    
    std::cout << "\n--- Multiple/Standard Exceptions Example ---" << std::endl;
    try {
        checkValue(50);
        checkValue(-5); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught an invalid_argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught an out_of_range: " << e.what() << std::endl;
    }

    
    try {
        checkValue(42); 
    } catch (const std::exception& e) {
        
        std::cerr << "Caught a standard exception: " << e.what() << std::endl;
    } catch (...) { 
        std::cerr << "Caught an unknown exception type!" << std::endl;
    }

    
    std::cout << "\n--- Custom Exception Example ---" << std::endl;
    std::vector<int> myData;
    try {
        processData(myData); 
    } catch (const MyCustomException& e) {
        std::cerr << "Caught a custom exception: " << e.what() << std::endl;
    }

    return 0;
}
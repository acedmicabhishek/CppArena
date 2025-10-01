#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

void greet(std::string name);


void passByValue(int x) {
    x = 99; 
    std::cout << "Inside passByValue, x is: " << x << std::endl;
}



void passByReference(int &x) {
    x = 99; 
    std::cout << "Inside passByReference, x is: " << x << std::endl;
}



void passByPointer(int *x) {
    *x = 99; 
    std::cout << "Inside passByPointer, *x is: " << *x << std::endl;
}

int add(int a, int b) {
    return a + b; 
}

unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1; 
    }
    return n * factorial(n - 1); 
}

void print(int i) {
    std::cout << "Printing an int: " << i << std::endl;
}

void print(double d) {
    std::cout << "Printing a double: " << d << std::endl;
}

void print(std::string s) {
    std::cout << "Printing a string: " << s << std::endl;
}

void showMessage(std::string message = "This is a default message.") {
    std::cout << message << std::endl;
}


inline int square(int x) {
    return x * x;
}


// 8. Lambda Expressions (C++11)
// Anonymous functions that can be defined and used on the fly.
// Syntax: [capture_clause](parameters) -> return_type { body }

void lambdaExample() {
    std::cout << "\n--- Lambda Expressions Example ---" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    
    auto printNumber = [](int n) {
        std::cout << n << " ";
    };

    std::cout << "Numbers: ";
    std::for_each(numbers.begin(), numbers.end(), printNumber);
    std::cout << std::endl;

    
    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    std::cout << "There are " << evenCount << " even numbers." << std::endl;

    
    int factor = 10;
    auto multiplyByFactor = [factor](int n) {
        return n * factor;
    };
    std::cout << "5 multiplied by factor " << factor << " is: " << multiplyByFactor(5) << std::endl;
}


int main() {
    
    greet("Meow");

    
    std::cout << "\n--- Parameter Passing Example ---" << std::endl;
    int val = 10;
    std::cout << "Original val: " << val << std::endl;
    passByValue(val);
    std::cout << "After passByValue, val is: " << val << std::endl;

    val = 10;
    std::cout << "\nOriginal val: " << val << std::endl;
    passByReference(val);
    std::cout << "After passByReference, val is: " << val << std::endl;

    val = 10;
    std::cout << "\nOriginal val: " << val << std::endl;
    passByPointer(&val);
    std::cout << "After passByPointer, val is: " << val << std::endl;

    
    std::cout << "\n--- Return Value Example ---" << std::endl;
    int sum = add(5, 3);
    std::cout << "The sum of 5 and 3 is: " << sum << std::endl;

    
    std::cout << "\n--- Recursion Example ---" << std::endl;
    std::cout << "Factorial of 5 is: " << factorial(5) << std::endl;

    
    std::cout << "\n--- Function Overloading Example ---" << std::endl;
    print(10);
    print(3.14);
    print("Hello C++");

    
    std::cout << "\n--- Default Arguments Example ---" << std::endl;
    showMessage("This is a custom message.");
    showMessage(); 

    
    std::cout << "\n--- Inline Function Example ---" << std::endl;
    std::cout << "The square of 7 is: " << square(7) << std::endl;

    
    lambdaExample();

    return 0;
}


void greet(std::string name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}
#include <iostream>
#include <csetjmp>
#include <exception>
#include <thread>
#include <chrono>
#include <vector>

void gotoExample() {
    std::cout << "--- goto Example ---" << std::endl;
    int i = 0, j = 0;
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            if (i == 2 && j == 3) {
                goto found;
            }
            std::cout << "i: " << i << ", j: " << j << std::endl;
        }
    }
found:
    std::cout << "Found at i: " << i << ", j: " << j << std::endl;
    std::cout << std::endl;
}


jmp_buf jump_buffer;

void function_that_jumps() {
    std::cout << "In function_that_jumps()" << std::endl;
    
    longjmp(jump_buffer, 1);
}

void setjmpLongjmpExample() {
    std::cout << "--- setjmp/longjmp Example ---" << std::endl;
    
    
    if (setjmp(jump_buffer) == 0) {
        std::cout << "Calling function_that_jumps()" << std::endl;
        function_that_jumps();
        std::cout << "This will not be printed." << std::endl;
    } else {
        std::cout << "Returned from a longjmp." << std::endl;
    }
    std::cout << std::endl;
}


void rangeBasedForLoopExample() {
    std::cout << "--- Range-based for loop Example ---" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::cout << "Iterating over a vector:" << std::endl;
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << "Modifying elements in a vector:" << std::endl;
    for (int &number : numbers) {
        number *= 2;
    }

    std::cout << "Vector after modification:" << std::endl;
    for (const int &number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl << std::endl;
}

int main() {
    gotoExample();
    setjmpLongjmpExample();
    rangeBasedForLoopExample();

    return 0;
}
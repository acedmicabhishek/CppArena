#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <map>

// --- Key Features of C++11 and C++14 ---

// C++11 Features

// 1. auto keyword
void autoExample() {
    std::cout << "--- C++11: auto ---" << std::endl;
    auto i = 42;          // i is an int
    auto d = 3.14;        // d is a double
    auto s = "hello";     // s is a const char*
    auto vec = std::vector<int>{1, 2, 3};

    std::cout << "auto deduced types: int, double, const char*, vector<int>" << std::endl;
}

// 2. Range-based for loops
void rangeBasedForExample() {
    std::cout << "\n--- C++11: Range-based for ---" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Iterating through vector: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// 3. Lambda Expressions
void lambdaExample() {
    std::cout << "\n--- C++11: Lambda Expressions ---" << std::endl;
    std::vector<int> numbers = {5, 8, 2, 9, 4};
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b; // Sort in ascending order
    });
    std::cout << "Sorted vector using a lambda: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// 4. Smart Pointers (std::unique_ptr and std::shared_ptr)
void smartPointerExample() {
    std::cout << "\n--- C++11: Smart Pointers ---" << std::endl;
    // unique_ptr for exclusive ownership
    std::unique_ptr<int> p1 = std::make_unique<int>(101);
    std::cout << "unique_ptr value: " << *p1 << std::endl;
    // The memory is automatically deallocated when p1 goes out of scope.

    // shared_ptr for shared ownership
    std::shared_ptr<int> p2 = std::make_shared<int>(202);
    std::shared_ptr<int> p3 = p2;
    std::cout << "shared_ptr value: " << *p2 << ", use count: " << p2.use_count() << std::endl;
    // Memory is deallocated when the last shared_ptr is destroyed.
}

// 5. Move Semantics and Rvalue References
class Buffer {
public:
    Buffer(size_t size) : _size(size), _data(new int[size]) {
        std::cout << "Buffer constructed (regular)." << std::endl;
    }
    // Move constructor
    Buffer(Buffer&& other) noexcept : _size(other._size), _data(other._data) {
        std::cout << "Buffer move-constructed." << std::endl;
        other._size = 0;
        other._data = nullptr;
    }
    ~Buffer() { delete[] _data; }
private:
    size_t _size;
    int* _data;
};

void moveSemanticsExample() {
    std::cout << "\n--- C++11: Move Semantics ---" << std::endl;
    Buffer b1(1000);
    Buffer b2 = std::move(b1); // Efficiently "steals" the resource from b1
}

// C++14 Features

// 1. Generic Lambdas
void genericLambdaExample() {
    std::cout << "\n--- C++14: Generic Lambdas ---" << std::endl;
    auto add = [](auto a, auto b) {
        return a + b;
    };
    std::cout << "Generic lambda add(5, 3): " << add(5, 3) << std::endl;
    std::cout << "Generic lambda add(3.5, 2.1): " << add(3.5, 2.1) << std::endl;
}

// 2. Return Type Deduction for Functions
auto multiply(int a, int b) { // Return type is deduced to be int
    return a * b;
}

void returnTypeDeductionExample() {
    std::cout << "\n--- C++14: Return Type Deduction ---" << std::endl;
    std::cout << "multiply(6, 7): " << multiply(6, 7) << std::endl;
}

// 3. Binary Literals and Digit Separators
void literalAndSeparatorExample() {
    std::cout << "\n--- C++14: Binary Literals & Digit Separators ---" << std::endl;
    int binary_num = 0b11010010;
    long long large_num = 1'000'000'000;
    std::cout << "Binary 11010010 is decimal: " << binary_num << std::endl;
    std::cout << "Large number with separators: " << large_num << std::endl;
}


int main() {
    // C++11
    autoExample();
    rangeBasedForExample();
    lambdaExample();
    smartPointerExample();
    moveSemanticsExample();

    // C++14
    genericLambdaExample();
    returnTypeDeductionExample();
    literalAndSeparatorExample();

    return 0;
}
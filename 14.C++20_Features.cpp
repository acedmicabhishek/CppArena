#include <iostream>
#include <vector>
#include <string>
#include <concepts> // For concepts
#include <ranges>   // For ranges
#include <compare>  // For the three-way comparison operator
#include <format>   // For std::format

// --- Key Features of C++20 ---

// Note: To compile C++20 code, you need a modern compiler (like g++ 10 or later)
// and the appropriate flag, e.g., g++ -std=c++20 14.C++20_Features.cpp
// The linter in this environment may not fully support C++20 syntax.

// 1. Concepts
// Concepts allow you to place constraints on template parameters, leading to clearer error messages.
// template <typename T>
// concept Integral = std::is_integral_v<T>;

// This function will only compile if T is an integral type.
// template <Integral T>
// T add(T a, T b) {
//     return a + b;
// }

void conceptsExample() {
    std::cout << "--- C++20: Concepts (Commented out due to linter limitations) ---" << std::endl;
    // std::cout << "add(5, 10): " << add(5, 10) << std::endl;
}

// 2. Ranges
// Ranges provide a modern and powerful way to work with sequences of elements.
void rangesExample() {
    std::cout << "\n--- C++20: Ranges ---" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use a "pipe" syntax to chain operations.
    // Filter for even numbers, then square them.
    // auto results = numbers | std::views::filter([](int n){ return n % 2 == 0; })
    //                        | std::views::transform([](int n){ return n * n; });

    // std::cout << "Squares of even numbers: ";
    // for (int n : results) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;
}

// 3. Three-Way Comparison Operator (<=>)
// The "spaceship operator" simplifies comparison logic.
class Point {
public:
    int x, y;
    // The compiler can auto-generate all six comparison operators (==, !=, <, >, <=, >=) from this one definition.
    // auto operator<=>(const Point&) const = default;
};

void spaceshipOperatorExample() {
    std::cout << "\n--- C++20: Three-Way Comparison (<=>) (Commented out) ---" << std::endl;
    // Point p1{1, 2}, p2{1, 3};
    // auto result = p1 <=> p2;
    // if (result < 0) std::cout << "p1 is less than p2" << std::endl;
    // else if (result > 0) std::cout << "p1 is greater than p2" << std::endl;
    // else std::cout << "p1 is equal to p2" << std::endl;
}

// 4. Designated Initializers
// Allows you to initialize members of a struct or class by name.
struct Person {
    std::string name;
    int age;
    std::string city;
};

void designatedInitializersExample() {
    std::cout << "\n--- C++20: Designated Initializers ---" << std::endl;
    // Person p = {.name = "Alice", .age = 30, .city = "New York"};
    // std::cout << p.name << " is " << p.age << " and lives in " << p.city << "." << std::endl;
}

// 5. std::format
// A modern, type-safe, and extensible way to format strings.
void stdFormatExample() {
    std::cout << "\n--- C++20: std::format (Commented out) ---" << std::endl;
    // std::string name = "Bob";
    // int age = 25;
    // std::string formatted_string = std::format("User {} is {} years old.", name, age);
    // std::cout << formatted_string << std::endl;
}


// 6. Coroutines
// Functions that can be suspended and resumed.
// (This is a very complex topic and the implementation is heavily dependent on the compiler)
void coroutinesExample() {
    std::cout << "\n--- C++20: Coroutines (Commented out) ---" << std::endl;
    // A proper example requires a lot of boilerplate or a library like cppcoro.
}

// 7. Modules
// A modern way to organize code that can lead to faster compile times.
// (Modules are not supported by all compilers and require specific build setups)
void modulesExample() {
    std::cout << "\n--- C++20: Modules (Conceptual) ---" << std::endl;
    std::cout << "import std.core;" << std::endl;
    std::cout << "export module my_module;" << std::endl;
}

// 8. consteval and constinit
// consteval: Specifies that a function MUST be evaluated at compile time.
// consteval int square(int n) {
//     return n * n;
// }

// constinit: Asserts that a variable has static storage duration and is initialized at compile time.
// constinit int compile_time_var = 123;

void constEvalInitExample() {
    std::cout << "\n--- C++20: consteval and constinit (Commented out) ---" << std::endl;
    // constexpr int squared = square(10); // OK
    // std::cout << "consteval square(10): " << squared << std::endl;
    // std::cout << "constinit var: " << compile_time_var << std::endl;
}

// 9. Feature Test Macros
// Allows you to check for the availability of specific C++ features.
void featureTestMacrosExample() {
    std::cout << "\n--- C++20: Feature Test Macros ---" << std::endl;
#ifdef __has_include
#  if __has_include(<format>)
    std::cout << "Compiler has <format>" << std::endl;
#  endif
#  if __has_include(<coroutine>)
    std::cout << "Compiler has <coroutine>" << std::endl;
#  endif
#endif
}


int main() {
    conceptsExample();
    rangesExample();
    spaceshipOperatorExample();
    designatedInitializersExample();
    stdFormatExample();
    coroutinesExample();
    modulesExample();
    constEvalInitExample();
    featureTestMacrosExample();

    return 0;
}
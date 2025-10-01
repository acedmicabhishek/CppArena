#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <optional>
#include <any>
#include <string_view>

// --- Key Features of C++17 ---

// 1. Structured Bindings
// Allows you to unpack multiple return values or elements from pairs/tuples/structs into separate variables.
void structuredBindingsExample() {
    std::cout << "--- C++17: Structured Bindings ---" << std::endl;
    std::map<std::string, int> user_ages = {{"Alice", 30}, {"Bob", 25}};

    // Unpack map elements directly in the loop
    for (const auto& [name, age] : user_ages) {
        std::cout << name << " is " << age << " years old." << std::endl;
    }
}

// 2. if and switch with initializers
// Allows you to declare and initialize a variable within the scope of an if or switch statement.
void ifWithInitializerExample() {
    std::cout << "\n--- C++17: if with initializer ---" << std::endl;
    std::map<int, std::string> error_codes = {{404, "Not Found"}, {500, "Internal Server Error"}};

    // 'it' is only in scope for the if-else block
    if (auto it = error_codes.find(404); it != error_codes.end()) {
        std::cout << "Found error 404: " << it->second << std::endl;
    } else {
        std::cout << "Error 404 not found." << std::endl;
    }
    // 'it' is not accessible here
}

// 3. std::optional
// Represents a value that may or may not be present. Avoids using special values like -1 or nullptr.
std::optional<int> findValue(const std::vector<int>& data, int value_to_find) {
    for (int val : data) {
        if (val == value_to_find) {
            return val; // Value found, return it
        }
    }
    return std::nullopt; // Value not found
}

void stdOptionalExample() {
    std::cout << "\n--- C++17: std::optional ---" << std::endl;
    std::vector<int> data = {1, 2, 3, 4, 5};
    
    if (auto result = findValue(data, 3); result.has_value()) {
        std::cout << "Found value: " << result.value() << std::endl;
    }
    if (auto result = findValue(data, 99); !result.has_value()) {
        std::cout << "Value 99 was not found." << std::endl;
    }
}

// 4. std::any
// A type-safe container for single values of any type.
void stdAnyExample() {
    std::cout << "\n--- C++17: std::any ---" << std::endl;
    std::any value;

    value = 42;
    std::cout << "any contains an int: " << std::any_cast<int>(value) << std::endl;

    value = std::string("Hello C++17");
    std::cout << "any contains a string: " << std::any_cast<std::string>(value) << std::endl;

    try {
        // This will throw a std::bad_any_cast exception
        std::cout << std::any_cast<double>(value) << std::endl;
    } catch (const std::bad_any_cast& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

// 5. std::string_view
// A non-owning, read-only view of a string. Avoids unnecessary copies and allocations.
void printString(std::string_view sv) {
    std::cout << "Printing a string_view: " << sv << std::endl;
}

void stdStringViewExample() {
    std::cout << "\n--- C++17: std::string_view ---" << std::endl;
    std::string full_string = "The quick brown fox";
    const char* c_string = "jumps over the lazy dog";

    printString(full_string); // No copy of full_string is made
    printString(c_string);    // No allocation for the C-style string

    // Create a view of a substring
    std::string_view fox_view(full_string.c_str() + 16, 3);
    printString(fox_view);
}

int main() {
    structuredBindingsExample();
    ifWithInitializerExample();
    stdOptionalExample();
    stdAnyExample();
    stdStringViewExample();

    return 0;
}
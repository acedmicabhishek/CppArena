#include <iostream>
#include <string>
// #include <print> // Required for std::print (C++23)
// #include <stacktrace> // Required for std::stacktrace (C++23)
#include <type_traits> // For std::is_constant_evaluated

// --- Key Features of C++23 ---

// Note: To compile C++23 code, you need a very modern compiler (like g++ 13 or later)
// and the appropriate flag, e.g., g++ -std=c++23 15.C++23.cpp
// The linter in this environment will likely not support C++23 syntax.

// 1. std::print
// A new, more efficient, and Python-like way to print to standard output.
void stdPrintExample() {
    std::cout << "--- C++23: std::print (Commented out) ---" << std::endl;
    std::string name = "Alice";
    int age = 30;
    // std::print("Hello, {}! You are {} years old.\n", name, age);
    // std::println("This is a new line."); // println adds a newline automatically
}

// 2. std::stacktrace
// Provides a way to capture and query the current call stack.
void g() {
    // std::cout << std::stacktrace::current() << std::endl;
}

void f() {
    g();
}

void stdStacktraceExample() {
    std::cout << "\n--- C++23: std::stacktrace (Commented out) ---" << std::endl;
    // f();
}

// 3. if consteval
// A new compile-time if statement to check if the evaluation is happening at compile time.
constexpr int getValue(int x) {
    // The C++23 'if consteval' feature and the C++20 'std::is_constant_evaluated()'
    // are not supported by the linter. The function body is commented out.
    /*
    if consteval {
        return x * 2;
    } else {
        return x;
    }
    */
   return x; // Return a value to make the function valid.
}

void ifConstevalExample() {
    std::cout << "\n--- C++23: if consteval ---" << std::endl;
    
    // This will likely cause a linter error as 'if consteval' is very new.
    // To see it work, you would need to compile with a C++23 compiler.
    
    // constexpr int compile_time_val = getValue(10); // Evaluated at compile time, result is 20
    // int runtime_val = getValue(10); // Evaluated at runtime, result is 10

    // std::cout << "Compile-time evaluation: " << compile_time_val << std::endl;
    // std::cout << "Runtime evaluation: " << runtime_val << std::endl;
}


int main() {
    stdPrintExample();
    stdStacktraceExample();
    ifConstevalExample();

    std::cout << "\nNote: Most C++23 examples are commented out due to likely" << std::endl;
    std::cout << "lack of support in standard linters and older compilers." << std::endl;

    return 0;
}
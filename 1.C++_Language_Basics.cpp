#include <iostream>
#include <string>
#include <limits>

#define MAX_VALUE 100


namespace MyNamespace {
    int value = 42;
}


class Base {
public:
    virtual ~Base() {} 
};

class Derived : public Base {
public:
    void Print() {
        std::cout << "Derived class" << std::endl;
    }
};

constexpr int getCompileTimeValue() {
    return 2 * 2;
}

int main() {
    
    
    int integerVar{10};
    char charVar{'a'};
    float floatVar{3.14f};
    double doubleVar{3.14159};
    bool boolVar{true};

    auto autoVar = 3.14; 
    using BigInt = long long;
    BigInt bigIntVar = 123456789012345LL;

    std::cout << "--- Variables and Data Types ---" << std::endl;
    std::cout << "integerVar: " << integerVar << std::endl;
    std::cout << "autoVar (double): " << autoVar << std::endl;
    std::cout << "BigInt: " << bigIntVar << std::endl;
    std::cout << std::endl;

    
    
    const double PI = 3.14159;
    constexpr int compileTimeVal = getCompileTimeValue();

    std::cout << "--- Constants ---" << std::endl;
    std::cout << "PI (const): " << PI << std::endl;
    std::cout << "compileTimeVal (constexpr): " << compileTimeVal << std::endl;
    std::cout << "MAX_VALUE (#define): " << MAX_VALUE << std::endl;
    std::cout << std::endl;

    
    
    int _int = 5; 
    std::cout << "--- Keywords and Identifiers ---" << std::endl;
    std::cout << "_int: " << _int << std::endl;
    std::cout << std::endl;

    
    
    std::cout << "--- Input/Output ---" << std::endl;
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!" << std::endl;

    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid input for age." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::cout << "You are " << age << " years old." << std::endl;
    }
    std::cout << std::endl;

    
    
    enum Flags {
        FLAG1 = 1 << 0, 
        FLAG2 = 1 << 1, 
        FLAG3 = 1 << 2, 
    };
    int myFlags = FLAG1 | FLAG3;
    std::cout << "--- Operators ---" << std::endl;
    std::cout << "Flags set: " << myFlags << std::endl;
    if (myFlags & FLAG1) {
        std::cout << "FLAG1 is set" << std::endl;
    }
    if (myFlags & FLAG2) {
        std::cout << "FLAG2 is set" << std::endl;
    }
    std::cout << std::endl;

    
    
    std::cout << "--- Type Casting ---" << std::endl;
    
    double d = 3.14;
    int i = static_cast<int>(d);
    std::cout << "static_cast: " << i << std::endl;

    
    Base* b = new Derived();
    Derived* der = dynamic_cast<Derived*>(b);
    if (der) {
        der->Print();
    }
    delete b;

    
    const int const_val = 10;
    int* non_const_ptr = const_cast<int*>(&const_val);
    *non_const_ptr = 20; 
    std::cout << "const_cast (UB): " << *non_const_ptr << std::endl;

    
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    std::cout << "reinterpret_cast: " << *ch << std::endl;
    delete p;
    std::cout << std::endl;

    
    
    std::cout << "--- Namespaces ---" << std::endl;
    namespace MN = MyNamespace;
    std::cout << "Value from MyNamespace: " << MN::value << std::endl;
    using MyNamespace::value;
    std::cout << "Value using 'using' declaration: " << value << std::endl;

    return 0;
}
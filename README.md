# CppArena

My arena for C++ stuff

### Compiling and Running Code

Use the `make run <number>` command, where `<number>` is the topic number you want to run.

For example, to compile and run `1.Cpp_Language_Basics.cpp`, use the following command:
```bash
make run 1
```

**To compile all files:**
```bash
make all
```

**To clean up all compiled executables:**
```bash
make clean
```

---

# C++ Programming Topics: From Beginner to Advanced

## 1. C++ Language Basics
- [ ] Variables and Data Types (int, char, float, double, bool)
- [ ] Constants (const, constexpr, #define)
- [ ] Keywords and Identifiers
- [ ] Input/Output (iostream: cin, cout, cerr)
- [ ] Operators (Arithmetic, Relational, Logical, Bitwise, Assignment)
- [ ] Type Casting (static_cast, dynamic_cast, const_cast, reinterpret_cast)
- [ ] Namespaces

## 2. Control Flow
- [ ] `if`, `else if`, `else` statements
- [ ] `switch` statement
- [ ] `for`, `while`, `do-while` loops
- [ ] `break`, `continue`, `goto`
- [ ] Range-based for loop (C++11)

## 3. Functions
- [ ] Function Declaration, Definition, and Call
- [ ] Function Parameters and Arguments (Pass by value, reference, pointer)
- [ ] Return Values
- [ ] Recursion
- [ ] Function Overloading
- [ ] Default Arguments
- [ ] Inline Functions
- [ ] Lambda Expressions (C++11)

## 4. Arrays and Strings
- [ ] C-style Arrays
- [ ] `std::vector`
- [ ] `std::array` (C++11)
- [ ] C-style Strings (char arrays)
- [ ] `std::string`
- [ ] String Manipulation

## 5. Pointers and Memory Management
- [ ] Pointers (Address and Dereference Operators)
- [ ] Pointer Arithmetic
- [ ] Pointers and Arrays
- [ ] Pointers and Functions
- [ ] Dynamic Memory Allocation (`new`, `delete`)
- [ ] Smart Pointers (C++11): `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`
- [ ] RAII (Resource Acquisition Is Initialization)

## 6. Object-Oriented Programming (OOP)
- [ ] Classes and Objects
- [ ] Access Specifiers (public, protected, private)
- [ ] Constructors and Destructors
- [ ] `this` pointer
- [ ] Member Functions
- [ ] Static Members
- [ ] Friend Functions and Classes
- [ ] Inheritance (Single, Multiple, Multilevel, Hierarchical, Hybrid)
- [ ] Polymorphism (Compile-time/Static and Runtime/Dynamic)
- [ ] Virtual Functions and Pure Virtual Functions
- [ ] Abstract Classes
- [ ] Operator Overloading

## 7. Advanced OOP Concepts
- [ ] Copy Constructor and Copy Assignment Operator
- [ ] Move Constructor and Move Assignment Operator (C++11)
- [ ] Rule of Three, Five, and Zero
- [ ] Virtual Destructors
- [ ] Diamond Problem and Virtual Inheritance

## 8. Templates and Generic Programming
- [ ] Function Templates
- [ ] Class Templates
- [ ] Template Specialization
- [ ] Variadic Templates (C++11)
- [ ] `auto` and `decltype` (C++11)
- [ ] SFINAE (Substitution Failure Is Not An Error)

## 9. Standard Template Library (STL)
- [ ] Containers (Sequence: vector, deque, list; Associative: set, map; Unordered: unordered_set, unordered_map)
- [ ] Iterators
- [ ] Algorithms (`<algorithm>`)
- [ ] Functors (Function Objects)
- [ ] Adapters (stack, queue, priority_queue)

## 10. Exception Handling
- [ ] `try`, `catch`, `throw`
- [ ] Standard Exception Classes
- [ ] `noexcept` specifier (C++11)

## 11. File Handling
- [ ] File Streams (`fstream`, `ifstream`, `ofstream`)
- [ ] Text and Binary File I/O
- [ ] File Positioning

## 12. C++11 and C++14 Features
- [ ] Move Semantics and Rvalue References
- [ ] Lambda Expressions
- [ ] `nullptr`
- [ ] `constexpr`
- [ ] Initialization (`{}`)
- [ ] Type Inference (`auto`, `decltype`)
- [ ] Range-based `for` loop
- [ ] Smart Pointers
- [ ] Concurrency (`std::thread`, `std::mutex`, `std::atomic`)
- [ ] Tuples (`std::tuple`)
- [ ] Regular Expressions (`<regex>`)
- [ ] Generic Lambdas (C++14)
- [ ] Return Type Deduction for Functions (C++14)

## 13. C++17 Features
- [ ] Structured Bindings
- [ ] `if` and `switch` with initializers
- [ ] `constexpr if`
- [ ] `std::optional`
- [ ] `std::variant`
- [ ] `std::any`
- [ ] `std::string_view`
- [ ] Filesystem Library (`<filesystem>`)
- [ ] Parallel STL Algorithms

## 14. C++20 Features
- [ ] Concepts
- [ ] Ranges
- [ ] Coroutines
- [ ] Modules
- [ ] Three-way comparison (`<=>`)
- [ ] `consteval` and `constinit`
- [ ] Feature Test Macros

## 15. C++23
- [ ] `std::expected` (C++23)
- [ ] `std::mdspan` (C++23)
- [ ] `std::print` (C++23)
- [ ] Pattern Matching (C++27 proposal)
- [ ] Contracts (Re-evaluated for future standards)
- [ ] Reflection (Upcoming)
- [ ] Concurrency and Parallelism Enhancements

## 16. Concurrency and Multithreading
- [ ] `std::thread`
- [ ] Mutexes (`std::mutex`, `std::lock_guard`, `std::unique_lock`)
- [ ] Condition Variables (`std::condition_variable`)
- [ ] Atomics (`std::atomic`)
- [ ] Futures and Promises (`std::future`, `std::promise`)
- [ ] `std::async`

## 17. Networking
- [ ] Sockets (using a library like Boost.Asio or a C-style library)
- [ ] Basic Client/Server
- [ ] Networking TS (C++20/23 and beyond)

## 18. Design Patterns
- [ ] Creational (Singleton, Factory, Builder, Prototype)
- [ ] Structural (Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Proxy)
- [ ] Behavioral (Chain of Responsibility, Command, Interpreter, Iterator, Mediator, Memento, Observer, State, Strategy, Template Method, Visitor)

## 19. Advanced and Specialized Topics
- [ ] Custom Memory Allocators
- [ ] Metaprogramming
- [ ] Interfacing with other languages (C, Python, etc.)
- [ ] Performance Optimization and Profiling
- [ ] Cache-Friendly Data Structures
- [ ] SIMD (Single Instruction, Multiple Data)
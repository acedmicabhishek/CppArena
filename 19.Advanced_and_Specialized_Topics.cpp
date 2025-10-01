#include <iostream>
#include <vector>
#include <memory>
#include <type_traits>
#include <chrono>

// For SIMD example
#include <immintrin.h> 

// --- 1. Custom Memory Allocators ---
// A simple custom allocator that tracks allocations.
template <typename T>
class TrackingAllocator {
public:
    using value_type = T;

    TrackingAllocator() noexcept {}

    template <typename U>
    TrackingAllocator(const TrackingAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n * sizeof(T) << " bytes.\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) noexcept {
        std::cout << "Deallocating " << n * sizeof(T) << " bytes.\n";
        ::operator delete(p);
    }
};

template <typename T, typename U>
bool operator==(const TrackingAllocator<T>&, const TrackingAllocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const TrackingAllocator<T>&, const TrackingAllocator<U>&) { return false; }


// --- 2. Metaprogramming ---
// Example: Compile-time factorial calculation.
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

// Example: Type traits to check if a type is a pointer.
template<typename T>
void check_if_pointer(T val) {
    if constexpr (std::is_pointer_v<T>) {
        std::cout << "This is a pointer type.\n";
    } else {
        std::cout << "This is not a pointer type.\n";
    }
}


// --- 3. Interfacing with other languages ---

// C linkage example
extern "C" {
    int add_in_c(int a, int b) {
        return a + b;
    }
}

// Python interfacing is usually done with libraries like Pybind11 or Boost.Python.
// A conceptual example of what a function to be exposed to Python might look like:
std::string greet_from_cpp() {
    return "Hello from C++!";
}
/*
// With Pybind11, you would have a binding file like this:
#include <pybind11/pybind11.h>
PYBIND11_MODULE(example, m) {
    m.def("greet", &greet_from_cpp, "A function that greets from C++");
}
*/


// --- 4. Performance Optimization and Profiling ---
// A simple function to demonstrate profiling.
void function_to_profile() {
    volatile double result = 0.0;
    for (int i = 0; i < 1000000; ++i) {
        result += i * 3.14159;
    }
}

class Timer {
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}
    ~Timer() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Execution time: " << duration.count() << " microseconds.\n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};


// --- 5. Cache-Friendly Data Structures ---
// Array of Structs (AoS) vs. Struct of Arrays (SoA)
struct PointAoS {
    float x, y, z;
};

struct PointSoA {
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> z;
};

void process_aos(const std::vector<PointAoS>& points) {
    float sum_x = 0;
    for(const auto& p : points) {
        sum_x += p.x;
    }
}

void process_soa(const PointSoA& points) {
    float sum_x = 0;
    for(const auto& x_val : points.x) {
        sum_x += x_val;
    }
}


// --- 6. SIMD (Single Instruction, Multiple Data) ---
// Using AVX intrinsics to add two arrays of floats.
void simd_add(float* a, float* b, float* result, int n) {
    for (int i = 0; i < n; i += 8) {
        __m256 a_vec = _mm256_loadu_ps(&a[i]);
        __m256 b_vec = _mm256_loadu_ps(&b[i]);
        __m256 result_vec = _mm256_add_ps(a_vec, b_vec);
        _mm256_storeu_ps(&result[i], result_vec);
    }
}


int main() {
    // 1. Custom Memory Allocator
    std::cout << "--- Custom Memory Allocator ---\n";
    std::vector<int, TrackingAllocator<int>> vec;
    vec.push_back(10);
    vec.push_back(20);
    std::cout << "\n";

    // 2. Metaprogramming
    std::cout << "--- Metaprogramming ---\n";
    std::cout << "Factorial of 5 is " << Factorial<5>::value << std::endl;
    int a = 5;
    int* p = &a;
    check_if_pointer(a);
    check_if_pointer(p);
    std::cout << "\n";

    // 3. Interfacing with C
    std::cout << "--- Interfacing with C ---\n";
    std::cout << "Calling C function: 3 + 4 = " << add_in_c(3, 4) << std::endl;
    std::cout << "\n";

    // 4. Performance Profiling
    std::cout << "--- Performance Profiling ---\n";
    {
        Timer t;
        function_to_profile();
    }
    std::cout << "\n";

    // 5. Cache-Friendly Data Structures
    std::cout << "--- Cache-Friendly Data Structures ---\n";
    std::cout << "AoS vs SoA is a design choice. SoA is often faster for operations on a single field.\n";
    std::cout << "\n";

    // 6. SIMD
    std::cout << "--- SIMD ---\n";
    const int size = 16;
    alignas(32) float a_simd[size];
    alignas(32) float b_simd[size];
    alignas(32) float result_simd[size];
    for(int i=0; i<size; ++i) {
        a_simd[i] = static_cast<float>(i);
        b_simd[i] = static_cast<float>(i * 2);
    }
    simd_add(a_simd, b_simd, result_simd, size);
    std::cout << "SIMD result: ";
    for(int i=0; i<size; ++i) {
        std::cout << result_simd[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
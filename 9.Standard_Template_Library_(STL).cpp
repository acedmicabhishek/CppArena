#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>


void containerExamples() {
    std::cout << "--- STL Containers ---" << std::endl;

    
    std::cout << "\n-- std::vector --" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    std::cout << "Vector elements: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    
    std::cout << "\n-- std::list --" << std::endl;
    std::list<std::string> str_list = {"apple", "banana"};
    str_list.push_front("orange");
    std::cout << "List elements: ";
    for (const auto& s : str_list) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    
    std::cout << "\n-- std::map --" << std::endl;
    std::map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    std::cout << "Bob's age is: " << ages["Bob"] << std::endl;

    
    std::cout << "\n-- std::set --" << std::endl;
    std::set<int> unique_numbers;
    unique_numbers.insert(10);
    unique_numbers.insert(5);
    unique_numbers.insert(10); 
    std::cout << "Set elements: ";
    for (int n : unique_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}



void iteratorExamples() {
    std::cout << "\n--- STL Iterators ---" << std::endl;
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    std::cout << "Traversing vector with an iterator: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        *it += 5;
    }

    std::cout << "Vector after modification: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}



void algorithmExamples() {
    std::cout << "\n--- STL Algorithms ---" << std::endl;
    std::vector<int> data = {5, 2, 8, 1, 9, 4};

    
    std::sort(data.begin(), data.end());
    std::cout << "Sorted vector: ";
    for (int n : data) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    
    auto it = std::find(data.begin(), data.end(), 8);
    if (it != data.end()) {
        std::cout << "Found 8 in the vector." << std::endl;
    }

    
    std::cout << "Doubling each element: ";
    std::for_each(data.begin(), data.end(), [](int& n){
        n *= 2;
        std::cout << n << " ";
    });
    std::cout << std::endl;
}

int main() {
    containerExamples();
    iteratorExamples();
    algorithmExamples();

    return 0;
}
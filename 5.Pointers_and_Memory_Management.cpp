#include <iostream>
#include <memory> 




void basicPointersExample() {
    std::cout << "--- Basic Pointers Example ---" << std::endl;
    int var = 20;
    int* ptr = &var; 

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Address of var (&var): " << &var << std::endl;
    std::cout << "Value of ptr (address it holds): " << ptr << std::endl;
    std::cout << "Value pointed to by ptr (*ptr): " << *ptr << std::endl;

    *ptr = 30; 
    std::cout << "New value of var: " << var << std::endl;
    std::cout << std::endl;
}


void dynamicMemoryExample() {
    std::cout << "--- Dynamic Memory Example (new/delete) ---" << std::endl;
    
    
    int* p_int = new int(101);
    std::cout << "Dynamically allocated int: " << *p_int << std::endl;
    delete p_int; 
    p_int = nullptr; 

    
    int* p_arr = new int;
    for (int i = 0; i < 5; ++i) {
        p_arr[i] = i * 10;
    }
    std::cout << "Dynamically allocated array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << p_arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] p_arr; 
    p_arr = nullptr;
    std::cout << std::endl;
}




void uniquePtrExample() {
    std::cout << "--- std::unique_ptr Example ---" << std::endl;
    
    
    std::unique_ptr<int> u_ptr1 = std::make_unique<int>(25);
    std::cout << "Value from unique_ptr: " << *u_ptr1 << std::endl;

    
    std::unique_ptr<int> u_ptr2 = std::move(u_ptr1);
    std::cout << "Value from moved unique_ptr: " << *u_ptr2 << std::endl;
    

    
    std::cout << std::endl;
}


struct MyClass {
    MyClass() { std::cout << "MyClass Constructed." << std::endl; }
    ~MyClass() { std::cout << "MyClass Destructed." << std::endl; }
};

void sharedPtrExample() {
    std::cout << "--- std::shared_ptr Example ---" << std::endl;
    
    std::shared_ptr<MyClass> s_ptr1;
    
    {
        std::shared_ptr<MyClass> s_ptr2 = std::make_shared<MyClass>();
        std::cout << "Use count: " << s_ptr2.use_count() << std::endl; 
        s_ptr1 = s_ptr2; 
        std::cout << "Use count: " << s_ptr2.use_count() << std::endl; 
    } 

    std::cout << "Use count after inner scope: " << s_ptr1.use_count() << std::endl; 
    std::cout << std::endl;
} 



void weakPtrExample() {
    std::cout << "--- std::weak_ptr Example ---" << std::endl;
    std::weak_ptr<int> w_ptr;
    {
        auto s_ptr = std::make_shared<int>(42);
        w_ptr = s_ptr; 

        if (auto locked_ptr = w_ptr.lock()) { 
            std::cout << "Object is alive. Value: " << *locked_ptr << std::endl;
        } else {
            std::cout << "Object is no longer alive." << std::endl;
        }
    } 

    if (w_ptr.expired()) {
        std::cout << "The weak_ptr has expired." << std::endl;
    }
    std::cout << std::endl;
}


int main() {
    basicPointersExample();
    dynamicMemoryExample();
    uniquePtrExample();
    sharedPtrExample();
    weakPtrExample();

    return 0;
}
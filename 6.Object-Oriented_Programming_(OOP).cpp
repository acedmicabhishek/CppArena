#include <iostream>
#include <string>

class Animal {
private: 
    std::string name;

public: 
    
    Animal(std::string n) : name(n) {
        std::cout << "Animal named " << name << " created." << std::endl;
    }

    
    virtual ~Animal() {
        std::cout << "Animal named " << name << " destroyed." << std::endl;
    }

    
    std::string getName() const {
        return name;
    }

    
    
    
    virtual void makeSound() const {
        std::cout << name << " makes a generic sound." << std::endl;
    }
};




class Dog : public Animal {
public:
    
    Dog(std::string n) : Animal(n) {}

    
    void makeSound() const override {
        std::cout << getName() << " says: Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(std::string n) : Animal(n) {}

    
    void makeSound() const override {
        std::cout << getName() << " says: Meow!" << std::endl;
    }
};



void animalSound(const Animal* animal) {
    animal->makeSound();
}

int main() {
    std::cout << "--- Creating Objects ---" << std::endl;
    
    Dog myDog("Buddy");
    Cat myCat("Whiskers");
    
    std::cout << "\n--- Calling Methods ---" << std::endl;
    myDog.makeSound();
    myCat.makeSound();

    std::cout << "\n--- Demonstrating Polymorphism ---" << std::endl;
    Animal* genericAnimal = new Dog("Generic Dog");
    
    animalSound(&myDog);
    animalSound(&myCat);
    animalSound(genericAnimal);

    delete genericAnimal;

    std::cout << "\n--- Objects going out of scope ---" << std::endl;
    return 0;
}
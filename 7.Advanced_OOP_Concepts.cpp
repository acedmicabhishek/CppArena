#include <iostream>
#include <string>

class Shape {
public:
    virtual double getArea() const = 0; 
    virtual ~Shape() {} 
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};


class Engine {
public:
    void start() { std::cout << "Engine started." << std::endl; }
};

class Radio {
public:
    void playMusic() { std::cout << "Playing music." << std::endl; }
};


class Car : public Engine, public Radio {};


class PoweredDevice {
public:
    PoweredDevice() { std::cout << "PoweredDevice constructor" << std::endl; }
    void powerOn() { std::cout << "Device powered on." << std::endl; }
};


class Scanner : virtual public PoweredDevice {
public:
    void scan() { std::cout << "Scanning document." << std::endl; }
};

class Printer : virtual public PoweredDevice {
public:
    void print() { std::cout << "Printing document." << std::endl; }
};


class Copier : public Scanner, public Printer {};


class MyClass {
private:
    int secretValue;
public:
    MyClass() : secretValue(42) {}
    
    friend void showSecret(const MyClass& obj);
};


void showSecret(const MyClass& obj) {
    
    std::cout << "The secret value is: " << obj.secretValue << std::endl;
}


class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    std::cout << "--- Abstract Class Example ---" << std::endl;
    Circle c(5.0);
    std::cout << "Area of circle: " << c.getArea() << std::endl;

    std::cout << "\n--- Multiple Inheritance Example ---" << std::endl;
    Car myCar;
    myCar.start();
    myCar.playMusic();

    std::cout << "\n--- Virtual Inheritance (Diamond Problem) Example ---" << std::endl;
    Copier myCopier;
    myCopier.powerOn(); 
    myCopier.scan();
    myCopier.print();

    std::cout << "\n--- Friend Function Example ---" << std::endl;
    MyClass obj;
    showSecret(obj);

    std::cout << "\n--- Operator Overloading Example ---" << std::endl;
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    return 0;
}
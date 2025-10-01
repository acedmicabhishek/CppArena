#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>

// --- Creational Patterns ---

// 1. Singleton
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    void showMessage() {
        std::cout << "Hello from Singleton!\n";
    }
    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;
private:
    Singleton() {}
};

// 2. Factory Method
class Product {
public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};

class ConcreteProductA : public Product {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteProductA}";
    }
};

class ConcreteProductB : public Product {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteProductB}";
    }
};

class Creator {
public:
    virtual ~Creator(){};
    virtual Product* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        Product* product = this->FactoryMethod();
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

class ConcreteCreatorA : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConcreteProductB();
    }
};


// 3. Builder
class Car {
public:
    std::string engine;
    std::string body;
    int seats;

    void specifications() const {
        std::cout << "Car specs: Engine=" << engine << ", Body=" << body << ", Seats=" << seats << std::endl;
    }
};

class CarBuilder {
public:
    virtual ~CarBuilder() {}
    virtual void buildEngine() = 0;
    virtual void buildBody() = 0;
    virtual void buildSeats() = 0;
    virtual Car* getCar() = 0;
};

class SportsCarBuilder : public CarBuilder {
private:
    Car* car;
public:
    SportsCarBuilder() { car = new Car(); }
    ~SportsCarBuilder() { delete car; }
    void buildEngine() override { car->engine = "Sports Engine"; }
    void buildBody() override { car->body = "Sports Body"; }
    void buildSeats() override { car->seats = 2; }
    Car* getCar() override { return car; }
};

class Director {
public:
    void setBuilder(CarBuilder* b) { builder = b; }
    void constructCar() {
        builder->buildEngine();
        builder->buildBody();
        builder->buildSeats();
    }
private:
    CarBuilder* builder;
};

// 4. Prototype
class Prototype {
public:
    virtual ~Prototype() {}
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void whoAmI() const = 0;
};

class ConcretePrototype1 : public Prototype {
public:
    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype1>(*this);
    }
    void whoAmI() const override {
        std::cout << "I am ConcretePrototype1\n";
    }
};

// --- Structural Patterns ---

// 5. Adapter
class Target {
public:
    virtual ~Target() = default;
    virtual std::string Request() const {
        return "Target: The default target's behavior.";
    }
};

class Adaptee {
public:
    std::string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter : public Target {
private:
    Adaptee *adaptee_;
public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    std::string Request() const override {
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

// 6. Decorator
class Component {
 public:
  virtual ~Component() {}
  virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component {
 public:
  std::string Operation() const override {
    return "ConcreteComponent";
  }
};

class Decorator : public Component {
 protected:
  Component* component_;

 public:
  Decorator(Component* component) : component_(component) {
  }
  std::string Operation() const override {
    return this->component_->Operation();
  }
};

class ConcreteDecoratorA : public Decorator {
 public:
  ConcreteDecoratorA(Component* component) : Decorator(component) {
  }
  std::string Operation() const override {
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
  }
};

// --- Behavioral Patterns ---

// 7. Strategy
class Strategy {
public:
    virtual ~Strategy() {}
    virtual std::string doAlgorithm(const std::vector<std::string> &data) const = 0;
};

class Context {
private:
    std::unique_ptr<Strategy> strategy_;
public:
    explicit Context(std::unique_ptr<Strategy> &&strategy = {}) : strategy_(std::move(strategy)) {}
    void set_strategy(std::unique_ptr<Strategy> &&strategy) {
        strategy_ = std::move(strategy);
    }
    void doSomeBusinessLogic() const {
        if (strategy_) {
            std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
            std::string result = strategy_->doAlgorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
            std::cout << result << "\n";
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
    }
};

class ConcreteStrategyA : public Strategy {
public:
    std::string doAlgorithm(const std::vector<std::string> &data) const override {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));
        return result;
    }
};

// 8. Observer
class IObserver {
 public:
  virtual ~IObserver(){};
  virtual void Update(const std::string &message_from_subject) = 0;
};

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

class Subject : public ISubject {
 public:
  virtual ~Subject() {
    std::cout << "Goodbye, I was the Subject.\n";
  }

  void Attach(IObserver *observer) override {
    list_observer_.push_back(observer);
  }
  void Detach(IObserver *observer) override {
    list_observer_.erase(std::remove(list_observer_.begin(), list_observer_.end(), observer), list_observer_.end());
  }
  void Notify() override {
    for (IObserver *observer : list_observer_) {
      observer->Update(message_);
    }
  }

  void CreateMessage(std::string message = "Empty") {
    this->message_ = message;
    Notify();
  }

 private:
  std::vector<IObserver *> list_observer_;
  std::string message_;
};

class Observer : public IObserver {
 public:
  Observer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
    this->number_ = Observer::static_number_;
  }
  virtual ~Observer() {
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
  }

  void Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
  }
  void PrintInfo() {
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
  }

 private:
  std::string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

int Observer::static_number_ = 0;


int main() {
    // Singleton
    std::cout << "--- Singleton ---\n";
    Singleton::getInstance().showMessage();
    std::cout << "\n";

    // Factory Method
    std::cout << "--- Factory Method ---\n";
    Creator* creator1 = new ConcreteCreatorA();
    std::cout << creator1->SomeOperation() << std::endl;
    delete creator1;
    std::cout << "\n";

    // Builder
    std::cout << "--- Builder ---\n";
    Director director;
    SportsCarBuilder scb;
    director.setBuilder(&scb);
    director.constructCar();
    Car* car = scb.getCar();
    car->specifications();
    std::cout << "\n";

    // Prototype
    std::cout << "--- Prototype ---\n";
    auto proto1 = std::make_unique<ConcretePrototype1>();
    auto clone1 = proto1->clone();
    proto1->whoAmI();
    clone1->whoAmI();
    std::cout << "\n";

    // Adapter
    std::cout << "--- Adapter ---\n";
    Adaptee *adaptee = new Adaptee;
    Adapter *adapter = new Adapter(adaptee);
    std::cout << adapter->Request() << std::endl;
    delete adaptee;
    delete adapter;
    std::cout << "\n";

    // Decorator
    std::cout << "--- Decorator ---\n";
    Component* simple = new ConcreteComponent;
    std::cout << "Client: I've got a simple component:\n";
    std::cout << "RESULT: " << simple->Operation();
    Component* decorator1 = new ConcreteDecoratorA(simple);
    std::cout << "\nClient: Now I've got a decorated component:\n";
    std::cout << "RESULT: " << decorator1->Operation() << "\n";
    delete simple;
    delete decorator1;
    std::cout << "\n";

    // Strategy
    std::cout << "--- Strategy ---\n";
    Context context(std::make_unique<ConcreteStrategyA>());
    context.doSomeBusinessLogic();
    std::cout << "\n";

    // Observer
    std::cout << "--- Observer ---\n";
    Subject *subject = new Subject;
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    subject->CreateMessage("Hello World! :D");
    observer2->RemoveMeFromTheList();
    subject->CreateMessage("The weather is hot today! ;)");
    delete observer1;
    delete observer2;
    delete subject;

    return 0;
}
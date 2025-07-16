#include<iostream>
#include<string>

using namespace std;

class Coffee {
    public: //In C++, if you don’t write public:, the members in a class are private by default.
    virtual string getDescription() = 0;
    virtual double getCost() = 0;

    virtual ~Coffee() = default;
};

class SimpleCoffee : public Coffee {

    public:
    string getDescription() override {
        return "Simple Coffee";
    }

    double getCost() override {
        return 5.5;
    }

};

// Without this, every decorator (Milk, Sugar) will repeat the exact constructor logic and hold a pointer to Coffee.
class CoffeeDecorator : public Coffee {
    protected:
    Coffee* coffee;

    public:
        CoffeeDecorator(Coffee* c) : coffee(c) {}
};

class Milk : public CoffeeDecorator {

    public:
    Milk(Coffee* c) : CoffeeDecorator(c) {}

    string getDescription() override {
        return coffee->getDescription() + " + Milk";
    }

    double getCost() override {
        return coffee->getCost() + 1.5;
    }

};

class Sugar : public CoffeeDecorator {
    public:

    Sugar(Coffee* c) : CoffeeDecorator(c) {}

    string getDescription() override {
        return coffee->getDescription() + " + Sugar";
    }

    double getCost() override {
        return coffee->getCost() + 1.0;
    }

};

int main() {
    Coffee* myCoffee = new SimpleCoffee();
    cout<< "order -> " << myCoffee->getDescription() << endl;

    cout<< "cost -> " << myCoffee->getCost() << endl;

    myCoffee = new Milk(myCoffee);

    cout<< "order -> " << myCoffee->getDescription() << endl;

    cout<< "cost -> " << myCoffee->getCost() << endl;

    myCoffee = new Sugar(myCoffee);

    cout<< "order -> " << myCoffee->getDescription() << endl;

    cout<< "cost -> " << myCoffee->getCost() << endl;
    return 0;
}
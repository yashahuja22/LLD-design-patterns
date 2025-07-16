// Prototype Design Pattern Example in C++
#include <iostream>

using namespace std;

class Shape {
    public:
    virtual Shape* clone() const = 0; // Pure virtual function for cloning
    virtual void draw() const = 0; // Pure virtual function for drawing the shape
    virtual void setColor(string color) = 0; // Pure virtual function for drawing the shape
    virtual ~Shape() = default; // Virtual destructor for proper cleanup
};

class Circle : public Shape {
    private:
    string color;

    public:
    Circle(string color) {
        this->color = color;
    }

    Circle* clone() const override {
        return new Circle(this->color); // Create a new Circle object by copying the current object
    }

    void draw() const override {
        cout << "Drawing a " << color << " Circle." << endl; // Implementation of drawing a circle
    }

    void setColor(string newColor) override {
        color = newColor; // Set the color of the circle
    }
};

class Client {
    private:
    Shape* shapePrototype; // Pointer to the prototype shape

    public:
    Client(Shape* prototype) : shapePrototype(prototype) {}

    Shape* createShape() {
        return shapePrototype->clone(); // Clone the prototype to create a new shape
    }
};

int main() {
    Shape* circlePrototype = new Circle("Red"); // Create a prototype Circle object
    Client client(circlePrototype); // Create a client with the prototype

    Shape* newCircle = client.createShape(); // Create a new Circle by cloning the prototype
    newCircle->draw(); // Draw the new Circle

    Shape* anotherCircle = client.createShape(); // Create another Circle by cloning the prototype
    anotherCircle->setColor("Blue"); // Change the color of the new Circle
    anotherCircle->draw(); // Draw the modified Circle
    return 0;
}
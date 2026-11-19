#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;

// Common interface for all products.
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Rectangle." << endl;
    }
};

// Factory creates the requested Shape object.
class ShapeFactory {
public:
    static unique_ptr<Shape> createShape(const string& type) {
        if (type == "circle" || type == "Circle") {
            return make_unique<Circle>();
        }

        if (type == "rectangle" || type == "Rectangle") {
            return make_unique<Rectangle>();
        }

        throw invalid_argument("Unknown shape type: " + type);
    }
};

int main() {
    cout << "Factory Design Pattern Demonstration" << endl;
    cout << "-------------------------------------" << endl;

    try {
        // Two separate factory requests create two different objects.
        unique_ptr<Shape> firstShape = ShapeFactory::createShape("circle");
        unique_ptr<Shape> secondShape = ShapeFactory::createShape("rectangle");

        cout << "Request 1: circle" << endl;
        firstShape->draw();

        cout << "Request 2: rectangle" << endl;
        secondShape->draw();
    } catch (const invalid_argument& error) {
        cerr << "Error: " << error.what() << endl;
        return 1;
    }

    return 0;
}

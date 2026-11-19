#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Abstract base class
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function

    virtual ~Shape() = default; // Virtual destructor
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        const double PI = 3.141592653589793;
        return PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    // Shape is abstract, so this is not allowed:
    // Shape shape;

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(8.0, 3.0);

    // Derived objects are accessed through base-class pointers.
    vector<Shape*> shapes = {&circle, &rectangle, &triangle};
    const vector<string> names = {"Circle", "Rectangle", "Triangle"};

    cout << fixed << setprecision(2);
    cout << "Runtime Polymorphism - Shape Areas\n";
    cout << "-----------------------------------\n";

    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << names[i] << " area: " << shapes[i]->area() << endl;
    }

    return 0;
}

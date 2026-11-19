#include <iostream>
#include <iomanip>

using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0)
        : real(r), imaginary(i) {}

    // Function overloading: same function name, different parameter lists.
    ComplexNumber add(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real,
                             imaginary + other.imaginary);
    }

    void display() const {
        cout << real;
        if (imaginary >= 0) {
            cout << " + " << imaginary << "i";
        } else {
            cout << " - " << -imaginary << "i";
        }
    }

    // Operator overloading: define how + combines two ComplexNumber objects.
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real,
                             imaginary + other.imaginary);
    }
};

// Two overloaded free functions with different parameter types.
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    cout << fixed << setprecision(2);

    cout << "Compile-Time Polymorphism: Function and Operator Overloading\n";
    cout << "-------------------------------------------------------------\n";

    cout << "add(10, 20) = " << add(10, 20) << endl;
    cout << "add(5.5, 2.3) = " << add(5.5, 2.3) << endl;

    ComplexNumber first(4.0, 3.0);
    ComplexNumber second(2.0, 5.0);

    cout << "\nFirst complex number: ";
    first.display();

    cout << "\nSecond complex number: ";
    second.display();

    ComplexNumber result = first + second;

    cout << "\n\nResult of first + second: ";
    result.display();

    // The named member function produces the same sum.
    ComplexNumber functionResult = first.add(second);
    cout << "\nResult using add() member function: ";
    functionResult.display();

    cout << endl;
    return 0;
}

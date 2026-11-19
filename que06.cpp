
#include <iostream>
#include <string>
using namespace std;

class Complex {
    int real, image;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        image = i;
    }

    void display() {
        cout << real << " + " << image << "i" << endl;
    }

    void display(string msg) {
        cout << msg;
        cout << real << " + " << image << "i" << endl;
    }

    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.image = image + c.image;
        return temp;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(2, 5);
    c1.display("First Complex Number: ");
    Complex c3 = c2 + c1;
    cout << "Addition: ";
    c3.display();

    return 0;
}

//1. Set up a GitHub repository. Write a C++ program to demonstrate data types, constants, variables, operators, and I/O. Commit with a meaningful message.

#include<iostream>
#include <string>
using namespace std;
int main(){

 // 1. Variables and Data Types
    int age = 18;
    float number = 5.2;
    double marks = 89.75;
    char grade = 'A';
    bool isStudent = true;
    string name = "Anushka";

    // 2. Constant
    const float PI = 3.14159;

    // 3. Input and Output
    cout << "Enter your name: ";
    cin >> name;

    // 4. Operators
    int a = 20, b = 10;
    // Arithmetic operators 
    cout << "\n--- Arithmetic Operators ---" << endl;
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Modulus: " << a % b << endl;
    // Relational operators
    cout << "\n--- Relational Operators ---" << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a == b: " << (a == b) << endl;
    // Logical operatores 
    cout << "\n--- Logical Operators ---" << endl;
    cout << "(a > b && b > 0): " << (a > b && b > 0) << endl;
    cout << "(a < b || b > 0): " << (a < b || b > 0) << endl;

return 0;
}


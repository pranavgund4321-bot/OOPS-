
#include <iostream>
using namespace std;

class Student {
    int* marks;

public:

    // 1. Default Constructor
    Student() {
        marks = new int;
        *marks = 0;
        cout << "Default Constructor Called" << endl;
    }

    // 2. Parameterized Constructor
    Student(int m) {
        marks = new int;
        *marks = m;
        cout << "Parameterized Constructor Called" << endl;
    }

    // 3. Copy Constructor
    Student(Student &s) {
        marks = new int;
        *marks = *s.marks;
        cout << "Copy Constructor Called" << endl;
    }

    // 4. Move Constructor
    Student(Student &&s) {
        marks = s.marks;
        s.marks = NULL;
        cout << "Move Constructor Called" << endl;
    }

    // 5. Copy Assignment Operator
    Student& operator=(Student &s) {
        if (this != &s) {
            *marks = *s.marks;
        }
        return *this;
    }

    // 6. Move Assignment Operator
    Student& operator=(Student &&s) {
        if (this != &s) {
            delete marks;
            marks = s.marks;
            s.marks = NULL;
        }
        return *this;
    }

    // 7. Destructor
    ~Student() {
        delete marks;
        cout << "Destructor Called" << endl;
    }

    void display() {
        if (marks != NULL)
            cout << "Marks: " << *marks << endl;
        else
            cout << "No marks available" << endl;
    }
};

int main() {

    Student s1;
    Student s2(90);
    Student s3(s2);
    Student s4(static_cast<Student&&>(s2));

    cout << "\nStudent Details:" << endl;
    s1.display();
    s2.display();
    s3.display();
    s4.display();

    return 0;
}


#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    void get_personal_details() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void display_person_data() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class Student : public Person {
protected:
    int roll_no;
    string course;
public:
    void get_student_details() {
        get_personal_details();
        cout << "Enter Roll No: ";
        cin >> roll_no;
        cout << "Enter Course Name: ";
        cin >> course;
    }

    void display_student_data() {
        display_person_data();
        cout << "Roll No: " << roll_no << endl;
        cout << "Course: " << course << endl;
    }
};
class GraduateStudent : public Student {
private:
    string specialization;
    int marks;

public:
    void get_graduate_student_details() {
        get_student_details();
        cout << "Enter Specialization: ";
        cin >> specialization;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display_graduate_student_data() {
        display_student_data();
        cout << "Specialization: " << specialization << endl;
        cout << "Marks: " << marks << endl;
        if (marks >= 45) {
            cout << "Graduated" << endl;
        }
        else {
            cout << "Not Graduated" << endl;
        }
    }
};

int main() {
    GraduateStudent s1;
    s1.get_graduate_student_details();
    cout << "\nDisplaying Details:" << endl;
    s1.display_graduate_student_data();
    return 0;
}

#include <iostream>
#include <string>
#include <utility>

using namespace std;

// Base class: common details shared by all people in the university.
class Person {
protected:
    string name;
    int age;

public:
    Person(string personName, int personAge)
        : name(std::move(personName)), age(personAge) {}

    void displayPerson() const {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
    }
};

// Single inheritance: Student inherits the public/protected
// behaviour and data of Person.
class Student : public Person {
protected:
    string studentId;
    string course;

public:
    Student(string personName, int personAge,
            string id, string courseName)
        : Person(std::move(personName), personAge),
          studentId(std::move(id)),
          course(std::move(courseName)) {}

    void displayStudent() const {
        displayPerson();
        cout << "Student ID: " << studentId << '\n';
        cout << "Course: " << course << '\n';
    }
};

// Multilevel inheritance: GraduateStudent inherits from Student,
// which already inherits from Person.
class GraduateStudent : public Student {
private:
    string researchTopic;
    string supervisor;

public:
    GraduateStudent(string personName, int personAge,
                    string id, string courseName,
                    string topic, string supervisorName)
        : Student(std::move(personName), personAge,
                  std::move(id), std::move(courseName)),
          researchTopic(std::move(topic)),
          supervisor(std::move(supervisorName)) {}

    void displayGraduateStudent() const {
        displayStudent();
        cout << "Research Topic: " << researchTopic << '\n';
        cout << "Supervisor: " << supervisor << '\n';
    }
};

int main() {
    cout << "UNIVERSITY MANAGEMENT - INHERITANCE DEMO\n";

    cout << "\n--- Student (Single Inheritance) ---\n";
    Student student("Aarav Sharma", 20, "STU2026001",
                    "B.Tech Computer Science");
    student.displayStudent();

    cout << "\n--- Graduate Student (Multilevel Inheritance) ---\n";
    GraduateStudent graduate("Diya Patel", 24, "PG2026007",
                             "M.Tech Computer Science",
                             "Distributed Data Processing",
                             "Dr. Meera Kulkarni");
    graduate.displayGraduateStudent();

    cout << "\nInheritance demonstration completed.\n";
    return 0;
}

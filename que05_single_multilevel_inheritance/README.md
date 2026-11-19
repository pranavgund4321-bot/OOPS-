# Practical 05 – Single and Multilevel Inheritance

## Aim
To understand base and derived classes and how data and behaviour can be reused through inheritance.

## Question
Implement a university-management example using the inheritance chain:

`Person → Student → GraduateStudent`

## Class design

- **Person (base class):** stores common information: `name` and `age`. Its `displayPerson()` function displays these details.
- **Student (derived from Person):** adds `studentId` and `course`. It reuses `displayPerson()` and adds `displayStudent()`.
- **GraduateStudent (derived from Student):** adds `researchTopic` and `supervisor`. It can access the inherited student and person behaviour, and adds `displayGraduateStudent()`.

## Inheritance diagram

```text
        Person
           |
           |  Single inheritance
           v
         Student
           |
           |  Multilevel inheritance
           v
    GraduateStudent
```

## Inherited member access

| Class | Members available |
|---|---|
| `Person` | Its own `name`, `age`, and `displayPerson()` |
| `Student` | Inherits protected `name` and `age`; can call public `displayPerson()`; adds student ID, course and `displayStudent()` |
| `GraduateStudent` | Inherits accessible Person and Student members; can call `displayPerson()` and `displayStudent()`; adds research topic, supervisor and its display function |

The data members are `protected` where derived classes need access. The display functions are `public`, so they can be called from `main()`. Private members of a base class would not be directly accessible in a derived class.

## Build and run

### Windows (MinGW g++)
```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
.\main.exe
```

### Ubuntu / WSL
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

## Sample objects
1. A `Student` object demonstrates single inheritance from `Person`.
2. A `GraduateStudent` object demonstrates multilevel inheritance through `Student` and `Person`.

## Result
The university-management example demonstrates single inheritance (`Person → Student`) and multilevel inheritance (`Person → Student → GraduateStudent`). Derived classes reuse accessible data and functions from their base classes.

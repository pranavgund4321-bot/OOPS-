# Practical 08 – Factory Design Pattern

## Question
Implement either the Singleton or Factory design pattern in C++ and discuss its use case and trade-offs.

## Aim
To practise applying a common object-creation design pattern instead of creating objects without a clear structure.

## Pattern selected: Factory

The **Factory Design Pattern** is selected because the program needs to create different types of shapes based on a requested type. The calling code asks the factory for a shape and does not need to know the concrete class's construction details.

## Class / object diagram

```text
                  +----------------------+
                  |      ShapeFactory    |
                  +----------------------+
                  | + createShape(type)  |
                  +----------+-----------+
                             |
                 creates one of the following
                      /             \
                     v               v
              +-----------+   +-------------+
              |  Circle   |   |  Rectangle  |
              +-----------+   +-------------+
              | + draw()  |   | + draw()    |
              +-----+-----+   +------+------+
                    \                /
                     \              /
                      v            v
                   +------------------+
                   |      Shape       |
                   +------------------+
                   | + draw() = 0     |
                   +------------------+
                       common interface
```

## How the program works

1. The abstract `Shape` class defines a common `draw()` interface.
2. `Circle` and `Rectangle` implement the interface.
3. `ShapeFactory::createShape(type)` checks the requested type and creates the matching object.
4. The factory returns a `unique_ptr<Shape>`. This provides automatic object cleanup when the pointer goes out of scope.
5. The program makes two requests: one for a circle and one for a rectangle. Each returned object is used through the common `Shape` interface.

## Flow diagram

```text
        Start
          |
          v
  Request a shape type
          |
          v
  ShapeFactory receives type
          |
          v
     Which type?
       /      \
   circle   rectangle
      |          |
      v          v
 Create       Create
 Circle      Rectangle
      \          /
       \        /
        v      v
     Return Shape pointer
          |
          v
       Call draw()
          |
          v
         End
```

## Use case

A graphics application may need to create different shapes based on user input or a configuration file. The application can request a shape from the factory without directly constructing each concrete shape. The same approach can be used for creating vehicles, notification types, or database connection objects.

## Benefit and trade-off

- **Benefit:** Object-creation logic is kept in one place. Client code depends on the common `Shape` interface rather than directly constructing each concrete class.
- **Trade-off:** The factory adds an extra class and must be updated when new shape types are introduced. For a very small program, this extra structure may be unnecessary.

## Sample output

```text
Factory Design Pattern Demonstration
-------------------------------------
Request 1: circle
Drawing a Circle.
Request 2: rectangle
Drawing a Rectangle.
```

The same output is available in [sample_output.txt](sample_output.txt).

## Compile and run

### Windows PowerShell (with g++)

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
.\main.exe
```

### Ubuntu / WSL

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

## Result

The Factory Design Pattern was implemented successfully. The factory creates Circle and Rectangle objects according to the requested type and returns them through a common base-class interface.

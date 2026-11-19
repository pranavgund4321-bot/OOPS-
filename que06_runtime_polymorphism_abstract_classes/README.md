# Practical 06 – Runtime Polymorphism and Abstract Classes

## Question
Create an abstract `Shape` class and implement `Circle`, `Rectangle` and `Triangle` with an `area()` function.

## Aim
To demonstrate how a base-class interface can be used to call the correct derived-class function at runtime.

## Concepts used

- **Abstract class:** `Shape` is an abstract base class because it declares the pure virtual function `virtual double area() const = 0;`.
- **Pure virtual function:** It specifies an interface that derived classes must implement.
- **Virtual destructor:** `virtual ~Shape() = default;` ensures correct destruction if a derived object is deleted through a base-class pointer.
- **Function overriding:** `Circle`, `Rectangle` and `Triangle` each provide their own `area()` implementation using `override`.
- **Runtime polymorphism:** The program stores pointers to the derived objects as `Shape*` and calls `area()` through those pointers. At runtime, C++ dispatches the call to the correct derived implementation.

## Area formulas

| Shape | Formula | Dimensions used | Calculated area |
|---|---|---|---:|
| Circle | π × radius² | radius = 5 | 78.54 |
| Rectangle | length × width | 4 × 6 | 24.00 |
| Triangle | ½ × base × height | 8 × 3 | 12.00 |

All dimensions are positive and valid.

## Why cannot Shape be instantiated?

A class containing at least one pure virtual function is abstract. It does not provide a complete implementation of the interface, so an object such as `Shape shape;` cannot be created. The commented-out statement in `main.cpp` demonstrates this restriction. Objects of concrete derived classes can be created because they implement `area()`.

## Source code

See [main.cpp](main.cpp).

## Sample output

```text
Runtime Polymorphism - Shape Areas
-----------------------------------
Circle area: 78.54
Rectangle area: 24.00
Triangle area: 12.00
```

The output is also saved in [sample_output.txt](sample_output.txt).

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

The program demonstrates abstraction and runtime polymorphism. Calls made through the `Shape*` base-class interface execute the appropriate `area()` function for Circle, Rectangle and Triangle.

# Practical 07 – Compile-Time Polymorphism: Overloading

## Question
Demonstrate function overloading and operator overloading using a Complex Number class.

## Aim
To understand how C++ selects functions at compile time based on parameters and operator definitions.

## Concepts used

### 1. Function overloading
Function overloading allows multiple functions to have the same name when their parameter lists differ. The compiler selects the matching function based on the arguments supplied.

This program defines:
- `int add(int a, int b)` for integer values.
- `double add(double a, double b)` for decimal values.
- A `ComplexNumber::add(const ComplexNumber&)` member function to add two complex-number objects.

### 2. Operator overloading
The `+` operator is overloaded inside the `ComplexNumber` class. It adds the real parts together and the imaginary parts together, returning a new `ComplexNumber` object.

For example:

```text
(4 + 3i) + (2 + 5i) = 6 + 8i
```

This overload is useful because it lets complex numbers be added with the familiar and readable `+` notation, just like built-in numeric types.

### 3. Difference between the concepts

| Concept | Meaning | When selected |
|---|---|---|
| Function overloading | Same function name with different parameter lists | Compile time, based on arguments |
| Operator overloading | Defines how an operator works with user-defined types | Compile time, based on operand types |
| Runtime polymorphism | A virtual function call resolves to the derived implementation | Runtime, based on the actual object type |

## Sample output

```text
Compile-Time Polymorphism: Function and Operator Overloading
-------------------------------------------------------------
add(10, 20) = 30
add(5.5, 2.3) = 7.80

First complex number: 4.00 + 3.00i
Second complex number: 2.00 + 5.00i

Result of first + second: 6.00 + 8.00i
Result using add() member function: 6.00 + 8.00i
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

The program demonstrates compile-time polymorphism through function overloading and operator overloading. The compiler selects the appropriate `add()` function from its arguments, while the overloaded `+` operator adds two `ComplexNumber` objects.

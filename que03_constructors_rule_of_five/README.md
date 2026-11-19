# Practical 03: Constructors and Rule of Five

## Question
Implement a class that demonstrates default, parameterized, copy and move constructors, and the Rule of Five.

## Aim
To understand object creation, copying, moving and safe management of an owned resource.

## Program overview
The `IntArray` class owns a dynamically allocated integer array. It implements all five special member functions in the Rule of Five:

1. **Destructor:** releases the owned array using `delete[]`.
2. **Copy constructor:** creates a separate allocation and copies each element (deep copy).
3. **Copy assignment operator:** creates a deep copy, handles self-assignment, and then replaces the old allocation.
4. **Move constructor:** transfers the pointer and size to the new object, then leaves the source empty.
5. **Move assignment operator:** releases the destination's old allocation, transfers ownership, and leaves the source empty.

The class also has a default constructor and a parameterized constructor. The program demonstrates copy construction, copy assignment, move construction, move assignment, and that modifying a deep copy does not change the original.

## Compile and run
```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
.\main.exe
```

## Memory checking with Valgrind (Ubuntu / WSL)
```bash
g++ -std=c++17 -g -O0 main.cpp -o main
valgrind --leak-check=full --show-leak-kinds=all ./main
```

A clean run should report no definitely-lost or indirectly-lost bytes and ideally:
`All heap blocks were freed -- no leaks are possible`.

## Alternative: AddressSanitizer
If Valgrind is unavailable, use a compiler/runtime that supports AddressSanitizer:
```bash
g++ -std=c++17 -g -O1 -fsanitize=address -fno-omit-frame-pointer main.cpp -o main_asan
./main_asan
```
Check the full output for AddressSanitizer errors. Leak detection availability depends on the platform and compiler runtime.

## Evidence reminder
The included `memory_check.txt` is a record template with commands, not a claim that a memory checker has already been run. Run Valgrind or AddressSanitizer on your own machine and paste the actual result into that file before submitting.

## Result
The program demonstrates default and parameterized construction, deep copying, move-based ownership transfer, and automatic resource release through the Rule of Five.

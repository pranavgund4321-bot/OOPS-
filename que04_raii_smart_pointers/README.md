# Practical 04 – RAII and Smart Pointers

## Aim
To understand how Resource Acquisition Is Initialization (RAII) ties resource lifetime to object lifetime, and how smart pointers reduce manual memory-management errors.

## Question
Replace suitable raw `new`/`delete` usage with `std::unique_ptr` and `std::shared_ptr`. Compare their behaviour and check for memory leaks.

## Concepts demonstrated
1. **Raw pointer:** allocates a resource using `new` and releases it using `delete`. The programmer is responsible for cleanup.
2. **`std::unique_ptr`:** represents exclusive ownership. It cannot be copied; ownership can be transferred with `std::move`. The resource is released automatically when the pointer leaves scope. The program also demonstrates a smart-pointer-managed array.
3. **`std::shared_ptr`:** represents shared ownership. The report and backup modules both hold a reference to the same resource. `use_count()` shows the number of owners; the resource is released when the final owner is destroyed.
4. **Repeated iterations:** performs 1,000 cycles of unique and shared allocation to exercise automatic cleanup.

## Comparison

| Feature | Raw pointer | unique_ptr | shared_ptr |
|---|---|---|---|
| Ownership | Not expressed by the pointer | Exclusive | Shared |
| Copying | Pointer value can be copied (ownership remains unclear) | Not copyable | Copyable; shares ownership |
| Ownership transfer | Manual convention | `std::move` | Copy another shared owner |
| Cleanup | Programmer must call `delete` | Automatic at scope exit | Automatic when last owner exits |
| Overhead | Minimal | Usually minimal | Reference-count bookkeeping |
| Best use | Non-owning access or low-level code | Default choice for owning a resource | Only when ownership is genuinely shared |

## Build and run

### Windows (MinGW g++)
Open the VS Code terminal in this folder:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
.\main.exe
```

### Ubuntu / WSL

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

## Memory checking

### AddressSanitizer (GCC / MinGW or WSL)

Compile and run:

```bash
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer main.cpp -o main_asan
./main_asan
```

A clean run should finish without AddressSanitizer memory-error reports. Save the actual terminal output in `memory_check.txt`.

### Valgrind (Ubuntu / WSL)

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
```

Record the real Valgrind summary in `memory_check.txt`. Do not claim a clean result unless you have run the command and verified its output.

## Observation
- The raw-pointer example requires an explicit `delete`; forgetting it can leak memory.
- `unique_ptr` automatically destroys its resource at the end of its scope and supports one owner.
- `shared_ptr` keeps the shared resource alive while at least one owner remains.
- Smart pointers implement RAII and make ownership and cleanup easier to reason about.

## Result
The program demonstrates raw-pointer cleanup, exclusive ownership with `std::unique_ptr`, shared ownership with `std::shared_ptr`, and repeated automatic resource release. Run AddressSanitizer or Valgrind locally and attach the actual result as evidence.

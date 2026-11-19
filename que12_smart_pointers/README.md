# Practical 12: Smart Pointers and RAII

## Aim
To understand how RAII connects resource lifetime to object lifetime and how `std::unique_ptr` and `std::shared_ptr` reduce manual memory-management errors.

## Files
- `main.cpp` — raw-pointer comparison, `unique_ptr`, `shared_ptr`, and a `unique_ptr` array demonstration.
- `expected_output.txt` — representative program output.
- `memory_check.txt` — commands and a place to record the actual memory-check result.

## Concepts demonstrated
1. **Raw pointer:** memory is allocated with `new` and must be released manually with `delete`. Forgetting cleanup can cause a leak.
2. **`std::unique_ptr`:** exclusive ownership. It cannot be copied; ownership can be transferred with `std::move`. The object is destroyed automatically when the owner leaves scope.
3. **`std::shared_ptr`:** shared ownership. Copies share a control block and reference count. The object is destroyed when the last owner is gone.
4. **RAII:** smart-pointer destructors release their managed resources automatically. Do not call `delete` on a smart pointer's managed object.

The program repeats all demonstrations three times. It also demonstrates `std::unique_ptr<int[]>` for array ownership.

## Compile and run (GCC / MinGW on Windows PowerShell)
```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
.\main.exe
```

## Memory checking with AddressSanitizer
Use a GCC build that supports AddressSanitizer:
```powershell
g++ -std=c++17 -g -O1 -fsanitize=address -fno-omit-frame-pointer main.cpp -o main_asan.exe
.\main_asan.exe
```
Review the complete output for AddressSanitizer errors. Leak detection support depends on the compiler/runtime. For a more explicit leak check, run the program in Ubuntu/WSL with Valgrind:
```bash
g++ -std=c++17 -g -O0 main.cpp -o main
valgrind --leak-check=full --show-leak-kinds=all ./main
```
A clean Valgrind run should report no definitely-lost or indirectly-lost bytes and ideally:
`All heap blocks were freed -- no leaks are possible`.

**Important:** Record the actual output from your own machine in `memory_check.txt`. Do not claim a clean memory-check result until you have run the tool.

## Comparison

| Feature | Raw pointer | unique_ptr | shared_ptr |
|---|---|---|---|
| Ownership | Not expressed/managed automatically | Exclusive (one owner) | Shared (multiple owners) |
| Cleanup | Programmer calls `delete` | Automatic at scope end | Automatic when last owner ends |
| Copying | Pointer value can be copied (does not transfer ownership) | Not copyable; movable | Copyable; increments reference count |
| Main risk | Leak, dangling pointer, double delete | Misusing `release()` or dangling non-owning references | Cycles can leak unless weak_ptr is used |
| Best use | Non-owning access / low-level APIs | Default choice for exclusive ownership | Only when ownership is genuinely shared |

## Observation
- The raw-pointer example needs an explicit `delete`.
- The `unique_ptr` object is destroyed automatically when its scope ends; moving it leaves the original pointer empty.
- The `shared_ptr` reference count changes from 1 to 2 and back to 1 when the second owner leaves scope.
- The shared object is destroyed only after the final owner leaves scope.
- The array managed by `unique_ptr<int[]>` is automatically released.

## Result
The program demonstrates exclusive and shared ownership, RAII-based cleanup, and the difference between manual raw-pointer cleanup and smart-pointer-managed lifetime.

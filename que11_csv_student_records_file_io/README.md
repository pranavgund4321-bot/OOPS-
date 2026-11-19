# Practical 11 – CSV Student Records Using File I/O

## Aim
To practise persistent storage, structured records, file modes, and file-position operations using C++ file streams.

## CSV format
The program stores one student per line in `students.csv`, using this three-column format:

```csv
ID,Name,Marks
1001,Aarav Sharma,88.50
1002,Diya Patel,92.00
1003,Rohan Mehta,79.25
```

This is a simple CSV demonstration. Names must not contain commas because the example parser uses commas as field separators and does not implement quoted CSV fields.

## Implementation
- `std::ofstream` creates/writes the CSV file and checks that opening and writing succeeded.
- `std::ifstream` reads the header and student records.
- Each record is parsed and validated; malformed records are skipped with a message.
- `std::fstream` is used for the read/write position demonstration in `position_demo.txt`.

## File-position functions

| Function | Purpose |
|---|---|
| `tellg()` | Returns the current input (get) position. |
| `seekg()` | Moves the input (get) position. |
| `tellp()` | Returns the current output (put) position. |
| `seekp()` | Moves the output (put) position. |

The **get position** is where the next read takes place. The **put position** is where the next write takes place. The program uses `tellg()` and `seekg()` on `students.csv`, and uses `tellp()` and `seekp()` on a small separate file so the original student data remains unchanged.

Position values are stream positions, not portable offsets into a raw C++ struct. CSV is written as text fields rather than dumping the in-memory bytes of a structure.

## Files generated
- `students.csv`: three student records.
- `position_demo.txt`: short file used to demonstrate output positioning; its content becomes `AZCDE`.

The committed `students.csv` is the expected generated CSV. Running the program recreates it in the current working directory.

## Compile and run

### Windows (PowerShell / VS Code terminal)

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
.\main.exe
```

### Linux / WSL

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

Run the executable from this practical's folder so the generated files appear there.

## Expected result
Three student records are written to and read from a CSV file. The output also shows the input and output stream positions before and after repositioning with all four required functions.

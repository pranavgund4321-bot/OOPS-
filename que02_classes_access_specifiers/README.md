# Practical 02: Classes, Access Specifiers and Member Functions

## Question
Design and implement a class model for a real-world entity such as a BankAccount or Vehicle.

## Aim
To understand how classes combine data and behaviour, and how access specifiers protect data.

## Program
This practical implements a `BankAccount` class with two objects.

### Class members
- **Private data members:** `accountNumber`, `accountHolder`, and `balance`. They cannot be accessed or modified directly from `main()`. This protects account data and ensures balance changes go through validation.
- **Public member functions:** constructor, `displayDetails()`, `deposit()`, `withdraw()`, and `getBalance()`. These provide controlled access to the account's behaviour and information.
- **Constructor:** initialises each object and prevents a negative opening balance.
- **Validation:** deposit and withdrawal amounts must be positive; a withdrawal cannot exceed the available balance.

## Compile and run
```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
.\main.exe
```

## Sample output
```text
========== BANK ACCOUNT MANAGEMENT =========

--- ACCOUNT 1 ---
Account holder : Aarav Sharma
Account number : BA1001
Balance        : Rs. 5000.00
Rs. 1500.00 deposited successfully.
Rs. 2000.00 withdrawn successfully.
Final balance  : Rs. 4500.00

--- ACCOUNT 2 ---
Account holder : Diya Patel
Account number : BA1002
Balance        : Rs. 2500.00
Rs. 1000.00 deposited successfully.
Withdrawal failed: insufficient balance.
Final balance  : Rs. 3500.00
```

## Result
The `BankAccount` class demonstrates encapsulation using private data members and public member functions. Two separate objects are created, and their deposit, withdrawal, and display operations are demonstrated.

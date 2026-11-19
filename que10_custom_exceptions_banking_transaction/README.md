# Practical 10 – Custom Exceptions: Banking Transaction

## Aim
To practise reporting application-specific failures and handling different errors in a controlled way using a custom exception hierarchy in C++.

## Problem statement
Create a bank account with a withdrawal operation. Throw and catch specific custom exceptions for invalid amounts and insufficient funds. Verify that unsuccessful transactions do not alter the account balance.

## Exception hierarchy

```text
std::runtime_error
       |
BankingException
       |
  +----+----------------+
  |                     |
InvalidAmount     InsufficientFunds
```

- **BankingException:** Common base class for application-specific banking errors. It derives from `std::runtime_error`.
- **InvalidAmount:** Thrown when a withdrawal amount is zero or negative.
- **InsufficientFunds:** Thrown when the requested withdrawal is greater than the available balance.

## Program flow

```text
Start
  |
Create BankAccount (Rs. 1000)
  |
Attempt withdrawal
  |
Validate amount
  |---- amount <= 0 ----> throw InvalidAmount
  |
Check balance
  |---- amount > balance -> throw InsufficientFunds
  |
Deduct amount and report success
  |
Catch the specific exception (if thrown)
  |
Display balance
  |
End
```

## Test cases

| Test | Withdrawal amount | Expected result |
|---|---:|---|
| Successful withdrawal | Rs. 250 | Balance becomes Rs. 750 |
| Invalid amount | Rs. -100 | InvalidAmount; balance stays Rs. 750 |
| Insufficient funds | Rs. 2000 | InsufficientFunds; balance stays Rs. 750 |

## Why custom exceptions?
Custom exception types make application errors explicit. The caller can catch `InvalidAmount` and `InsufficientFunds` separately and respond with a message appropriate to each failure.

## Compilation and execution

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

## Result
The program demonstrates a custom exception hierarchy and separate handling of invalid amounts and insufficient funds. The account balance is updated only after a valid withdrawal, so failed transactions leave it unchanged.

#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>

// Common base class for application-specific banking errors.
class BankingException : public std::runtime_error {
public:
    explicit BankingException(const std::string& message)
        : std::runtime_error(message) {}
};

class InvalidAmount : public BankingException {
public:
    InvalidAmount()
        : BankingException("Transaction amount must be greater than zero.") {}
};

class InsufficientFunds : public BankingException {
public:
    InsufficientFunds()
        : BankingException("Transaction declined: insufficient account balance.") {}
};

class BankAccount {
private:
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& name, double openingBalance)
        : accountHolder(name), balance(openingBalance) {
        if (openingBalance < 0) {
            throw InvalidAmount();
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;
        std::cout << "Withdrawal successful: Rs. " << amount << '\n';
    }

    void displayBalance() const {
        std::cout << accountHolder << "'s current balance: Rs. "
                  << balance << '\n';
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    BankAccount account("Aarav Sharma", 1000.00);
    std::cout << "=== Banking Transaction Demo ===\n";
    account.displayBalance();

    std::cout << "\n1. Successful withdrawal\n";
    try {
        account.withdraw(250.00);
    } catch (const InvalidAmount& error) {
        std::cout << "InvalidAmount: " << error.what() << '\n';
    } catch (const InsufficientFunds& error) {
        std::cout << "InsufficientFunds: " << error.what() << '\n';
    }
    account.displayBalance();

    std::cout << "\n2. Invalid amount (negative value)\n";
    try {
        account.withdraw(-100.00);
    } catch (const InvalidAmount& error) {
        std::cout << "InvalidAmount: " << error.what() << '\n';
    } catch (const InsufficientFunds& error) {
        std::cout << "InsufficientFunds: " << error.what() << '\n';
    }
    account.displayBalance();

    std::cout << "\n3. Withdrawal exceeding available balance\n";
    try {
        account.withdraw(2000.00);
    } catch (const InvalidAmount& error) {
        std::cout << "InvalidAmount: " << error.what() << '\n';
    } catch (const InsufficientFunds& error) {
        std::cout << "InsufficientFunds: " << error.what() << '\n';
    }
    account.displayBalance();

    std::cout << "\nAll transactions completed. Failed transactions did not "
                 "change the balance.\n";
    return 0;
}

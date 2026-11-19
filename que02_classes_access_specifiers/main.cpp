#include <iostream>
#include <iomanip>
#include <string>

class BankAccount {
private:
    // Private members: account details are hidden from direct access.
    // This protects the balance from being changed without validation.
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    // Public constructor: initialise each account with validated data.
    BankAccount(const std::string& number,
                const std::string& holder,
                double openingBalance)
        : accountNumber(number), accountHolder(holder),
          balance(openingBalance >= 0.0 ? openingBalance : 0.0) {
        if (openingBalance < 0.0) {
            std::cout << "Invalid opening balance for " << accountHolder
                      << ". Balance set to 0.\n";
        }
    }

    // Public member function: display account information.
    void displayDetails() const {
        std::cout << "Account holder : " << accountHolder << '\n'
                  << "Account number : " << accountNumber << '\n'
                  << "Balance        : Rs. " << std::fixed
                  << std::setprecision(2) << balance << '\n';
    }

    // Public member function: deposit only a positive amount.
    void deposit(double amount) {
        if (amount <= 0.0) {
            std::cout << "Deposit failed: amount must be positive.\n";
            return;
        }

        balance += amount;
        std::cout << "Rs. " << std::fixed << std::setprecision(2)
                  << amount << " deposited successfully.\n";
    }

    // Public member function: withdraw only if amount is valid
    // and sufficient balance is available.
    void withdraw(double amount) {
        if (amount <= 0.0) {
            std::cout << "Withdrawal failed: amount must be positive.\n";
        } else if (amount > balance) {
            std::cout << "Withdrawal failed: insufficient balance.\n";
        } else {
            balance -= amount;
            std::cout << "Rs. " << std::fixed << std::setprecision(2)
                      << amount << " withdrawn successfully.\n";
        }
    }

    // Public read-only accessor: callers can check balance but cannot
    // directly modify the private data member.
    double getBalance() const {
        return balance;
    }
};

int main() {
    std::cout << "========== BANK ACCOUNT MANAGEMENT =========\n\n";

    // Create two independent objects using the constructor.
    BankAccount account1("BA1001", "Aarav Sharma", 5000.00);
    BankAccount account2("BA1002", "Diya Patel", 2500.00);

    std::cout << "--- ACCOUNT 1 ---\n";
    account1.displayDetails();
    account1.deposit(1500.00);
    account1.withdraw(2000.00);
    std::cout << "Final balance  : Rs. " << account1.getBalance() << "\n\n";

    std::cout << "--- ACCOUNT 2 ---\n";
    account2.displayDetails();
    account2.deposit(1000.00);
    account2.withdraw(5000.00); // Demonstrates insufficient-balance validation.
    std::cout << "Final balance  : Rs. " << account2.getBalance() << "\n";

    return 0;
}

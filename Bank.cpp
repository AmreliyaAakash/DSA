#include <iostream>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    double getBalance() {
        return balance;
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << accountHolderName;
        cout << "\nBalance: " << balance << endl;
    }

    // Polymorphic function
    virtual void calculateInterest() {
        cout << "No interest for base account.\n";
    }

    virtual ~BankAccount() {}
};

// Savings Account
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }
};

// Checking Account
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn with overdraft: " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void checkOverdraft() {
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAccount {
private:
    int term; // months
    double rate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double r)
        : BankAccount(accNo, name, bal) {
        term = t;
        rate = r;
    }

    void calculateInterest() override {
        double interest = (balance * rate * term) / (100 * 12);
        cout << "FD Interest: " << interest << endl;
    }
};

// Menu System
int main() {
    BankAccount* account = nullptr;
    int choice, type;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Info\n";
        cout << "5. Calculate Interest\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nSelect Account Type:\n";
            cout << "1. Savings\n2. Checking\n3. Fixed Deposit\n";
            cin >> type;

            int accNo;
            string name;
            double bal;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> bal;

            if (type == 1) {
                double rate;
                cout << "Enter Interest Rate: ";
                cin >> rate;
                account = new SavingsAccount(accNo, name, bal, rate);
            }
            else if (type == 2) {
                double limit;
                cout << "Enter Overdraft Limit: ";
                cin >> limit;
                account = new CheckingAccount(accNo, name, bal, limit);
            }
            else if (type == 3) {
                int term;
                double rate;
                cout << "Enter Term (months): ";
                cin >> term;
                cout << "Enter Interest Rate: ";
                cin >> rate;
                account = new FixedDepositAccount(accNo, name, bal, term, rate);
            }

            cout << "Account Created Successfully!\n";
            break;
        }

        case 2:
            if (account) {
                double amt;
                cout << "Enter amount: ";
                cin >> amt;
                account->deposit(amt);
            }
            break;

        case 3:
            if (account) {
                double amt;
                cout << "Enter amount: ";
                cin >> amt;
                account->withdraw(amt);
            }
            break;

        case 4:
            if (account)
                account->displayAccountInfo();
            break;

        case 5:
            if (account)
                account->calculateInterest(); // polymorphism
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    delete account;
    return 0;
}

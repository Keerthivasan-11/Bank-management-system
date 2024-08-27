#include <bits/stdc++.h>
using namespace std;

// Base class for Bank Accounts
class BankAccount {
protected:
    int Accnumber;
    string name;
    double balance;

public:
    BankAccount(string n, int Acc, double bal)
        : name(n), Accnumber(Acc), balance(bal) {}

    virtual ~BankAccount() {}  // Virtual destructor

    string getname() const {
        return name;
    }
    int getAccnumber() const {
        return Accnumber;
    }
    double getbalance() const {
        return balance;
    }
    void deposit(double amount) {
        balance += amount;
    }
    virtual void withdraw(double amount) = 0;  // Pure virtual function
};

// Derived class for Saving Account
class SavingAccount : public BankAccount {
public:
    SavingAccount(string n, int Acc, double bal)
        : BankAccount(n, Acc, bal) {}

    void withdraw(double amount) override {
        if (balance > amount) {
            balance -= amount;
            cout << "\t\t--Withdrawal successful--";
        } else {
            cout << "\t\t--Insufficient balance--";
        }
    }
};

// Derived class for Current Account
class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string n, int Acc, double bal)
        : BankAccount(n, Acc, bal) {}

    void withdraw(double amount) override {
        // Current accounts can overdraft, so there's no balance check here
        balance -= amount;
        cout << "\t\t--Withdrawal successful--";
    }
};

// Class to manage the bank accounts
class BankManagement {
private:
    vector<BankAccount*> accounts;

public:
    ~BankManagement() {
        for (auto acc : accounts) {
            delete acc;
        }
    }

    void addAccount(string name, int Accnumber, double balance, bool isSaving) {
        BankAccount* account;
        if (isSaving) {
            account = new SavingAccount(name, Accnumber, balance);
        } else {
            account = new CurrentAccount(name, Accnumber, balance);
        }
        accounts.push_back(account);
    }

    void showAllAccounts() const {
        cout << "\t\tAll accounts:" << endl;
        for (auto acc : accounts) {
            cout << "\t\tName: " << acc->getname() << endl;
            cout << "\t\tAccount number: " << acc->getAccnumber() << endl;
            cout << "\t\tAccount balance: " << acc->getbalance() << endl;
            cout << "\t--------------------------------" << endl;
        }
    }

    void searchAccount(int accountnum) const {
        cout << "\t\tAccount Holder" << endl;
        for (auto acc : accounts) {
            if (acc->getAccnumber() == accountnum) {
                cout << "\t\tName: " << acc->getname() << endl;
                cout << "\t\tAccount number: " << acc->getAccnumber() << endl;
                cout << "\t\tAccount balance: " << acc->getbalance() << endl;
                return;
            }
        }
        cout << "\t\t--No account number available--" << endl;
    }

    BankAccount* findAccount(int Acc) const {
        for (auto acc : accounts) {
            if (acc->getAccnumber() == Acc) {
                return acc;
            }
        }
        return nullptr;
    }
};

int main() {
    BankManagement bank;
    int choice;
    char option;

    do {
        system("clear");
        cout << "\t\t::BANK MANAGEMENT SYSTEM::" << endl;
        cout << "\t\t\tMAIN MENU" << endl;
        cout << "\t\t\t 1. Create account" << endl;
        cout << "\t\t\t 2. Show all accounts" << endl;
        cout << "\t\t\t 3. Search account" << endl;
        cout << "\t\t\t 4. Deposit money" << endl;
        cout << "\t\t\t 5. Withdraw money" << endl;
        cout << "\t\t\t 6. Exit" << endl;
        cout << "\t\t---------------------------------" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int Accnumber;
            double balance;
            bool isSaving;
            cout << "\tEnter Name: ";
            cin >> name;
            cout << "\tEnter account number: ";
            cin >> Accnumber;
            cout << "\tEnter initial deposit: ";
            cin >> balance;
            cout << "\tIs it a saving account (1 for Yes, 0 for No)? ";
            cin >> isSaving;
            bank.addAccount(name, Accnumber, balance, isSaving);
            cout << "\t\tAccount created successfully..........." << endl;
            break;
        }
        case 2:
            bank.showAllAccounts();
            break;
        case 3: {
            int Accnumber;
            cout << "\t\tEnter account number: ";
            cin >> Accnumber;
            bank.searchAccount(Accnumber);
            break;
        }
        case 4: {
            double dep;
            int acc;
            cout << "\t\tAccount number to deposit: ";
            cin >> acc;
            BankAccount* account = bank.findAccount(acc);
            if (account != nullptr) {
                cout << "\t\tEnter the amount to deposit: ";
                cin >> dep;
                account->deposit(dep);
                cout << "\t\tAmount deposited successfully---";
            } else {
                cout << "\t\tAccount not found--" << endl;
            }
            break;
        }
        case 5: {
            double Withdrawal;
            int acc;
            cout << "\t\tAccount number to withdraw: ";
            cin >> acc;
            BankAccount* account = bank.findAccount(acc);
            if (account != nullptr) {
                cout << "\t\tEnter the amount to withdraw: ";
                cin >> Withdrawal;
                account->withdraw(Withdrawal);
                cout << "\t\tAmount withdrawn successfully---";
            } else {
                cout << "\t\tAccount not found--" << endl;
            }
            break;
        }
        case 6:
            cout << "\t\tThank you for using the Bank Management System!" << endl;
            cout << "\t\tHave a great day!" << endl;
            return 0;
        default:
            cout << "\t\tInvalid choice, please try again." << endl;
        }

        cout << endl;
        cout << "\t\tWhether to continue or exit [Yes(Y) or No(N)]? ";
        cin >> option;
    } while (option == 'Y' || option == 'y');

    return 0;
}

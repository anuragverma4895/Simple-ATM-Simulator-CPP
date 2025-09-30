#include <iostream>
using namespace std;
class ATM {
    int pin;
    double balance;
public:
    ATM(int p, double b) {
        pin = p;
        balance = b;
    }

    bool login() {
        int attempt = 0, enteredPin;
        while (attempt < 3) {
            cout << "Enter PIN: ";
            cin >> enteredPin;
            if (enteredPin == pin) {
                cout << "Login successful\n";
                return true;
            } else {
                cout <<"Incorrect PIN\n";
                attempt++;
            }
        }
        cout << "Account locked. Too many attempts.\n";
        return false;
    }
    void checkBalance() {
        cout << "Current Balance: $" << balance << "\n";
    }
    void deposit() {
        double amount;
        cout << "Enter amount to deposit: $";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Deposited successfully. Updated Balance: $" << balance << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }
    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: $";
        cin >> amount;
        if (amount < 10) {
            cout << "Minimum withdrawal is $10.\n";
        } else if (amount > 500) {
            cout << "Maximum withdrawal per transaction is $500.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Remaining Balance: $" << balance << "\n";
        }
    }
};

int main() {
    ATM atm(1234, 50.0);
    if (!atm.login()) return 0;
    int choice;
    do {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: atm.checkBalance(); break;
            case 2: atm.deposit(); break;
            case 3: atm.withdraw(); break;
            case 4: cout << "Thank you for using ATM.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}

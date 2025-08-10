/*  
    Name: Akumatey Cyril Stevenson
    Index Number: 6134524
    Program: Bank Account Management
    Description: This program uses a class to manage up to 10 bank accounts.
                  It allows creating accounts, depositing, withdrawing, applying
                  interest, and viewing account details.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// This class represents a basic bank account
class bankAccount {
private:
    string name;                    // Account holder's name
    int accountNumber;              // Unique account number (automatically assigned)
    string accountType;             // Account type (either "checking" or "saving")
    double balance;                 // Current balance in the account
    double interestRate;            // Interest rate as a decimal (e.g. 0.03 for 3%)
    static int nextAccountNumber;   // Static variable to keep track of the next account number

public:
    // Constructor to create an account with initial values
    bankAccount(string n = "", string type = "checking", double bal = 0.0, double rate = 0.0) {
        name = n;
        accountType = type;
        balance = bal;
        interestRate = rate;
        accountNumber = nextAccountNumber++; // Assign and increment account number
    }

    // This function returns the account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds or invalid amount.\n";
    }

    // Function to apply interest to the account balance
    void applyInterest() {
        balance += balance * interestRate;
    }

    // Function to display account details
    void display() const {
        cout << fixed << setprecision(2); // Set decimal precision to 2 places
        cout << "\n--- Account Info ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << name << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%\n";
        cout << "---------------------\n";
    }
};

// Initialize the static account number starting from 1000
int bankAccount::nextAccountNumber = 1000;

int main() {
    const int MAX_ACCOUNTS = 10;            // Maximum number of accounts the program can store
    bankAccount accounts[MAX_ACCOUNTS];     // Array to store up to 10 accounts
    int accountCount = 0;                   // Keeps track of how many accounts have been created
    int choice;                             // Stores user's menu choice

    do {
        // Display menu
        cout << "\n--- Bank Account Menu ---\n";
        cout << "1. Create new account\n";
        cout << "2. Deposit to account\n";
        cout << "3. Withdraw from account\n";
        cout << "4. Apply interest to account\n";
        cout << "5. Display all accounts\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        // Handle user's choice
        switch (choice) {
            case 1:
                if (accountCount < MAX_ACCOUNTS) {
                    // Variables to hold account details
                    string name, type;
                    double balance, rate;

                    cin.ignore(); // Clear input buffer before using getline
                    cout << "Enter account holder's name: ";
                    getline(cin, name);
                    cout << "Enter account type (checking/saving): ";
                    getline(cin, type);
                    cout << "Enter initial balance: $";
                    cin >> balance;
                    cout << "Enter interest rate (e.g., 0.03 for 3%): ";
                    cin >> rate;

                    // Create new account and store it in the array
                    accounts[accountCount] = bankAccount(name, type, balance, rate);
                    cout << "Account created. Account Number: " << accounts[accountCount].getAccountNumber() << endl;
                    accountCount++;
                } else {
                    cout << "Maximum number of accounts reached.\n";
                }
                break;

            case 2: {
                int accNum;
                double amount;
                cout << "Enter account number to deposit into: ";
                cin >> accNum;

                // Search for the account
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        cout << "Enter amount to deposit: $";
                        cin >> amount;
                        accounts[i].deposit(amount);
                        cout << "Deposit successful.\n";
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Account not found.\n";
                break;
            }

            case 3: {
                int accNum;
                double amount;
                cout << "Enter account number to withdraw from: ";
                cin >> accNum;

                // Search for the account
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        cout << "Enter amount to withdraw: $";
                        cin >> amount;
                        accounts[i].withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Account not found.\n";
                break;
            }

            case 4: {
                int accNum;
                cout << "Enter account number to apply interest: ";
                cin >> accNum;

                // Search for the account
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        accounts[i].applyInterest();
                        cout << "Interest applied.\n";
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Account not found.\n";
                break;
            }

            case 5:
                // Display all created accounts
                for (int i = 0; i < accountCount; i++) {
                    accounts[i].display();
                }
                break;

            case 0:
                cout << "Exiting program. Thank you!\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 0); // Continue until user chooses to exit

    return 0;
}

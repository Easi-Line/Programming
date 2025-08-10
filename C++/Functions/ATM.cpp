#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "----------MENU----------" << "\n"
         << "1. Check Balance" << "\n"
         << "2. Deposit Money" << "\n"
         << "3. Withdraw Money" << "\n"
         << "4. Send Money" << "\n"
         << "5. Transaction History" << "\n"
         << "6. Exit" << "\n"
         << "------------------------" << "\n"
         << "Please select an option (1-6): ";
}

float getAmount () {
    float amount;
    cout << "Enter amount: ";
    cin >> amount;
    return amount;
}

void checkBalance(float accountBalance) {
    if (accountBalance >= 0) {
    cout << "\nAccount balnce: $" << accountBalance << "\n" "\n";
    } else {
        cout << "\nAccount balnce: $0\n"; // Display zero balance if negative
        cout << "Loan balnce: $" << accountBalance << "\n" "\n";
    }
}

float depositMoney(float accountBalance, float depositAmount) {
    if (depositAmount > 0) {
                    accountBalance += depositAmount;
                    cout << "\nAmount Deposited: " << depositAmount << "\n"
                         << "New balance: " << accountBalance << "\n" "\n";
                } else {
                    cout << "Invalid deposit amount.\n";
                }
    return accountBalance;
}

float withdrawMoney(float accountBalance, float withdrawAmount) {
    if (withdrawAmount <= 0) {
        cout << "Invalid withdrawal amount.\n";
    } else if (withdrawAmount > accountBalance) {
        cout << "\nInsufficient funds.\n"
             << "Current balance: " << accountBalance << "\n"
             << "You can withdraaw the money you want with a charge of $20.\nPress 1 to proceed or 0 to cancel: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            accountBalance -= (withdrawAmount + 20); // Deduct withdrawal amount and charge
            cout << "\nAmount Withdrawn: " << withdrawAmount << "\n"
                 << "New balance after charge: " << accountBalance << "\n" "\n";
        } else {
            cout << "Withdrawal cancelled.\n";
        }
    } else {
        accountBalance -= withdrawAmount;
        cout << "\nAmount Withdrawn: " << withdrawAmount << "\n"
             << "New balance: " << accountBalance << "\n" "\n";
    } 
    return accountBalance;
}

float sendMoney(float accountBalance, float sendAmount) {
    cout << "enter the recipient's account number: ";
    int recipientAccount;
    cin >> recipientAccount;
    if (sendAmount <= 0) {
        cout << "Invalid send amount.\n";
    } else if (sendAmount > accountBalance) {
        cout << "\nInsufficient funds.\n"
             << "Current balance: " << accountBalance << "\n"
             << "You can send the money you want with a charge of $50.\nPress 1 to proceed or 0 to cancel: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            accountBalance -= (sendAmount + 20); // Deduct send amount and charge
            cout << "\nAmount Sent: " << sendAmount << "\n"
                 << "New balance after charge: " << accountBalance << "\n" "\n";
        } else {
            cout << "Send cancelled.\n";
        }
    } else {
        accountBalance -= sendAmount;
        cout << "\nAmount Sent: " << sendAmount << "\n"
             << "New balance: " << accountBalance << "\n" "\n";
    }
    // return the updated balance.
    cout << "Transaction to account " << recipientAccount << " completed successfully.\n";
    cout << "New balance: " << accountBalance << "\n" "\n";

    return accountBalance;
}

string transactionHistory() {
    cout << "Transaction history is not implemented yet.\n";
    return "Transaction history is not available.";
}

int main () {
    float accountBalance = 1000.0; // Example initial balance
    int choice;
    while (choice != 6) {
        displayMenu();
        cin >> choice;
        // system("cls"); // Clear the console screen
        switch(choice) {
            case 1: {
                checkBalance(accountBalance);
                break;
            }
            case 2: {
                float depositAmount;
                depositAmount = getAmount();
                accountBalance = depositMoney(accountBalance, depositAmount);
                break;
            }
            case 3: {
                float withdrawAmount;
                withdrawAmount = getAmount();
                accountBalance = withdrawMoney(accountBalance, withdrawAmount);
                break;
            }
            case 4: {
                float sendAmount;
                sendAmount = getAmount();
                accountBalance = sendMoney(accountBalance, sendAmount);
                break;
            }
            case 5: {
                transactionHistory();
                break;
            }
            case 6: {
                cout << "Exiting the ATM. Thank you!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please select a valid option (1-6).\n";
                break;
            }
        }
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

// SavingsAccount class tracks a user's savings plan and progress
class SavingsAccount {
    double deposit, rate, savedAmount;      // periodic deposit amount, annual interest rate, amount saved so far
    int periods, years;                     // number of deposits per year, number of years
    string savingGoal;                      // description of the savings goal
    double targetAmount;                    // target amount to save

public:
    // Constructor with default values for goal, target, and saved
    SavingsAccount(double dep, int p, double r, int y,
                   const string& goal = "", double target = 0.0, double saved = 0.0)
        : deposit(dep), periods(p), rate(r), years(y),
          savingGoal(goal), targetAmount(target), savedAmount(saved) {}

    // Set the user's savings goal and target amount
    void setGoal(const string& goal, double target) {
        savingGoal = goal;
        targetAmount = target;
    }

    // Add a deposit to the saved amount (only if positive)
    void addDeposit(double amount) {
        if (amount > 0)
            savedAmount += amount;
        else
            cout << "Deposit must be positive.\n";
    }

    // Update periodic savings plan information
    void setDepositInfo(double dep, int p, double r, int y) {
        deposit = dep;
        periods = p;
        rate = r;
        years = y;
    }

    // Calculate total accumulated amount after the savings plan period
    double totalAccumulated() const {
        if (rate == 0) return deposit * periods * years;
        double rp = rate / periods; // rate per period
        double factor = pow(1 + rp, periods * years);
        return deposit * (factor - 1) / rp;
    }

    // Calculate the required deposit per period to reach a certain target
    double requiredDeposit(double target) const {
        double rp = rate / periods; // rate per period
        double factor = pow(1 + rp, periods * years);
        double denom = factor - 1;
        if (denom == 0) return target / (periods * years);
        return target * rp / denom;
    }

    // Display current progress towards the savings goal
    void viewProgress() const {
        cout << "\n--- Savings Progress ---\n";
        cout << "Saving Goal: " << (savingGoal.empty() ? "Not set" : savingGoal) << endl;
        cout << "Target Amount: $" << targetAmount << endl;
        cout << "Saved so far: $" << savedAmount << endl;
        cout << "Amount needed: $" << (targetAmount > savedAmount ? targetAmount - savedAmount : 0) << endl;
        if (targetAmount > 0) {
            double percent = (savedAmount / targetAmount) * 100.0;
            if (percent > 100) percent = 100;
            cout << "Progress: " << percent << "%\n";
        }
        cout << "-----------------------\n";
    }
};

int main() {
    double deposit, rate, target;
    int periods, years, choice;
    string goal;

    // Initialize account with default values
    SavingsAccount acc(0, 1, 0, 1);

    cout << fixed << setprecision(2);
    cout << "Savings Account Calculator\n";

    // Menu-driven loop for user interaction
    while (true) {
        system("cls"); // Clear the console screen (Windows). Use "clear" for Linux/macOS.
        cout << "Savings Account Calculator\n";
        cout << "\nMenu:\n";
        cout << "1. Set savings goal\n";
        cout << "2. Add deposit\n";
        cout << "3. View progress\n";
        cout << "4. Calculate total accumulated from periodic deposits\n";
        cout << "5. Calculate required deposit to reach target amount\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (choice == 0) {
            cout << "\nThank you for using the Savings Account Calculator!\n \n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter your saving goal (reason): ";
                getline(cin, goal);
                cout << "Enter your target amount: ";
                cin >> target;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (target < 0) {
                    cout << "\nTarget amount must not be negative.\n";
                    break;
                }
                acc.setGoal(goal, target);
                break;

            case 2:
                cout << "Enter deposit amount: ";
                cin >> deposit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                acc.addDeposit(deposit);
                break;

            case 3:
                acc.viewProgress();
                break;

            case 4:
                cout << "Enter number of deposits per year (e.g., 12 for monthly): ";
                cin >> periods;
                cout << "Enter annual interest rate (e.g., 0.048 for 4.8%): ";
                cin >> rate;
                cout << "Enter number of years: ";
                cin >> years;
                cout << "Enter deposit amount for each period: ";
                cin >> deposit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                acc.setDepositInfo(deposit, periods, rate, years);
                cout << "\nTotal accumulated after " << years << " years: $"
                     << acc.totalAccumulated() << "\n \n";
                break;

            case 5:
                cout << "Enter number of deposits per year (e.g., 12 for monthly): ";
                cin >> periods;
                cout << "Enter annual interest rate (e.g., 0.048 for 4.8%): ";
                cin >> rate;
                cout << "Enter number of years: ";
                cin >> years;
                cout << "Enter target amount to accumulate: ";
                cin >> target;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                acc.setDepositInfo(0, periods, rate, years);
                cout << "\nRequired deposit per period to reach $" << target << " in "
                     << years << " years: $" << acc.requiredDeposit(target) << "\n \n";
                break;

            default:
                cout << "\nInvalid option selected.\n \n";
        }
        cout << "\nPress Enter to continue...";
        cin.get(); // Wait for user to press Enter before clearing the screen
    }

    return 0;
}
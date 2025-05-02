// Bank Account System using OOP
#include <iostream>
using namespace std;

// Creating BankAccount class
class BankAccount {
private:
    string ownerName;
    int accountID;
    string typeOfAccount;
    double currentBalance;

public:
    // Default constructor
    BankAccount() {
        ownerName = "User";
        accountID = 00000;
        typeOfAccount = "Savings";
        currentBalance = 0;
    }

    // Parameterized constructor
    BankAccount(string owner, int accID, string accType, double balance) {
        ownerName = owner;
        accountID = accID;
        typeOfAccount = accType;
        currentBalance = balance;
    }

    // Accessor functions
    string getOwnerName() {
        return ownerName;
    }

    int getAccountID() {
        return accountID;
    }

    string getTypeOfAccount() {
        return typeOfAccount;
    }

    double getCurrentBalance() {
        return currentBalance;
    }

    // Mutator function
    void setAccountType(string accType) {
        typeOfAccount = accType;
        cout << "Updated account type to " << typeOfAccount << "." << endl;
    }

    // Deposit and Withdraw methods
    void deposit(double amount) {
        if (amount > 0) {
            cout << "Depositing " << amount << " Rs." << endl;
            currentBalance += amount;
            cout << "New Balance: " << currentBalance << " Rs." << endl << "\n";
        }
    }

    void withdraw(double amount) {
        if (amount > currentBalance) {
            cout << "Insufficient Balance.";
            return;
        }
        cout << "Withdrawing " << amount << " Rs." << endl;
        currentBalance -= amount;
        cout << "New Balance: " << currentBalance << " Rs." << endl << "\n";
    }

    // Display account details
    void showAccountDetails() {
        cout << "Account Details:" << endl;
        cout << "Holder: " << ownerName << endl;
        cout << "Account Number: " << accountID << endl;
        cout << "Type: " << typeOfAccount << endl;
        cout << "Balance: " << currentBalance << " Rs." << endl;
    }
};

// Main function
int main() {
    int depositAmount, withdrawAmount;
    
    // Default constructor object
    BankAccount acc1;
    acc1.showAccountDetails();
    cout << "\n";

    // Parameterized constructor object
    BankAccount acc2("Atharv Niprul", 123456, "Savings", 30000);
    acc2.showAccountDetails();
    cout << "\n";

    // Depositing and withdrawing money
    cout << "Enter Amount to deposit: ";
    cin >> depositAmount;
    acc2.deposit(depositAmount);

    cout << "Enter Amount to Withdraw: ";
    cin >> withdrawAmount;
    acc2.withdraw(withdrawAmount);

    // Using accessor methods
    cout << "Holder: " << acc2.getOwnerName() << endl;
    cout << "Account Number: " << acc2.getAccountID() << endl;
    cout << "Type: " << acc2.getTypeOfAccount() << endl;
    cout << "Balance: " << acc2.getCurrentBalance() << " Rs." << endl;
    cout << "\n";

    // Mutator method
    string newType;
    cout << "Enter New Account Type: ";
    cin >> newType;
    acc2.setAccountType(newType);
    cout << "\n";
    acc2.showAccountDetails();
    cout << "\n";

    // Creating an account with user inputs
    string userHolder;
    int userAccID;
    string userAccType;
    double userBalance;

    cout << "Enter Account Holder Name: ";
    cin >> userHolder;
    cout << "Enter Account Number: ";
    cin >> userAccID;
    cout << "Enter Account Type: ";
    cin >> userAccType;
    cout << "Enter Account Balance: ";
    cin >> userBalance;
    cout << "\n";

    // Creating new object with user inputs
    BankAccount acc3(userHolder, userAccID, userAccType, userBalance);
    acc3.showAccountDetails();
    
    return 0;
}

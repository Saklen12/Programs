#include <iostream>
using namespace std;

// Bank class with function overloading for deposits
class FinancialInstitution {
public:
    void addFunds(int cashAmount) {
        cout << "Depositing " << cashAmount << " RS in cash." << endl;
    }

    void addFunds(float digitalAmount) {
        cout << "Depositing " << digitalAmount << " RS via digital payment." << endl;
    }

    void addFunds(string upiIdentifier) {
        int amount;
        cout << "Enter amount to pay via UPI: ";
        cin >> amount;
        cout << "Depositing " << amount << " RS using UPI (" << upiIdentifier << ")." << endl;
    }
};

// Account class with operator overloading for transactions
class UserAccount {
private:
    int accID;
    double accBalance;

public:
    UserAccount(int id, double balance) : accID(id), accBalance(balance) {}

    void showDetails() {
        cout << "Account: " << accID << "\tBalance: " << accBalance << " RS" << endl;
    }

    // Operator overloading for deposit
    UserAccount operator+(double amount) {
        accBalance += amount;
        return *this;
    }

    // Operator overloading for withdrawal
    UserAccount operator-(double amount) {
        if (accBalance >= amount) {
            accBalance -= amount;
        } else {
            cout << "Insufficient Funds." << endl;
        }
        return *this;
    }

    void sendFunds(UserAccount &receiver, double amount) {
        if (accBalance >= amount) {
            accBalance -= amount;
            receiver.accBalance += amount;
            cout << "Transferring " << amount << " RS from Account " << accID << " to Account " << receiver.accID << "..." << endl;
        } else {
            cout << "Transfer Failed: Insufficient balance." << endl;
        }
    }
};

int main() {
    cout << "----------------------------------------------------" << endl;
    
    // Bank instance
    FinancialInstitution bank;
    bank.addFunds(7000);
    bank.addFunds(1000.10f);
    bank.addFunds("PhonePe23746@UPI");
    
    // Creating User Accounts
    UserAccount user1(23746, 10000);
    UserAccount user2(83972, 5000);
    user1.showDetails();
    user2.showDetails();
    
    cout << "----------------------------------------------------" << endl;
    
    // Fund Transfer
    user1.sendFunds(user2, 3000);
    user1.showDetails();
    user2.showDetails();
    
    cout << "----------------------------------------------------" << endl;
    
    // Withdraw Funds
    user1 = user1 - 2000;
    cout << "Withdrawing " << 2000 << " RS from account 1..." << endl;
    user1.showDetails();
    
    return 0;
}

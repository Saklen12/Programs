#include<iostream>
#include<fstream>
#include <vector>
using namespace std;

int addFunds(int *balance)
{
    int depositAmount;
    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    *balance += depositAmount;
    
    string record = "+" + to_string(depositAmount) + " Rs";
    ofstream transactionFile("records.txt", ios::app);
    transactionFile << record << endl;
    transactionFile.close();
    
    cout << depositAmount << " Rs deposited successfully.\n" << endl;
    return 1;
}

int deductFunds(int *balance, int withdrawalAmount)
{
    if (withdrawalAmount < *balance)
    {
        *balance -= withdrawalAmount;
        
        string record = "-" + to_string(withdrawalAmount) + " Rs";
        ofstream transactionFile("records.txt", ios::app);
        transactionFile << record << endl;
        transactionFile.close();
        
        return 1;
    }
    return 0;
}

void showLastTransactions()
{
    string recentTransactions[10];
    int totalEntries = 0;
    string transaction;
    
    ifstream transactionFile("records.txt");
    while (getline(transactionFile, transaction)) {
        recentTransactions[totalEntries % 10] = transaction;
        totalEntries++;
    }
    
    int startIndex = (totalEntries > 10) ? totalEntries % 10 : 0;
    int limit = (totalEntries > 10) ? 10 : totalEntries;
    
    for (int i = 0; i < limit; i++) {
        cout << recentTransactions[(startIndex + i) % 10] << endl;
    }
}

int main()
{
    int userBalance = 0;
    int userChoice;
    
    ofstream transactionFile("records.txt", ios::trunc);
    transactionFile.close();
    

    cout << "Welcome to MyBank" << endl;
    
    do 
    {
        cout << "1. Deposit Funds" << endl;
        cout << "2. Withdraw Funds" << endl;
        cout << "3. View Last 10 Transactions" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch(userChoice)
        {
            case 1:
                addFunds(&userBalance);
                break;

            case 2:
                int withdrawAmount;
                cout << "Enter withdrawal amount: ";
                cin >> withdrawAmount;
                
                if (deductFunds(&userBalance, withdrawAmount))
                {
                    cout << withdrawAmount << " Rs withdrawn successfully." << endl;
                }
                else
                {
                    cout << "Insufficient balance.\n" << endl;
                }
                break;

            case 3:
                showLastTransactions();
                break;

            case 4:
                cout << "Exiting...";
                exit(0);
        }
    } while (1);
    
    return 0; 
}

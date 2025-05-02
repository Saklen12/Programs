#include <iostream>
#include<string>
#include<exception>
using namespace std;

class InsufficientFundsException : public exception{
	public:
	 virtual const char* what() const throw() {
    	return "InsufficientFund";
  }
};

class InvalidTransactionException : public exception{
	public:
	virtual const char* what() const throw() {
    	return "InvalidTransaction";
  }
};
class BankAccount{
	public:
    int  account_no;
    double balance;
        
        BankAccount(double bal):balance(bal){}
        
        void deposit(double amount){
            if(amount<0)
            {
                throw InvalidTransactionException();
            }else{
                balance+=amount;
                cout<< "Money deposited successfully and your balance is : "<< balance << endl;
            }
        }
        
        void withdraw(double amount){
               if(amount>balance){
                  throw InsufficientFundsException();
               }
			   else{
                   balance-=amount;
                   cout<< "Withdrawal Successfully" << endl;
           }
       }
       
       void transfer(BankAccount &to, double amount){
       	   this->withdraw(amount);
       	   to.deposit(amount);
       	   cout<<to.account_no;
           cout<< "Transfer Successfully" << endl;
       }  
       
       void divideBalance(double divisor){
           balance/=divisor;
           cout<< "Money Divided successfully and your balance is : "<< balance << endl;
       }
       
       void display(){
           cout<< "Your Currnt Balance is: "<< balance<<endl;
       }
       
      
};
     
int main()
{
    int choice;
    double amt;
    int no;
    BankAccount account(2000);
    BankAccount b(20000);
    do{
        cout<<"<-----------Bank Account----------->" << endl;
        cout << "1.Deposit" << endl;
        cout << "2.Withdraw" << endl;
        cout << "3.Divide Balance" << endl;
        cout << "4.Transfer" << endl;
        cout << "5.Display" << endl;
        cout<< "Enter your choice :" << endl;
        cin>> choice ;   
        
        switch(choice){
            case 1:	try {
				  	cout<<"Enter Deposit Amount:"<<endl;
                    cin>>amt;
                    b.deposit(amt); 
				  } catch (InvalidTransactionException& e) {
				     cout<< "Error: " << e.what() << std::endl;
				  }
            case 2:
				try {
				  	cout<<"Enter Withdraw Amount:"<<endl;
				    cin>>amt;
					b.withdraw(amt);  
				  } catch (InsufficientFundsException& e) {
				     cout<< "Error: " << e.what() << std::endl;
				  }
  
                    break;
            case 3:cout<<"Enter Divisor Amount:"<<endl;
                    cin>>amt;
                    b.divideBalance(amt);
                    break;
            case 4:	cout<<"Enter Account No :"<<endl;
            		cin>>no;
            		account.account_no=no;
            		cout<<"Enter Amount :"<<endl;
            		cin>>amt;
            		b.transfer(account,amt);
                    break;
            case 5:b.display();
                   break;
        }
            
    }while(choice!=0);
    
    
    

    return 0;
}

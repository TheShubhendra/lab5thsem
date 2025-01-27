#include<iostream>

using namespace std;

class Account{
    private:
        string account_holder_name;
        float balance;
    
    public:
        Account(string name, float account){
            this->account_holder_name = name;
            this->balance = balance;
        }

        void deposit(float amount){
        balance += amount;
        }

        void withdraw(float amount){
            if(balance >= amount){
                balance -= amount;
            }
            
        }

        void account_details(){
            cout << "Name: " << account_holder_name << endl << "Balance: " << balance << endl ; 
        }
};



int main(){
    Account account1 = Account("Shubh", 433000.4);
    account1.deposit(500.0);
    account1.withdraw(50);
    account1.account_details();

    return 0;
}
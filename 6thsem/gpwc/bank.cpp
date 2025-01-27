#include<iostream>

using namespace std;

typedef struct{
    string account_holder_name;
    float balance;
    
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
} account_t;



int main(){
    account_t account1 = { "John Snow", 1000.0 };
    account1.deposit(500.0);
    account1.withdraw(50);
    account1.account_details();

    return 0;
}
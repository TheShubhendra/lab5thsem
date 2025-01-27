#include<stdio.h>

typedef struct {
    char* account_holder_name;
    float balance;
} account_t;

void deposit(account_t* account, float amount){
    account->balance += amount;
}

void withdraw(account_t* account, float amount){
    if(account->balance >= amount){
        account->balance -= amount;
    }
    
}

void account_details(account_t* account){
    printf("Name: %s\nBalance: %.2f\n", account->account_holder_name, account->balance); 
}

int main(){
    account_t account1 = { "John Snow", 1000.0 };
    deposit(&account1, 500.0);
    withdraw(&account1, 50);
    account_details(&account1);

    return 0;
}
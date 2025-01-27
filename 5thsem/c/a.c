#include<stdio.h>
#include<stdbool.h>

bool isPrime(int x){
    for(int i=2; i<x/2; i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

bool isPal(int x){
    int rev = 0;
    int temp=x;
    while(temp>0){
        rev*=10;
        rev+=(temp%10);
        temp/=10;
    }
    return rev==x;
}

int sum(int x){
    int res = 0;
    while(x>0){
        res+=(x%10);
        x/=10;
    }
    return res;
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(isPrime(n)){
        printf("%d is a prime number\n", n);
    }else{
        printf("%d is not a prime number\n", n);
    }
    if(isPal(n)){
        printf("%d is palindrome\n", n);
    }else{
        printf("%d is not a palindrome\n", n);
    }

    printf("Sum of digits: %d\n", sum(n));

    return 0;


}
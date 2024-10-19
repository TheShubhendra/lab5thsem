#include<stdio.h>
#include<stdlib.h>

void print_array(int* a, int n){
    for(int i=0; i<n; i++){
        int c = RAND_MAX/rand() + 31;
        printf("\033[%dm%d ",c, *(a+i));
    }
    printf("\n");
}


void fib(int* f0, int* f1, int n){
    if(n<2){
        printf("N should be greater than or equals to 2");
    }
    int arr[n];
    arr[0] = *f0;
    arr[1] = *f1;
    for(int i=2; i<n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    print_array(arr, n);

}


int main(){
    int a = 0;
    int b = 1;
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    fib(&a, &b, n);
    return 0;
}
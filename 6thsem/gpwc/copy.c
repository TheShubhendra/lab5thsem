#include<stdio.h>

int main(){
    int a = 10;
    int* ptr = &a;
    printf("%d %p %p\n", *ptr, ptr, &ptr);
    return 0;
}
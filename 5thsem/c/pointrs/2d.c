#include<stdio.h>

int main(){
    int arr[][4] = {
        {1, 3, 4, 3},
        {4, 6, 2,  3}
    };
    printf("%p\n", arr);
    printf("%p\n", *arr);
    printf("%p\n", *(arr+1));
    printf("%d\n", *(*(arr)+5));
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *array;

    array = (int*) calloc(5, sizeof(int));
    for (int i=0; i<5; i++){
        *(array+i) = i;
    }
    for (int i=0; i<5; i++){
        printf("%d ", *(array+i));
    }
    free(array);
}
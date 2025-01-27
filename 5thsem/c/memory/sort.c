#include<stdio.h>
#include<stdlib.h>

void sort(int* arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("What is length of the array: ");
    scanf("%d", &n);

    int* arr = (int *) malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }

    sort(arr,  n);
    for(int i=0; i<n; i++){
        printf("\033[%dm%d ",31 + i%10, arr[i]);
    }
    
    free(arr);
    return 0;


}
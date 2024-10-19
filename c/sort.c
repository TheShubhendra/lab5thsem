#include<stdio.h>

void bubbleSort(int* arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j = i; j<n; j++){
            if(*(arr+i)>*(arr+j)){
                int temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }
}

int main(){
    printf("Select 1 for bubble sort, 2 for binary search");
    int option;
    int n;
    int arr[1000];
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("Enter number of elements");
        scanf("%d", &n);
        printf("Enter numbers: ");
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        void bubbleSort(arr, n);
        for( int i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
        break;

    case 2:
        break;
    
    default:
        printf("Invalid choice");
        break;
    }
}
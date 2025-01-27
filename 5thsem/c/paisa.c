#include <stdio.h>

int main(){
    float amount = 100.80;
    float distance = 1.8;
    float fuel_price = 56;
    int vada_price = 35;
    printf("Remaning paisa: %f\n", (amount - (vada_price + (distance*fuel_price))));
    return 0;
}

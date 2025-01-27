#include<stdio.h>

int main(){
    printf("Welcome!!,  press 1 if you are graduate , 2 if postgraduate\n");
    int grad;
    int base, year;
    float da,hra, gross=0;
    scanf("%d", &grad);
    switch (grad)
    {
    case 1:
        base = 5000;
        hra = base*.2;
        da = base*.3;
        printf("From how many years you are working here?: ");
        scanf("%d", &year);
        year/=3;
        gross = base+hra+da;
        switch (year)
        {
        case 0:
            break;
        default:
            gross += 2500;
            break;
        }
    printf("Your sallary is %.2f\n", gross);
        break;
    case 2:
        base = 6000;
        hra = base*.3;
        da = base*.4;
        printf("From how many years you are working here?: ");
        scanf("%d", &year);
        year/=3;
        switch (year)
        {
        case 0:
            gross = base+hra+da;
            break;
        default:
            gross = base+hra+da + 2500;
            break;
        }
        printf("Your sallary is %.2f\n", gross);
        break;
    default:
        printf("Invalid input\n");
        break;
    }

    return 0;
}
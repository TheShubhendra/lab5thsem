#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter size of the string: ");
    scanf("%d", &n);
    char *s = (char *) calloc(n, n*sizeof(char));
    scanf("%[^\n]s", s);
    // char s[] = "Hellow";
    int l=0,r=strlen(s)-1;


    puts(s);
    while(l<r){
        s[l] = s[l] + s[r];
        s[r] = s[l] - s[r];
        s[l] = s[l] - s[r];
        l++,r--;
    }
    puts(s);
}
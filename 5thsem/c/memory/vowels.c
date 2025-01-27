#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("\033[34m");
    system("cowsay Welcome");

    int n;
    printf("What is length of the sentence: ");
    scanf("%d", &n);
    printf("Enter your sentence: ");
    char* sen = (char *) malloc((n+1) * sizeof(char));
    char ch;
    getchar();
    for(int i=0; i<n; i++){
        scanf("%c", &ch);
        if(ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            ch = ch-32;
        }
        *(sen+i) = ch;
    }
    *(sen+n) = '\0';

   printf("%s\n", sen);
    
    free(sen);
    return 0;


}

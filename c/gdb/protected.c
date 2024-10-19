#include<stdio.h>
#include<string.h>

int main(){
	char pass[50];
	printf("Hi, This file contains highly classified information, Enter  your password: ");
	scanf("%s",pass);
	if(strcmp(pass, "H3LL0")){
		printf("Cracked");
	}else{
		printf("Invalid password");
	}
	return 0;
}

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


void main(){
	if(fork() || fork()){
		printf("Hello\n");
	}
}

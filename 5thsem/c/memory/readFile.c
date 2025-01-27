#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 100

int main(int argc, char* argv[]){
	if(argc<2){
	    perror("No file provided");
	    exit(0);
	}
	char* file_path = argv[1];
	printf("%s\n", file_path);
	FILE* fptr = fopen(file_path, "r");
	if (fptr == NULL){
		perror("Failed to open this file");
		exit(1);	
	}

	char buffer[BUFFER_SIZE];
 	size_t bytes_read;
	char* content = NULL;
	size_t total_size = 0;
	while( (bytes_read = fread(buffer, 1, BUFFER_SIZE, fptr)) > 0){
		total_size+=bytes_read;
		printf("total %ld\n", total_size);
		if( (content = realloc(content, total_size+1)) == NULL){
			perror("Failed to allocate memory");
			exit(1);
			}
		memcpy(content + total_size - bytes_read, buffer, bytes_read);
		printf("%ld bytes read | Total bytes: %ld\n", bytes_read, total_size);
	}
	printf("%s", content);
	fclose(fptr);
	free(content);

	return 0;
}

    

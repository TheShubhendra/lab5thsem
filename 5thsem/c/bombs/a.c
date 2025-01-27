#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>


int main() {
    printf("Running a.c\n"); 
    pid_t id = fork();
    if (id == 0 && execl("/home/student/theshubhendra/c/bombs/b", "b", NULL) == -1) {
        perror("execl failed in a.c");
    }
    return 0;
}


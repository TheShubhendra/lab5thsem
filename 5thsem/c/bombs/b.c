#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    printf("Running b.c\n");
    pid_t id = fork();
    if (id==0 && execl("/home/student/theshubhendra/c/bombs/a", "a", NULL) == -1) {
        perror("execl failed in b.c");
    }
    return 0;
}


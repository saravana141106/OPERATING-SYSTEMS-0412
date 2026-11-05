#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    printf("Parent process: PID=%d\n", getpid());
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();
        if (pid < 0) { perror("fork"); return 1; }
        if (pid == 0) {
            printf("Child %d: PID=%d, PPID=%d\n", i, getpid(), getppid());
            fflush(stdout);
            _exit(0);
        }
    }
    while (wait(NULL) > 0) { }
    printf("Parent: all children completed.\n");
    return 0;
}

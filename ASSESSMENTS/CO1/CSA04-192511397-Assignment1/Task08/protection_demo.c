/* Demonstrates process address-space isolation at a conceptual level. */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
    int value = 10;
    pid_t p = fork();
    if (p < 0) return 1;
    if (p == 0) { value = 99; printf("child value=%d\n", value); return 0; }
    waitpid(p, NULL, 0);
    printf("parent value=%d\n", value);
    return 0;
}

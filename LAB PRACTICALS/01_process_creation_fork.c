/* Lab program: 01_process_creation_fork */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
pid_t pid;
pid = fork();
if (pid == 0)
{
printf("Child Process ID: %d\n", getpid());
printf("Parent Process ID: %d\n", getppid());
}
else if (pid> 0)
{
printf("Parent Process ID: %d\n", getpid());
}
else
{
printf("Process creation failed\n");
}
return 0;
}

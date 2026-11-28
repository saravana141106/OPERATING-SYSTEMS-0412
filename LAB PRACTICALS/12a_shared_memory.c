/* Lab program: 12a_shared_memory */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
int shmid;
char *ptr;
char message[] = "Hello, shared memory!";
shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
if (shmid == -1)
{
perror("shmget");
return 1;
}
ptr = (char *)shmat(shmid, NULL, 0);
if (ptr == (char *)-1)
{
perror("shmat");
shmctl(shmid, IPC_RMID, NULL);
return 1;
}
strcpy(ptr, message);
printf("Data written to shared memory: %s\n", ptr);
printf("Data read from shared memory: %s\n", ptr);
shmdt(ptr);
shmctl(shmid, IPC_RMID, NULL);
return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void){
    int fd[2]; int readings[]={31,33,36,34,41,41}; int n=6;
    if(pipe(fd)==-1){perror("pipe");return 1;}
    pid_t pid=fork();
    if(pid<0){perror("fork");return 1;}
    if(pid==0){
        close(fd[1]); int value,count=0,sum=0;
        while(read(fd[0],&value,sizeof(value))>0){printf("analyser: reading %d\n",value);sum+=value;count++;}
        close(fd[0]);
        printf("analyser: count=%d average=%.1f\n",count,(double)sum/count);
        fflush(stdout);
        _exit(0);
    } else {
        close(fd[0]);
        for(int i=0;i<n;i++) if(write(fd[1],&readings[i],sizeof(int))!=sizeof(int)){perror("write");}
        close(fd[1]); /* EOF tells the child that no more data will arrive. */
        wait(NULL); printf("reader: done\n");
    }
    return 0;
}

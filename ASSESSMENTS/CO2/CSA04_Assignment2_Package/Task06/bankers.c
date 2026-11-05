#include <stdio.h>
#define P 5
#define R 3

int allocation[P][R]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int maximum[P][R]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int available[R]={3,3,2};

int safety(int seq[P]){
    int work[R],finish[P]={0},count=0;
    for(int r=0;r<R;r++) work[r]=available[r];
    while(count<P){
        int found=0;
        for(int p=0;p<P;p++) if(!finish[p]){
            int possible=1;
            for(int r=0;r<R;r++) if(maximum[p][r]-allocation[p][r]>work[r]) possible=0;
            if(possible){
                for(int r=0;r<R;r++) work[r]+=allocation[p][r];
                seq[count++]=p; finish[p]=1; found=1;
            }
        }
        if(!found) return 0;
    }
    return 1;
}
int request_resources(int p,int req[R]){
    int seq[P];
    for(int r=0;r<R;r++){
        if(req[r]>maximum[p][r]-allocation[p][r]) return -1;
        if(req[r]>available[r]) return 0;
    }
    for(int r=0;r<R;r++){available[r]-=req[r];allocation[p][r]+=req[r];}
    if(safety(seq)){printf("Request by P%d granted; safe sequence:",p);for(int i=0;i<P;i++)printf(" P%d",seq[i]);puts("");return 1;}
    for(int r=0;r<R;r++){available[r]+=req[r];allocation[p][r]-=req[r];}
    puts("Request denied: state would be unsafe."); return 0;
}
int main(void){
    int seq[P];
    if(safety(seq)){printf("Initial state is SAFE. Sequence:");for(int i=0;i<P;i++)printf(" P%d",seq[i]);puts("");}
    else puts("Initial state is UNSAFE.");
    int req1[R]={1,0,2}; puts("Request P1 = (1,0,2):"); request_resources(1,req1);
    int req2[R]={3,3,0}; puts("Request P4 = (3,3,0):"); request_resources(4,req2);
    return 0;
}

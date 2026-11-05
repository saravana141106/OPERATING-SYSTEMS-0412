#include <stdio.h>
#include <stdlib.h>
#define N 4

typedef struct { int id, at, bt, pr; } Job;
Job jobs[N] = {{1,0,5,2},{2,1,3,1},{3,2,8,3},{4,3,6,2}};

void print_metrics(const char *name, int finish[], int first[]) {
    double aw=0, atat=0, art=0;
    printf("\n%s\n", name);
    printf("Process  AT  BT  CT  TAT  WT  RT\n");
    for(int i=0;i<N;i++){
        int tat=finish[i]-jobs[i].at, wt=tat-jobs[i].bt, rt=first[i]-jobs[i].at;
        aw+=wt; atat+=tat; art+=rt;
        printf("P%d       %d   %d   %d   %d    %d   %d\n",jobs[i].id,jobs[i].at,jobs[i].bt,finish[i],tat,wt,rt);
    }
    printf("Average WT=%.2f, Average TAT=%.2f, Average RT=%.2f\n",aw/N,atat/N,art/N);
}
void fcfs(void){
    int f[N], first[N], t=0;
    printf("\nFCFS Gantt: ");
    for(int i=0;i<N;i++){ if(t<jobs[i].at)t=jobs[i].at; first[i]=t; printf("| P%d %d-%d ",jobs[i].id,t,t+jobs[i].bt); t+=jobs[i].bt; f[i]=t; }
    puts("|"); print_metrics("FCFS metrics",f,first);
}
void sjf(void){
    int done[N]={0}, f[N], first[N], t=0;
    printf("\nNon-preemptive SJF Gantt: ");
    for(int k=0;k<N;k++){
        int p=-1;
        for(int i=0;i<N;i++) if(!done[i] && jobs[i].at<=t && (p<0 || jobs[i].bt<jobs[p].bt)) p=i;
        if(p<0){t++;k--;continue;}
        first[p]=t; printf("| P%d %d-%d ",jobs[p].id,t,t+jobs[p].bt); t+=jobs[p].bt; f[p]=t; done[p]=1;
    }
    puts("|"); print_metrics("SJF metrics",f,first);
}
void srtf(void){
    int rem[N], f[N]={0}, first[N], seen[N]={0}, t=0, done=0, prev=-1;
    for(int i=0;i<N;i++) rem[i]=jobs[i].bt;
    printf("\nSRTF timeline: ");
    while(done<N){
        int p=-1;
        for(int i=0;i<N;i++) if(jobs[i].at<=t && rem[i]>0 && (p<0 || rem[i]<rem[p])) p=i;
        if(p<0){t++;continue;}
        if(!seen[p]){first[p]=t;seen[p]=1;}
        if(p!=prev){printf("| P%d@%d ",jobs[p].id,t);prev=p;}
        rem[p]--; t++;
        if(rem[p]==0){f[p]=t;done++;}
    }
    printf("| end %d\n",t); print_metrics("SRTF metrics",f,first);
}
void priority_np(void){
    int done[N]={0}, f[N], first[N], t=0;
    printf("\nNon-preemptive Priority (1=highest) Gantt: ");
    for(int k=0;k<N;k++){
        int p=-1;
        for(int i=0;i<N;i++) if(!done[i] && jobs[i].at<=t && (p<0 || jobs[i].pr<jobs[p].pr)) p=i;
        if(p<0){t++;k--;continue;}
        first[p]=t; printf("| P%d %d-%d ",jobs[p].id,t,t+jobs[p].bt); t+=jobs[p].bt; f[p]=t; done[p]=1;
    }
    puts("|"); print_metrics("Priority metrics",f,first);
}
void rr(int q){
    int rem[N], f[N]={0}, first[N], seen[N]={0}, added[N]={0}, queue[1000], head=0,tail=0,t=0,done=0;
    for(int i=0;i<N;i++) rem[i]=jobs[i].bt;
    printf("\nRound Robin q=%d Gantt: ",q);
    while(done<N){
        for(int i=0;i<N;i++) if(!added[i] && jobs[i].at<=t){queue[tail++]=i;added[i]=1;}
        if(head==tail){t++;continue;}
        int p=queue[head++];
        if(!seen[p]){first[p]=t;seen[p]=1;}
        int run= rem[p]<q ? rem[p] : q;
        printf("| P%d %d-%d ",jobs[p].id,t,t+run);
        t+=run; rem[p]-=run;
        for(int i=0;i<N;i++) if(!added[i] && jobs[i].at<=t){queue[tail++]=i;added[i]=1;}
        if(rem[p]>0) queue[tail++]=p; else {f[p]=t;done++;}
    }
    puts("|"); print_metrics("Round Robin metrics",f,first);
}
int main(int argc,char **argv){
    int q=3; if(argc>1) q=atoi(argv[1]); if(q<1) q=3;
    fcfs(); sjf(); srtf(); priority_np(); rr(q);
    return 0;
}

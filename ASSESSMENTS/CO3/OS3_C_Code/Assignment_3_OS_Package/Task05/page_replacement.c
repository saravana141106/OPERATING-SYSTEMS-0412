#include <stdio.h>
#define MAX 100
int find(const int f[], int n, int p) {
    for (int i=0;i<n;i++) if (f[i]==p) return i;
    return -1;
}
int fifo(const int r[], int n, int cap) {
    int f[10], used=0, next=0, faults=0;
    for(int i=0;i<n;i++) {
        if(find(f,used,r[i])>=0) continue;
        faults++;
        if(used<cap) f[used++]=r[i];
        else { f[next]=r[i]; next=(next+1)%cap; }
    }
    return faults;
}
int lru(const int r[], int n, int cap) {
    int f[10], last[10], used=0, faults=0;
    for(int i=0;i<n;i++) {
        int k=find(f,used,r[i]);
        if(k>=0) { last[k]=i; continue; }
        faults++;
        if(used<cap) { f[used]=r[i]; last[used++]=i; }
        else {
            int v=0;
            for(int j=1;j<cap;j++) if(last[j]<last[v]) v=j;
            f[v]=r[i]; last[v]=i;
        }
    }
    return faults;
}
int optimal(const int r[], int n, int cap) {
    int f[10], used=0, faults=0;
    for(int i=0;i<n;i++) {
        if(find(f,used,r[i])>=0) continue;
        faults++;
        if(used<cap) { f[used++]=r[i]; continue; }
        int victim=0, farthest=-1;
        for(int j=0;j<cap;j++) {
            int next=n;
            for(int k=i+1;k<n;k++) if(r[k]==f[j]) { next=k; break; }
            if(next>farthest) { farthest=next; victim=j; }
        }
        f[victim]=r[i];
    }
    return faults;
}
int main(void) {
    int ref[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int n=sizeof(ref)/sizeof(ref[0]);
    for(int c=3;c<=4;c++)
        printf("%d frames: FIFO=%d LRU=%d Optimal=%d\n",c,
               fifo(ref,n,c),lru(ref,n,c),optimal(ref,n,c));
    int belady[]={1,2,3,4,1,2,5,1,2,3,4,5};
    printf("Belady string FIFO: 3 frames=%d, 4 frames=%d\n",
           fifo(belady,12,3),fifo(belady,12,4));
    return 0;
}

#include <stdio.h>
typedef struct { int base, limit; } Segment;
int main(void) {
    Segment table[] = {{1000, 400}, {3000, 800}, {5000, 600}};
    int tests[][2] = {{0,100},{0,450},{1,799},{2,600},{2,20},{1,0},{0,399},{2,599}};
    for (int i=0;i<8;i++) {
        int s=tests[i][0], off=tests[i][1];
        if (s<0 || s>=3 || off<0 || off>=table[s].limit)
            printf("Segment %d offset %d: protection fault\n",s,off);
        else printf("Segment %d offset %d: physical address %d\n",s,off,table[s].base+off);
    }
    return 0;
}

#include <stdio.h>
int main(void) {
    /* Example memory budget for a 2 GB edge device (values in MB). */
    int ram=2048, realtime=256, ml=1536, logging=128, reserve=128;
    int total=realtime+ml+logging+reserve;
    printf("RAM=%d MB; real-time=%d; ML=%d; logging=%d; reserve=%d\n",
           ram,realtime,ml,logging,reserve);
    printf("Planned=%d MB: %s\n",total,total<=ram?"fits":"exceeds RAM");
    return 0;
}

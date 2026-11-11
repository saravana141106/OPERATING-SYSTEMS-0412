#include <stdio.h>
int main(void) {
    double disk=4.0; int n=6;
    printf("Six 4 TB disks (decimal capacity):\n");
    printf("RAID 0: %.0f TB usable; no redundancy\n",n*disk);
    printf("RAID 1 (three mirrored pairs): %.0f TB usable\n",(n/2)*disk);
    printf("RAID 5: %.0f TB usable; one-disk parity\n",(n-1)*disk);
    printf("RAID 6: %.0f TB usable; two-disk parity\n",(n-2)*disk);
    printf("RAID 10: %.0f TB usable; mirrored pairs striped\n",(n/2)*disk);
    return 0;
}
/* Linux inspection commands: lsblk; sudo fdisk -l; swapon --show */

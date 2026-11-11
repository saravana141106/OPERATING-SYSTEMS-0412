#include <stdio.h>
int main(void) {
    const double memory_ns=100.0, fault_ms=8.0;
    double rates[] = {1.0/1000, 1.0/100000, 1.0/1000000};
    for (int i=0;i<3;i++) {
        double p=rates[i];
        double eat=(1-p)*memory_ns + p*(fault_ms*1000000.0 + memory_ns);
        printf("Page fault rate 1/%.0f: EAT = %.3f ns\n",1.0/p,eat);
    }
    return 0;
}
/* Page-fault rate p: EAT = (1-p)*100 ns + p*(8 ms + 100 ns). */

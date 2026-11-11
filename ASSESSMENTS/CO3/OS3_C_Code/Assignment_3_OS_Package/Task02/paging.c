#include <stdio.h>
#define PAGE_SIZE 1024
#define PAGE_COUNT 8
int page_table[PAGE_COUNT] = {5, 2, -1, 7, 1, -1, 4, 6};
int main(void) {
    int addresses[] = {1500, 3100, 6200, 9000, 2049};
    int n = sizeof(addresses)/sizeof(addresses[0]);
    for (int i=0; i<n; i++) {
        int a=addresses[i], page=a/PAGE_SIZE, offset=a%PAGE_SIZE;
        if (page >= PAGE_COUNT) printf("%d: invalid address\n", a);
        else if (page_table[page] == -1) printf("%d: page fault\n", a);
        else printf("%d: physical address = %d\n", a, page_table[page]*PAGE_SIZE+offset);
    }
    return 0;
}

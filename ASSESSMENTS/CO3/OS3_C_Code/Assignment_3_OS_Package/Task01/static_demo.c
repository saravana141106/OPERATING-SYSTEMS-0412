#include <stdio.h>
static void encrypt_text(const char *s) {
    while (*s) putchar(*s++ + 1);
    putchar('\n');
}
int main(void) { encrypt_text("BANK"); return 0; }
/* Build: gcc static_demo.c -o static_demo
   Compare: ls -l static_demo dynamic_app; ldd dynamic_app
   Maps: cat /proc/$(pidof dynamic_app)/maps while program is running. */

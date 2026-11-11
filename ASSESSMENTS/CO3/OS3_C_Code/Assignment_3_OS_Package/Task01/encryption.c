#include <stdio.h>
#include <string.h>
/* Build as shared library: gcc -fPIC -shared encryption.c -o libencrypt.so */
void encrypt_text(const char *s) {
    while (*s) putchar(*s++ + 1);
    putchar('\n');
}

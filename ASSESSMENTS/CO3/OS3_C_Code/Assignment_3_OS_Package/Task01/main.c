#include <stdio.h>
#include <dlfcn.h>
typedef void (*encrypt_fn)(const char *);
int main(void) {
    void *h = dlopen("./libencrypt.so", RTLD_LAZY);
    if (!h) { fprintf(stderr, "Cannot load library: %s\n", dlerror()); return 1; }
    dlerror();
    encrypt_fn fn = (encrypt_fn)dlsym(h, "encrypt_text");
    const char *e = dlerror();
    if (e) { fprintf(stderr, "Symbol error: %s\n", e); dlclose(h); return 1; }
    printf("Encrypted text: ");
    fn("BANK");
    dlclose(h);
    return 0;
}
/* Build: gcc main.c -o dynamic_app -ldl
   Run: gcc -fPIC -shared encryption.c -o libencrypt.so
        ./dynamic_app */

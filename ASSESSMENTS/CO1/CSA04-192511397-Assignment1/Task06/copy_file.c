#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

static long long copy_file(const char *src, const char *dst, size_t bufsize)
{
    char *buf = malloc(bufsize);
    if (!buf) return -1;
    int in = open(src, O_RDONLY);
    if (in < 0) { free(buf); return -1; }
    int out = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) { close(in); free(buf); return -1; }

    long long calls = 0;
    for (;;) {
        ssize_t n;
        do { n = read(in, buf, bufsize); } while (n < 0 && errno == EINTR);
        calls++;
        if (n == 0) break;
        if (n < 0) { calls = -1; break; }
        ssize_t done = 0;
        while (done < n) {
            ssize_t w;
            do { w = write(out, buf + done, (size_t)(n - done)); }
            while (w < 0 && errno == EINTR);
            if (w <= 0) { calls = -1; break; }
            done += w;
        }
        if (calls < 0) break;
    }
    close(in);
    close(out);
    free(buf);
    return calls;
}

int main(void)
{
    FILE *f = fopen("records.dat", "w");
    if (!f) { perror("fopen"); return 1; }
    for (int i = 0; i < 10000; i++) fputc('A' + i % 26, f);
    fclose(f);

    size_t sizes[] = {1, 512, 4096};
    for (size_t i = 0; i < 3; i++) {
        long long calls = copy_file("records.dat", "copy.dat", sizes[i]);
        if (calls < 0) { perror("copy_file"); return 1; }
        printf("buffer %zu bytes: %lld read() calls\\n", sizes[i], calls);
    }
    unlink("records.dat");
    unlink("copy.dat");
    return 0;
}

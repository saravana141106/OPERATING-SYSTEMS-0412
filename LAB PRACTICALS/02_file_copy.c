/* Lab program: 02_file_copy */
/* Q2: Copy the content of one file to another using file operations */
#include <stdio.h>

int main(void)
{
    FILE *src, *dst;
    int ch;
    char text[200];

    /* create a source file from user input */
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    src = fopen("source.txt", "w");
    if (src == NULL) { perror("source.txt"); return 1; }
    fputs(text, src);
    fclose(src);

    /* copy source.txt -> destination.txt character by character */
    src = fopen("source.txt", "r");
    dst = fopen("destination.txt", "w");
    if (src == NULL || dst == NULL) { perror("fopen"); return 1; }
    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dst);
    fclose(src);
    fclose(dst);

    printf("File copied successfully\n");
    return 0;
}

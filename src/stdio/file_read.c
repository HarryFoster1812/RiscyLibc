#include <internal/io.h>
#include <stdio.h>
int fgetc(FILE *f)
{
    unsigned char c;
    if (read(f->fd, &c, 1) != 1)
        return EOF;
    return c;
}

int getchar(void)
{
    unsigned char c;
    if (read(stdin, &c, 1) != 1)
        return EOF;
    return c;
}

char *fgets(char *s, int n, FILE *f)
{
    int i = 0;
    unsigned char c;

    if (n <= 0) return NULL;

    while (i < n - 1)
    {
        if (read(f->fd, &c, 1) != 1)
            break;

        s[i++] = c;

        if (c == '\n')
            break;
    }

    if (i == 0)
        return NULL;

    s[i] = '\0';
    return s;
}

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f)
{
    return read(f->fd, ptr, size * nmemb);
}

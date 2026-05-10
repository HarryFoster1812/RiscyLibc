#include <internal/io.h>
#include <stdio.h>

int fputc(int c, FILE *f)
{
    unsigned char ch = (unsigned char)c;
    if (write(f->fd, &ch, 1) != 1)
        return EOF;
    return c;
}

int fputs(const char *s, FILE *f)
{
    size_t len = 0;
    while (s[len]) len++;

    return write(f->fd, s, len) == len ? 0 : EOF;
}

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f)
{
    return write(f->fd, ptr, size * nmemb) / size;
}

static void print_int(int x)
{
    char buf[16];
    int i = 0;

    if (x == 0) {
        putchar('0');
        return;
    }

    if (x < 0) {
        putchar('-');
        x = -x;
    }

    while (x > 0) {
        buf[i++] = '0' + (x % 10);
        x /= 10;
    }

    while (i--)
        putchar(buf[i]);
}


int putchar(int ch){
	return write(stdout, &ch, 1);
}

int printf(const char *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);

    for (int i = 0; fmt[i]; i++)
    {
        if (fmt[i] != '%') {
            putchar(fmt[i]);
            continue;
        }

        i++;
        switch (fmt[i])
        {
            case 'd': print_int(__builtin_va_arg(ap, int)); break;
            case 'c': putchar(__builtin_va_arg(ap, int)); break;
            case 's': {
                char *s = __builtin_va_arg(ap, char*);
                while (*s) putchar(*s++);
                break;
            }
        }
    }

    __builtin_va_end(ap);
    return 0;
}

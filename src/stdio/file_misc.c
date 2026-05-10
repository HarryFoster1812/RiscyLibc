#include "internal/syscall.h"
#include <internal/io.h>
#include <stdio.h>
#include <stdlib.h>

FILE *fopen(const char *path, const char *mode)
{
    int fd = syscall(SYS_open, path, 'r');
    if (fd < 0)
        return NULL;

    FILE *f = malloc(sizeof(FILE)); // or slab alloc
    if (!f) return NULL;

    f->fd = fd;
    return f;
}

int fclose(FILE * file) {
    if (file->fd < 0)
        return EOF;
    int fd = syscall(SYS_close, file->fd);

    free(file);
		return 0;
}


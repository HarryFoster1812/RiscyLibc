/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __STDIO_H__
#define __STDIO_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef struct {
   int fd;			/* File descriptor */
   unsigned char *buf;	/* Buffer */
   size_t size;		/* Size of the file */
   size_t pos;		/* Current position in the file */
} FILE;

#define BUFSIZ 512
#define EOF (-1)

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define stdin 0
#define stdout 1
#define stderr 2

void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE * restrict, fpos_t * restrict);
char *fgets(char * restrict, int, FILE * restrict);
FILE *fopen(const char * restrict, const char * restrict);
int fprintf(FILE * restrict, const char * restrict, ...);
int fputc(int, FILE *);
int fputs(const char * restrict, FILE * restrict);
size_t fread(void * restrict, size_t, size_t, FILE * restrict);
FILE *freopen(const char * restrict, const char * restrict, FILE * restrict);
int fscanf(FILE * restrict, const char * restrict, ...);
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void * restrict, size_t, size_t, FILE * restrict);
int getc(FILE *);
int getchar(void);
char *gets(char *);
void perror(const char *);
int printf(const char * restrict, ...);
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename(const char *, const char *);
void rewind(FILE *);
int scanf(const char * restrict, ...);
void setbuf(FILE * restrict, char * restrict);
int setvbuf(FILE * restrict, char * restrict, int, size_t);
int sprintf(char * restrict, const char * restrict, ...);
int sscanf(const char * restrict, const char * restrict, ...);
FILE *tmpfile(void);
char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE * restrict, const char * restrict, va_list);
int vprintf(const char * restrict, va_list);
int vsprintf(char * restrict, const char * restrict, va_list);

#ifdef __cplusplus
}
#endif

#endif

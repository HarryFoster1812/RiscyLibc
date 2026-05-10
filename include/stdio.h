/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __STDIO_H__
#define __STDIO_H__	1

#include <stddef.h>

typedef struct {
   int fd;
} FILE;

typedef int fpos_t;

#define BUFSIZ 512
#define EOF (-1)

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define stdin 0
#define stdout 1
#define stderr 2

// FILE OPS
int fclose(FILE *);
FILE *fopen(const char * , const char * );

int fgetc(FILE *);
char *fgets(char * , int, FILE * );
size_t fread(void * , size_t, size_t, FILE * );
int fscanf(FILE * , const char * , ...);


int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);

size_t fwrite(const void * , size_t, size_t, FILE * );
int fprintf(FILE * , const char * , ...);
int fputc(int, FILE *);
int fputs(const char * , FILE * );

int getc(FILE *); 
int getchar(void);
char *gets(char *);
void perror(const char *);
int printf(const char * , ...);
int putc(int, FILE *);
int putchar(int);
int puts(const char *);

// file ops (not supported)
//int remove(const char *);
//int rename(const char *, const char *);
//void rewind(FILE *);

int scanf(const char * , ...);
int sprintf(char * , const char * , ...);
int sscanf(const char * , const char * , ...);

#endif

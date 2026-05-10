#include "internal/types.h"
#include <string.h>


char *strcpy(char *destination, const char *source) {
	char* ret = destination;
	while(*source) {
		*destination = *source;
		source++;
		destination++;
	}

	*destination = *source;
	return ret;
}

char *strncpy(char *destination, const char *source, size_t len) {
	const char *s = source;
	unsigned int i = 0 , j = 0;
	while(i < len){
		*(destination + i) = *(s + j);
		i++;
		if(*(s + j))
			j++;
	}
	return destination;
}

char *strcat(char *destination, const char *source){return NULL;}
char *strncat(char *destination, const char *source, size_t len);

int strcmp(const char *str1, const char *str2){
}

char *strtok(char *str, const char *delim){
  static char* p;
  if (str) p=str;
  if (!p) return NULL;

  while (*p && strchr(delim, *p)) p++;
  if (*p == '\0') return NULL;
  char *start = p;

  // find end
  while (*p && !strchr(delim, *p)) p++;

  if (*p) {
    *p = '\0';
    p++;
  }

  return start;
}

int strncmp(const char *str1, const char *str2, size_t len){
	for(unsigned int i=0;i<len;i++){
		if (*str1 != *str2) return 0;
		str1++;
		str2++;
	}
	return 1;
}

size_t strlen(const char *str){
	size_t len = 0;
	while(*str != 0){
		len++;
		str++;
	}
	return len;
}

char *strchr(const char *str, int c){
  while(*str){
    if (*str == c) return str;
    str++;
  } 
  return NULL;
}

char *strrchr(const char *str, int c){}

char *strstr(const char *haystack, const char *needle){}

char *strrstr(const char *haystack, const char *needle){}

void *memcpy(void *destination, const void *source, size_t num){
	for(size_t i=0;i<num;++i){
		*((uint8_t*)destination+i) = *((uint8_t*)source+i);
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num){}

int memcmp(const void *ptr1, const void *ptr2, size_t num){
	for(size_t i=0;i<num;++i){
		uint8_t a = *((uint8_t*)ptr1+i);
		uint8_t b = *((uint8_t*)ptr2+i);
		if (a < b)
			return -1;
		else if (a > b)
			return 1;
		
	}
	// they are equal
	return 0;
}

void *memset(void *source, int value, size_t num){}

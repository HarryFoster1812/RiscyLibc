#include "string.h"


char *strcpy(char *destination, const char *source) {
	while(*source) {
		*destination = *source;
		source++;
		destination++;
	}

	*destination = *source;
	return destination;
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

char *strcat(char *destination, const char *source);
char *strncat(char *destination, const char *source, size_t len);

int strcmp(const char *str1, const char *str2){
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

char *strchr(const char *str, int c);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
char *strrstr(const char *haystack, const char *needle);
void *memcpy(void *destination, const void *source, size_t num);
void *memmove(void *destination, const void *source, size_t num);
int memcmp(const void *ptr1, const void *ptr2, size_t num);
void *memset(void *source, int value, size_t num);

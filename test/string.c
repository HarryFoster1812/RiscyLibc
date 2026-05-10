#include <assert.h>
#include <stdio.h>
#include "../include/string.h"

int main(){
  char str1[] = "Hello";
  char str2[] = "Hello, World";
  char a[512];

char* result = strcat(a, str1);
assert(strcmp(a, str1)==0);
return 0;
}

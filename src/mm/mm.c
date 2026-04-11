#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "sbrk.c"

typedef struct malloc_header {
    uint32_t size_and_flags;
    struct malloc_header* next;
} malloc_header_t;

static malloc_header_t* free_list = NULL;

#define USED_FLAG 1
#define NULL 0

#define GET_SIZE(h) ((h)->size_and_flags & ~USED_FLAG)
#define IS_USED(h)  ((h)->size_and_flags & USED_FLAG)

#define SET_USED(h) ((h)->size_and_flags |= USED_FLAG)
#define SET_FREE(h) ((h)->size_and_flags &= ~USED_FLAG)
#define SET_SIZE(h, s) ((h)->size_and_flags = (s) | ((h)->size_and_flags & USED_FLAG))

#define ALIGN8(x) ((x+7) & ~7)

malloc_header_t* find_free_block(size_t size) {
    malloc_header_t* curr = free_list;
    malloc_header_t* prev = NULL;

    while (curr) {
        if (!IS_USED(curr) && GET_SIZE(curr) >= size) {
            if (prev) prev->next = curr->next;
            else free_list = curr->next;
            return curr;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}

void *malloc(size_t size) {
    size_t aligned_size = ALIGN8(size);

    // Try reuse first
    malloc_header_t* header = find_free_block(aligned_size);
    if (header) {
        SET_USED(header);
        return (uint8_t*)header + sizeof(malloc_header_t);
    }

    // Otherwise grow heap
    void* block = sbrk(aligned_size + sizeof(malloc_header_t));
    if (block == (void*)-1) return NULL;

    header = (malloc_header_t*)block;
    SET_SIZE(header, aligned_size);
    SET_USED(header);

    return (uint8_t*)block + sizeof(malloc_header_t);
}


void free(void* ptr) {
    if (!ptr) return;

    malloc_header_t* header =
        (malloc_header_t*)((uint8_t*)ptr - sizeof(malloc_header_t));

    SET_FREE(header);

    // push into free list
    header->next = free_list;
    free_list = header;
}

void *calloc(size_t numobj, size_t size){
	void* mem = malloc(numobj*size);
	if(!mem)
		return NULL;

	memset(mem, 0, numobj * size);

	return mem;
}

void *realloc(void *ptr, size_t size){
	void* mem = malloc(size);
	if(!mem)
		return NULL;

	malloc_header_t* old_header = (malloc_header_t*)((uint8_t*)ptr - sizeof(malloc_header_t));
	size_t old_size = GET_SIZE(old_header);
	memcpy(mem, ptr, old_size < size ? old_size : size);

	free(ptr);
	return mem;
}

void *reallocarray(void *ptr, size_t numobj, size_t size){
	return realloc(ptr, numobj*size);
}

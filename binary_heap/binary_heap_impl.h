#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    void *arr;
    size_t nmemb;
    size_t N;
    bool (*compar)(const void*,const void*);
} binary_heap;

void binary_heap_init(binary_heap *p, size_t capacity, size_t nmemb,
            bool (*compar)(const void*,const void*) );
void swim(binary_heap *p, size_t k);
void sink(binary_heap *p, size_t k);
void binary_heap_free(binary_heap *p);
bool binary_heap_is_empty(binary_heap *p);
void binary_heap_del_max(binary_heap *p);
int *binary_heap_get_top_N(binary_heap *p, size_t N);

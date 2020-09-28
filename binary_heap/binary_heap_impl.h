/*
 * This implementation uses generic binary heap implementation using void* type.
 * This approach initially worked on different types but it has limitations, notably it only works on pointers,
 * so you can't pass primitive types directly to the insert function.
 * For example:
 *   binary_heap p;
 *   binary_heap_init(&p, 10, sizeof(int), compare);
 *   binary_heap_insert(&p, 4); // Error
 *
 * To overcome this limitation, we generate functions with preprocessors for the specific types we want.
 */

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

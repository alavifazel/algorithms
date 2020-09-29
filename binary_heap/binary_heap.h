/*
 * This code implements a generic binary heap using void* type.
 * This approach works on different types, but it has limitations. notably it only works on pointers of insertion;
 * i.e. you can't pass primitive types directly.
 * For example:
 *   binary_heap p;
 *   binary_heap_init(&p, 10, sizeof(int), compare);
 *   binary_heap_insert(&p, 4); // Error
 *
 * To overcome this limitation, we generate functions for the specific types we want with preprocessors.
 */

#ifndef BINARY_HEAP_HEADER
#define BINARY_HEAP_HEADER

#include "binary_heap_impl.h"

/* Caution: The code bellow only checks if the size of 'T' and 'nmemb' of the passed binary heap object are equal.
 * In other words, the code only inserts element if they have the right sizes. This would make unwanted results
 * if your compiler doesn't allocate different sizes for different types. To prevent this from happening we
 * added an assert function to check this condition in the 'binary_heap_init' function. Add your user-defined
 * type to the assert if you want to insert it's objects to a binary_heap.
 */

#define define_binary_heap_insert(T) \
void binary_heap_insert_##T(binary_heap *p, T item){ \
    if(p->nmemb != sizeof(T)) { \
        fprintf(stderr, "Size of T must be equal to the size of binary heap elements!\n"); \
        return; \
    } \
    p->N++; \
    void *ptr = malloc(sizeof(T)); \
    *((T*)ptr) = item; \
    memcpy(p->arr + p->nmemb*p->N, ptr, p->nmemb); \
    swim(p, p->N); \
    free(ptr); \
}

// User has to free the returned array.
#define define_binary_tree_get_top_N(T) \
T *binary_heap_get_top_N_##T(binary_heap *p, size_t N) { \
    T* tmp = (T*)malloc(p->nmemb * N); \
    for(size_t i = 1; i < N+1; ++i) { \
        memcpy(tmp, p->arr + p->nmemb, p->nmemb * N); \
    } \
    return tmp; \
}

define_binary_heap_insert(char)
define_binary_heap_insert(int)
define_binary_heap_insert(double)

define_binary_tree_get_top_N(char)
define_binary_tree_get_top_N(int)
define_binary_tree_get_top_N(double)

#endif

#ifndef BINARY_HEAP_HEADER
#define BINARY_HEAP_HEADER
#include "binary_heap_impl.h"

#define define_binary_heap_insert(T) \
void binary_heap_insert_##T(binary_heap *p, T item){ \
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
    T* tmp = malloc(p->nmemb * N); \
    for(size_t i = 1; i < N+1; ++i) { \
        memcpy(tmp + (i-1)*p->nmemb, p->arr + i*p->nmemb, p->nmemb); \
    } \
    return tmp; \
}

define_binary_heap_insert(char)
define_binary_heap_insert(int)
define_binary_heap_insert(float)
define_binary_heap_insert(double)
define_binary_heap_insert(bool)

define_binary_tree_get_top_N(char)
define_binary_tree_get_top_N(int)
define_binary_tree_get_top_N(float)
define_binary_tree_get_top_N(double)
define_binary_tree_get_top_N(bool)

#endif

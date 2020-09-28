/*
 * Binary heaps are used to implement 'priority queue' ADT.
 * A few jargons:
 * Binary Tree:
 * Complete Tree: Fully connected? (perfectly balanced) tree except for bottom level.
 *
 * Height of a complete tree with N nodes has lnN levels.
 */

#include <stdio.h>
#include "binary_heap.h"

bool compare(const void *a, const void *b)
{
  return *(double*)a < *(double*)b;
}

int main() {
    binary_heap p;
    binary_heap_init(&p, 20, sizeof(double), compare);

    binary_heap_insert_double(&p, 5);
    binary_heap_insert_double(&p, 6.5);
    binary_heap_insert_double(&p, 1.1);
    binary_heap_insert_double(&p, 86);
    binary_heap_insert_double(&p, 42.6);

    binary_heap_del_max(&p);

    for(size_t i = 1; i <= p.N; ++i) {
        printf("%f ", *(double*) (p.arr + i*p.nmemb));
    }

    printf("\n");

}

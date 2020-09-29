/* > Binary Heap implementation
 * Description> Binary heaps implements 'priority queue' ADT.
 */

#include <stdio.h>
#include "binary_heap.h"

bool compare_double(const void *a, const void *b);
bool compare_int(const void *a, const void *b);

int main() {
    // ________________________________________
    // testing for a binary heap with double type
    binary_heap p;
    binary_heap_init(&p, 20, sizeof(double), compare_double);

    binary_heap_insert_double(&p, 5);
    // binary_heap_insert_int(&p, 5); gives error (as it should).
    binary_heap_insert_double(&p, 6.5);
    binary_heap_insert_double(&p, 1.1);
    binary_heap_insert_double(&p, 86);
    binary_heap_insert_double(&p, 42.6);


    double* data_double = malloc(5 * sizeof(double));
    data_double = binary_heap_get_top_N_double(&p, 5);

    for(size_t i = 0; i < p.N; ++i) {
        printf("%f ", data_double[i]);
    }
    printf("\n");
    binary_heap_free(&p);
    free(data_double);

    // _____________________________________
    // testing for a binary heap with int type

    binary_heap p2;
    binary_heap_init(&p2, 20, sizeof(int), compare_int);

    binary_heap_insert_int(&p2, 5);
    binary_heap_insert_int(&p2, 6);
    binary_heap_insert_int(&p2, 1);
    binary_heap_insert_int(&p2, 86);
    binary_heap_insert_int(&p2, 42);


    int* data_int = malloc(5 * sizeof(int));
    data_int = binary_heap_get_top_N_int(&p2, 5);

    for(size_t i = 0; i < p2.N; ++i) {
        printf("%d    ", data_int[i]);
    }
    printf("\n");
    binary_heap_free(&p2);
    free(data_int);
}

bool compare_double(const void *a, const void *b)
{
  return *(double*)a < *(double*)b;
}

bool compare_int(const void *a, const void *b)
{
  return *(int*)a < *(int*)b;
}

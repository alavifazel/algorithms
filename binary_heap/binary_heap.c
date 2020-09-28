#include "binary_heap_impl.h"

void binary_heap_init(binary_heap *p, size_t capacity, size_t nmemb, bool (*compar)(const void*,const void*) ) {
    p->arr = malloc((capacity+1) * sizeof(nmemb));
    p->nmemb = nmemb;
    p->compar = compar;
    p->N = 0;
}

void binary_heap_free(binary_heap *p) {
    free(p->arr);
    p->nmemb = 0;
    p->compar = NULL;
    p->N = 0;
}

static void swap(void *arr, size_t nmemb, int a, int b) {
    void *tmp = malloc(nmemb);

    memcpy(tmp, arr + a*nmemb, nmemb);
    memcpy(arr + a*nmemb, arr + b*nmemb, nmemb);
    memcpy(arr + b*nmemb, tmp, nmemb);

    free(tmp);
}

void swim(binary_heap *p, size_t k) {
    while(k > 1 && p->compar(p->arr + p->nmemb*k/2, p->arr + p->nmemb*k)) {
        swap(p->arr, p->nmemb, k, k/2);
        k = k / 2;
    }
}

void sink(binary_heap *p, size_t k) {
    while(2*k <= p->N) {
        size_t tmp = 2*k;
        if(tmp < p->N && p->compar(p->arr + p->nmemb*tmp, p->arr + p->nmemb*(tmp+1))) tmp++;

        if(!p->compar(p->arr + k*p->nmemb, p->arr + tmp*p->nmemb)) break;
        else {
            swap(p->arr, p->nmemb, k, tmp);
            k = tmp;
        }
   }
}

bool binary_heap_is_empty(binary_heap *p) {
    return p->N == 0;
}

// Following function should be used with extra care. Remove the static attr to make it available outside of this file.
static void binary_heap_insert(binary_heap *p, void *item) {
    p->N++;
    memcpy(p->arr + p->nmemb*p->N, item, p->nmemb);
    swim(p, p->N);
}

void binary_heap_del_max(binary_heap *p) {
    swap(p->arr, p->nmemb, 1, p->N);
    p->N--;
    sink(p, 1);
}

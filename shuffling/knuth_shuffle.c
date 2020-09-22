/* > Knuth shuffle implementation
 *
 * Description: Fisher-Yates shuffle algorithm aka Knuth shuffle, is used for shuffling a set of objects and has a linear time complexity.
 * We loop through the array, and in each iteration we generate a random integer between 0 and i (the iteration variable), let's call this value 'x'.
 * Afterawrds we swap a[i] and a[x].
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(void *arr, size_t nmemb, int a, int b) {
    void *tmp = malloc(nmemb);

    memcpy(tmp, arr + a*nmemb, nmemb);
    memcpy(arr + a*nmemb, arr + b*nmemb, nmemb);
    memcpy(arr + b*nmemb, tmp, nmemb);
}

int rand_range_int(int min, int max) {
    return min + (int)(max * (rand() / (RAND_MAX+1.0)));
}

void shuffle(void *arr, size_t nmemb, size_t size) {
    for(int i = 0; i < size; ++i) {
        int tmp = rand_range_int(0, i + 1);
        swap(arr, nmemb, i, tmp);     
    } 
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); 
    int arr[] = {1,2,3,4,5,6,7};
    shuffle(arr, sizeof(int), 7);
    print_array(arr, 7);
}

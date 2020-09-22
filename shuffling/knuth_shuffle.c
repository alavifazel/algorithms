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

// Generic Knuth shuffle implementation that can work on array of objects with different types.
void shuffle(void *arr, size_t nmemb, size_t size) {
    for(int i = 0; i < size; ++i) {
        int tmp = rand_range_int(0, i + 1);
        swap(arr, nmemb, i, tmp);     
    } 
}

int main() {
    srand(time(NULL)); 
    
    // int array 
    int int_arr[] = {1,2,3,4,5,6,7};
    shuffle(int_arr, sizeof(int), 7);
    for(int i = 0; i < 7; ++i) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    // double array 
    double double_arr[] = {1.1, 1.2, 1.3, 2.1, 2.2, 2.3};
    shuffle(double_arr, sizeof(double), 6);
    for(int i = 0; i < 6; ++i) {
        printf("%f ", double_arr[i]);
    }
    printf("\n");
}

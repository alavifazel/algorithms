/* 
 * > Merge Sort implementation
 * Description>
 *  This algorithm essentially splits the data in half in each step. Example for an array with 8 elements:
 *                                                  _ 
 *                           8                       | 
 *                         /   \                     |
 *                        4     4                    |
 *                       / \    |\                   |  lgN levels
 *                      2   2   2 2                  |
 *                     / \ / \ / \ \\                |
 *                    1  1 1 1 1 1 1 1              _|
 *
 *  In each level, program recives two arrays and it 'merges' them by doing N comparisons at worst. Since the binary tree has 
 *  lgN levels, total steps needed to sort an array has NlgN steps. Formally:
 *
 *  Time complexity: At most it uses NlgN comparisons. 
 *  If D(N) satisfies D(N) = 2D(D/2) + N (for all N > 1) with D(1) = 0, then D(N) = NlgN
 *  
 *  Proof by induction:
 *      Induction hypothesis: D(N) = NlgN
 *      Is D(2N) = (2N)lg(2N)?
 *
 *  Steps:
 *      D(2N) = 2D(N) + 2N 
 *            = 2NlgN + 2N                  (By replacing D(N) with induction hypothesis D(N) = NlgN)
 *            = 2N(lg(2N-N)) + 2N
 *            = 2N(lg2N - lgN) + 2N
 *            = 2N(lg2N -  1 ) + 2N
 *            = 2N(lg2N) 
 *  
 *  In comparison to quick-sort, it uses more memory (equal to the size of the array we want to sort needed for the auxiliary array) hence it's not an in-place sorting algorithm;
 *  But unlike quick-sort it's a stable sorting algorithm and it preserves the order of keys with equal values. 
 *
 * Example of the recursive stack call:
 *
 *   merge_sort(arr,0,7);
 *   merge_sort(arr,0,3);
 *   merge_sort(arr,0,1);
 *   merge_sort(arr,0,0);
 *
 *   merge_sort(arr,0,7);
 *   merge_sort(arr,0,3);
 *   merge_sort(arr,0,1);
 *   merge_sort(arr,1,1);
 *
 *   merge_sort(arr,0,7);
 *   merge_sort(arr,0,3);
 *   merge_sort(arr,0,1);
 *   merg(0,1);
 *
 *   merge_sort(arr,0,7);
 *   merge_sort(arr,0,3);
 *   merge_sort(arr,2,3);
 *   merge_sort(arr,2,2);
 *
 *   merge_sort(arr,0,7);
 *   merge_sort(arr,0,3);
 *   merge_sort(arr,2,3);
 *   merge_sort(arr,3,3);
 *
 *   merge_sort(arr,0,7);
 *   merge_sort(arr,0,3);
 *   merge_sort(arr,2,3);
 *   merge(2,3);
 *
 *   merge_sort(arr,0,7);
 *   merge_sort(arr,0,3);
 *   merge(0,3)
 *
 *   .
 *   .
 *   .
 */

#include <stdlib.h>
#include <stdio.h>

void merge(int *arr, int *aux, int low, int mid, int high) {
    for(size_t i = low; i <= high; ++i)
        aux[i] = arr[i];
    
    // aux indices
    int i = low;
    int j = mid + 1;
    // arr index
    int k = low;

    while(i <= mid && j <= high) {
        if(aux[i] <= aux[j]) {
            arr[k] = aux[i];
            i++;
        } else {
            arr[k] = aux[j];
            j++;
        }
        k++;
    }
}

void merge_sort(int *arr, int *aux, size_t low, size_t high) {
    if(low < high) { // makes the base cases
        int mid = (low + high) / 2;
        merge_sort(arr, aux, low, mid);
        merge_sort(arr, aux, mid+1, high);

        merge(arr, aux, low, mid, high);
    }
}

void sort(int *arr, size_t size) {
    int *aux = malloc(size * sizeof(int));
    merge_sort(arr, aux, 0, size); 
    free(aux);
}

int main() {
    int arr[] = {1,5,3,6,3,2,6};
    sort(arr, 7);

    for(size_t i = 0; i < 7; ++i) {
        printf("%d ", arr[i]);
    } 
}

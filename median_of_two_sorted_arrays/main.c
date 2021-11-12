#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* arr1, int n1, int* arr2, int n2){
    int *mergedArr = malloc(sizeof(int) * (n1 + n2));
    size_t i = 0, j = 0, k = 0;
    double ans;
    while(i + j < n1 + n2) {
        if(i == n1) {
            mergedArr[k++] = arr2[j];
            j++;
            continue;
        }
        if(j == n2) {
            mergedArr[k++] = arr1[i];
            i++;
            continue;
        }
        if(arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i];
            i++;
        } else {
            mergedArr[k++] = arr2[j];
            j++;
        }
    }

     for(int k = 0; k < n1 + n2; k++) printf("%d ", mergedArr[k]);

    if((n1 + n2) % 2 == 0) {
        ans = (float)(mergedArr[(n1 + n2) / 2] + mergedArr[(n1 + n2) / 2 - 1]) / 2;

    } else {
        ans = mergedArr[(n1 + n2) / 2];
    }

    free(mergedArr);
    return ans;
}

int main()
{
    int arr1[32] = {1, 2};
    int arr2[32] = {3, 4};
    printf("%f\n", findMedianSortedArrays(arr1, 2, arr2, 2));

}

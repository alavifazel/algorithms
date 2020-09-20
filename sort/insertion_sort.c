/*
 * > Insertion sort implementation
 * 
 * Description:
 * 	Insetion sort depends on the initial order of data.
 * 	Best case:
 * 		If the array is sorted in ascending order, it takes N-1 steps to sort the array.
 *	Worst case:
 *		If the array is in descending order, it takes N^2/2 steps to sort the array (bottom half of a square matrix number of exchanges).
 *	Average:
 *		But for an array with randomly set elements, it takes in average, N^2/4 steps to sort the array (half of the bottom half of a square matrix of number of exchanges).
 * 
 */

#include <stdio.h>

void swap(int *arr, int a, int b) {
	int tmp = arr[a];
       	arr[a] = arr[b];
	arr[b] = tmp;	
}

void insertion_sort(int *arr, int size) {
	for(int i = 0; i < size; ++i) 
       		for(int j = i; j > 0; j--) 
			if(arr[j] < arr[j-1]) 
				swap(arr, j, j-1);
			else 
				break;
}

int main() {
	int arr[5] = {2,5,4,4,6};
	insertion_sort(arr, 5);
	
	for(int i = 0; i < 5; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

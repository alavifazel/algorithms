/*
 * > ShellSort implementation
 * Description: Shell sort is essentially insertion sort but with a sequence of "jumps" for swapping.
 * 
 */

#include <stdio.h>

void swap(int *arr, int a, int b) {
	int tmp = arr[a];
       	arr[a] = arr[b];
	arr[b] = tmp;	
}

void shellsort(int *arr, int size) {
	// First we find the maximum value in the increment sequence
	int h = 1;

	while(h < size/3)
		h = 3*h + 1;	// Knuth Sequence: 1, 4, 13, ...

	while(h >= 1) {
		for(int i = 0; i < size; ++i) {
			for(int j = i; j >= h;  j -= h) {
				if(arr[j] < arr[j-h]) {
					swap(arr, j, j-h);
                }
			}	
		}

		h = (h-1)/3;
	}
}

int main() {
	int arr[6] = {10,5,4,4,6,2};
	shellsort(arr, 6);
	
	for(int i = 0; i < 6; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

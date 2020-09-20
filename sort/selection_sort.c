/*
 * > Selection sort implementation
 *
 * Description: This algorithm uses (N-1) + (N-2) + ... + 1 + 0 steps of comparisons and N steps for exchanging.
 *
 * Worst case complexity: (N-1) + (N-2) + ... + 1 + 0 ~ N^2/2 -> O(N^2)
 *
 * Proof (by induction):
 *	We can write the sum as:
 *	S(N) = 1 + 2 + ... + (N-2) + (N-1)	
 *
 *	Let k = (N-1), we can write this expression as:
 *
 *	S(k) = 1 + 2 + ... + k
 *
 *	Let P(k) be the statement:
 *	
 *	P(k) = 1 + 2 + ... + k = k(k+1)/2
 *	
 *	To prove this we use mathematical induction:
 *
 *	1) Initial step:
 *		P(1) = 1 = 1(1+1)/2 = 1								(true)
 *	2) Inductive step: If P(k) is true, then for the same k is P(K+1) true?
 *		1 + 2 + ... + k + (k+1) = k(k+1)/2 + (k+1) = k(k+1)/2 + 2(k+1)/2 
 *					= [k(k+1)+2(k+1)] / 2 = [(k+1)(k+2)]/2 = P(k+2)		(true) 
 *	
 *	Now that we have proved that statement P(k) is true, let's substitute k = (N-1):
 *		P(N) = 1 + 2 + ... + N-1 = (N-1)(N)/2 ~ N^2/2 
 *
 *
 */

#include <stdio.h>

void swap(int *arr, int a, int b) {
	int tmp = arr[a];
       	arr[a] = arr[b];
	arr[b] = tmp;	
}

void selection_sort(int *arr, int size) {
	for(int i = 0; i < size; ++i) {
		int max_elem_index = i;
		for(int j = i+1; j < size; ++j) {
			if(arr[j] < arr[max_elem_index]) {
				max_elem_index = j;
			}
		}
		swap(arr, i, max_elem_index);
	}
}

int main() {
	int arr[5] = {23,3,3,5,36};
	selection_sort(arr, 5);
	
	for(int i = 0; i < 5; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

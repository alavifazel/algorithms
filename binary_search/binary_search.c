/*
 * > Binary search algorithm 
 */
#include <stdio.h>

int binary_search(int sorted_arr[], int size, int key) {
	int first_pos = 0;
	int last_pos = size - 1;
	int mid_pos;

	while(first_pos <= last_pos) {
		mid_pos = (first_pos + last_pos) / 2;	
		// identical to:
		// mid_pos = first_pos + (last_pos - first_pos) / 2;
		if(key < sorted_arr[mid_pos]) {
			last_pos = mid_pos - 1;	
		} else if (key > sorted_arr[mid_pos]) {
			first_pos = mid_pos + 1;
		} else {
			return mid_pos;
		}
	}
	return -1;
}

int main() {
	int sorted_arr[] = {2,3,5,43,66,100};
	printf("%d\n", binary_search(sorted_arr, 7, 100));
	printf("%d\n", binary_search(sorted_arr, 7, 40));
}

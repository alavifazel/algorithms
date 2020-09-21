/*
 * > Resizing array implementation of stack
 *
 * Description: Lookups take a constant time but pushing and poping element takes N steps in the worst case (when doubling and halving).
 * However the "Amortized" analysis of this algorithm is O(1).
 * To have guarantee for relatively fast insertion/deletion use linked-list implementaiton.
 * But on average general resizing array is faster.
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int *data;
	int lastIndex, capacity;
} Stack;

void StackInit(Stack *s, int initialCapacity){
	if(initialCapacity > 0) {
		s->data = (int *) malloc(initialCapacity * sizeof(int));
		s->lastIndex = 0;
		s->capacity = initialCapacity;
		memset(s->data, 0, s->capacity);
	} else {
	        fprintf(stderr, "Initial capacity should be positive!\n");
	}
}

void StackFree(Stack *s) {
	free(s->data);
	s->lastIndex = 0;
}

void StackPush(Stack *s, int key) {
	if(s->lastIndex != s->capacity) {
		s->lastIndex++;
		s->data[s->lastIndex] = key;
	}
	else {
		/* These lines should have been ideally in a private method named "resize".
		 * Since C has no such encapsulation, publicly defining these
		 * Lines into a public function could lead to errors.
		 * In other words, only StackPush and StackPop should be able to the data capacity not the users themselves.
		 */
		int *tmp = realloc(s->data, s->capacity * 2);
		if(tmp) {
			s->capacity *= 2;
			s->data = tmp;
			s->lastIndex++;
			s->data[s->lastIndex] = key;
		} else {
		      fprintf(stderr, "Can't inrease stack array size!\n");
		}
	}
}

int StackPop(Stack *s) {
	int lastData = s->data[s->lastIndex];
	s->data[s->lastIndex] = 0;
	s->lastIndex--;

	// Dividing by 4 prevents "thrashing"
	if(s->lastIndex < s->capacity / 4) {
		int *tmp = realloc(s->data, s->capacity / 2);
		if(tmp) {
			s->capacity /= 2;
			s->data = tmp;
			return lastData;
		} else {
		      fprintf(stderr, "Can't decrease stack array size!\n");
		}
	}
}

bool StackIsEmpty(Stack *s) {
	return s->lastIndex == 1; 
}

int StackSize(Stack *s) {
	return s->lastIndex;
}

int main() { 
	Stack s;
	StackInit(&s, 1);
	StackPush(&s, 400);
	StackPush(&s, 42);
	StackPush(&s, 123123);
	printf("%d\t%d\n",s.capacity, s.data[s.lastIndex]);
	
	StackPop(&s);
	printf("%d\t%d\n",s.capacity, s.data[s.lastIndex]);

	StackPop(&s);
	printf("%d\t%d\n",s.capacity, s.data[s.lastIndex]);

	StackPop(&s);
	printf("%d\t%d\n",s.capacity, s.data[s.lastIndex]);
	
	StackFree(&s);
}

/*
 * > Resizing array implementation of stack
 *
 * Description: Lookups take a constant time but pushing and popping element takes N steps in the worst case (when doubling and halving).
 * However the "Amortized" analysis of this algorithm is O(1).
 * To have guarantee for relatively fast insertion/deletion use linked-list implementaiton.
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *data;
    int top_index;
    int capacity;
} Stack;

void stack_init(Stack *s, int initial_capacity) {
    if (initial_capacity > 0) {
        s->data = (int *) malloc(initial_capacity * sizeof(int));
        s->top_index = 0;
        s->capacity = initial_capacity;
        memset(s->data, 0, s->capacity * sizeof(int));
    } else {
        fprintf(stderr, "Initial capacity should be positive!\n");
        s->data = NULL;
        s->top_index = 0;
        s->capacity = 0;
    }
}

void stack_free(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top_index = 0;
    s->capacity = 0;
}

void stack_push(Stack *s, int key) {
    if (s->top_index == s->capacity) {
        int *tmp = realloc(s->data, s->capacity * 2 * sizeof(int));
        if (tmp) {
            s->capacity *= 2;
            s->data = tmp;
        } else {
            fprintf(stderr, "Can't increase stack array size!\n");
            return;
        }
    }

    s->data[s->top_index] = key;
    s->top_index++;
}

int stack_pop(Stack *s) {
    if (s->top_index == 0) {
        return -1;
    }

    s->top_index--;
    int lastData = s->data[s->top_index];
    s->data[s->top_index] = 0;

    // Avoid shrinking below 4 capacity
    if (s->capacity > 4 && s->top_index < s->capacity / 4) {
        int new_capacity = s->capacity / 2;
        int *tmp = realloc(s->data, new_capacity * sizeof(int));
        if (tmp) {
            s->capacity = new_capacity;
            s->data = tmp;
        } else {
            fprintf(stderr, "Can't decrease stack array size!\n");
        }
    }

    return lastData;
}

int stack_top(Stack *s) {
    if (s->top_index == 0) {
        fprintf(stderr, "Stack is empty!\n");
        return -1;
    }
    return s->data[s->top_index - 1];
}

bool stack_is_empty(Stack *s) {
    return s->top_index == 0;
}

int stack_size(Stack *s) {
    return s->top_index;
}

int main(void) { 
	Stack s;
	stack_init(&s, 1);
	stack_push(&s, 400);
	stack_push(&s, 42);
	stack_push(&s, 123123);
	
	printf("%d\t%d\n", stack_size(&s), stack_top(&s));
	stack_pop(&s);
	printf("%d\t%d\n", stack_size(&s), stack_top(&s));
	stack_pop(&s);
	printf("%d\t%d\n", stack_size(&s), stack_top(&s));
	stack_pop(&s);
	printf("%d\t%d\n", stack_size(&s), stack_top(&s));
	
	stack_free(&s);
	
	return 0;
}

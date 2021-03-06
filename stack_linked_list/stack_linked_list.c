/*
 * > Linked-list stack implementation
 * Description: 
 * 	Every operation in this algorithm uses a constant time in the worst case;
 * 	but it uses extra time and space versus resizing array implementation.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
	int data;
	struct Node *next_node;	
};

typedef struct {
	Node *node;	
	int size;
} Stack;

void StackInit(Stack *s) {
	s->node = NULL;
	s->size = 0;
}

int StackPop(Stack *s) {
	int tmp = s->node->data;
	Node *new_node = s->node->next_node;
	free(s->node);
	s->node = new_node;
	s->size--;
	
	return tmp;
}

void StackFree(Stack *s) {
	for(int i = 0; i < s->size - 1; ++i) 
		StackPop(s);
}

void StackPush(Stack *s, int data) {
	Node *old_node = s->node;
	s->node = (Node*) malloc(sizeof(Node));	
	s->node->data = data;
	s->node->next_node = old_node;
	s->size++;
}

bool StackIsEmpty(Stack *s) {
	return s->size == 0; 
}

int main() { 
	Stack s;
	StackInit(&s);

	StackPush(&s, 400);
	StackPush(&s, 42);
	StackPush(&s, 123123);

	printf("%d\n", StackPop(&s));
	printf("%d\n", StackPop(&s));	
	printf("%d\n", StackPop(&s));	
	
	StackFree(&s);
}

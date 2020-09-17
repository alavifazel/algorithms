/*
 * > Linked-list queue implementation
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
	Node *firstNode, *lastNode;	
	int size;
} Queue;

void QueueInit(Queue *q) {
	q->firstNode = NULL;
	q->lastNode = NULL;
	q->size = 0;
}

bool QueueIsEmpty(Queue *q) {
	return q->size == 0; 
}

int Dequeue(Queue *q) {
	int oldKey = q->firstNode->data;
	Node *newNode = q->firstNode->next_node;
	free(q->firstNode);
	if(QueueIsEmpty(q))
		q->lastNode = q->firstNode; 

	q->firstNode = newNode;

	q->size--;	
	
	return oldKey;
}

void QueueFree(Queue *q) {
	for(int i = 0; i < q->size - 1; ++i) 
		Dequeue(q);
}

void Enqueue(Queue *q, int key) {
	Node *oldNode = q->lastNode;
	q->lastNode = (Node*) malloc(sizeof(Node));	
	q->lastNode->next_node = NULL;

	if(QueueIsEmpty(q))
		q->firstNode = q->lastNode;
	else	
		if(oldNode) oldNode->next_node = q->lastNode;

	q->lastNode->data = key;
	q->size++;	
}

int main() { 
	Queue q;
	QueueInit(&q);
	Enqueue(&q, 400);
	Enqueue(&q, 42);
	Enqueue(&q, 123);
	Enqueue(&q, 443);
	printf("%d\n", Dequeue(&q));
	printf("%d\n", Dequeue(&q));	
	printf("%d\n", Dequeue(&q));	
	printf("%d\n", Dequeue(&q));	
	QueueFree(&q);
}

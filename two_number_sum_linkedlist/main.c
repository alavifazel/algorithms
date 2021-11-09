/*
 * Add two numbers with arbitrary number of digits (using linked-list)
 * Example input:
 * 4 5 6
 * 1 2 3
 * 
 * Output:
 *
 * 5 7 9
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
  int value;
  size_t counter;
  struct Node *nextNode; 
};

void appendNode(Node **node, int value) {
	Node *oldNode = *node;
	*node = malloc(sizeof(Node));
	(*node)->value = value;
	(*node)->counter++;
	(*node)->nextNode = oldNode;
}

int popNode(Node **node) {
	if(*node != NULL) {
		int tmp = (*node)->value;
		Node *newNode = (*node)->nextNode;
		free(*node);
		*node = newNode;
		return tmp;
	}
	return -1;
}

void destroyNode(Node **node) {
	for(size_t i = 0; (*node)->counter; ++i)
		popNode(node);
}

void printNode(Node *node) {
	while(node != NULL) {
		printf("%d ", node->value);
		node = node->nextNode;
	}
	printf("\n");
}

int getElem(Node *node, size_t index) {
	size_t i = 0;
	while(node != NULL) {
		if(i == index) return node->value;
		node = node->nextNode;
		i++;
	}
	return -1;
}

void reverseNode(Node **node) {
	Node *prev = NULL;
	Node *current = *node;
	while(current != NULL) {
		Node *next = current->nextNode;
		current->nextNode = prev;
		prev = current;
		current = next;
	}
	*node = prev;
}

void initNode(Node **node) {
	*node = NULL;
}

void freeNode(Node **node) {
	free(*node);
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
	static Node *result;
	size_t i = 0;
	bool carry = false;
	while(getElem(l1, i) != -1 || getElem(l1, i) != -1) {
		int digit;
		if(getElem(l1, i) != -1 && getElem(l2, i) != -1)
			digit = getElem(l1, i) + getElem(l2, i);
		else if(getElem(l1, i) != -1)
			digit = getElem(l1, i);
		else if(getElem(l2, i) != -1)
			digit = getElem(l2, i);
		if(carry) digit++;
		if(digit < 10) {
			appendNode(&result, digit);
			carry = false;
		} else {
			appendNode(&result, digit - 10);
			carry = true;
		}
		i++;
	}
	return result;
}

int main() {
	Node *l1, *l2;
	initNode(&l1);
	initNode(&l2);
	appendNode(&l2, 1);
	appendNode(&l2, 2);
	appendNode(&l2, 3);

	appendNode(&l1, 4);
	appendNode(&l1, 5);
	appendNode(&l1, 6);

	Node *result = addTwoNumbers(l1, l2);
	reverseNode(&l1);
	reverseNode(&l2);
	printNode(l1);
	printNode(l2);
	printNode(result);
	freeNode(&l1);
	freeNode(&l2);
}

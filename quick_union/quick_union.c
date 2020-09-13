/*
 * > Implementation of weighted quick-union with tree compression
 *
 * Integer array id[] of size maxSize holds the info about connections,
 * in such a way that if node 'p' and 'u' are connected they have a same 'root id' in the array.
 * Hence to check if node 'p' and 'u' are connected we just have to check if they have the same 'root id' value.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int *id;
	int *depth_level;
	int maxSize;
} Union;

void union_init(Union *u, int maxSize) {
	int *id = (int*) malloc(sizeof(int) * maxSize); 	
	int *depth_level = (int*) malloc(sizeof(int) * maxSize); 	
	for(int i = 0; i < maxSize; ++i) {
		id[i] = i;
		depth_level[i] = 1;
	}
	u->id = id;
	u->depth_level = depth_level;
	u->maxSize = maxSize;
}

void union_free(Union *u) {
	free(u->id);
	free(u->depth_level);
	u->maxSize = 0;
}

int union_root(Union *u, int i) {
	if(i > u->maxSize) {
		fprintf(stderr, "Node number is exceeding the union's number of nodes!");
		return -1;	
	}
	while(i != u->id[i]) {
		// bellow code does not flatten (compresses) the tree completely.
		// it merely makes the node to point to it's grandparent;
		// but in practice it is almost as good as flattening the whole tree completely.
		u->id[i] = u->id[u->id[i]]; 
		i = u->id[i];
	}
	return i;
}

bool union_is_connected(Union *u, int a, int b) {
	if(union_root(u,a) == union_root(u,b)) return true;
	else return false;
}

void union_connect(Union *u, int a, int b) {
	if(u->depth_level[a] > u->depth_level[b]) {
		u->id[b] = union_root(u, a);
		u->depth_level[a] += u->depth_level[b]; 
	} else {
		u->id[a] = union_root(u, b);
		u->depth_level[b] += u->depth_level[a]; 
	}
}

void union_print(Union *u) {
	printf("\n");
	printf("  i   : ");
	for(int i = 0; i < u->maxSize; ++i) {
		printf(" %d", i);
	}
	printf("\n");
	printf("id[i] : ");
	for(int i = 0; i < u->maxSize; ++i) {
		printf(" %d", u->id[i]);
	}
	printf("\n");
}

int main(){
	Union u;
	union_init(&u, 10);
	union_print(&u);

	union_connect(&u,4,3);
	union_print(&u);

	union_connect(&u,5,3);
	union_print(&u);

	union_connect(&u,1,5);
	union_print(&u);

	printf("%d\n", union_is_connected(&u,1,4)); // true!

	union_free(&u);
	return 0;
}

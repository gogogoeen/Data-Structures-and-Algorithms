#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

int main(void){
	printf("hello wolrd.\n");
	int value;
	Tree t=newTree();
	printf("Enter a tree: ");
	while (scanf("%d", &value) == 1) {
     	t=TreeInsert(t, value);
      	printf("Enter a tree: ");
   	}
   	printf("done insert.\n");
   	showTree(t);
   	freeTree(t);
	return 0;
}

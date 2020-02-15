#include <stdio.h>
#include "BSTree.h"

int main(void){
	int value;
	Tree t=newTree();
	printf("Enter a tree: ");
	while (scanf("%d", &value) == 1) {
		Item v = value;
     	t=TreeInsert(t, value);
      	printf("Enter a tree: ");
   	}
   	printf("done.\n");
   	
	int h=TreeHeight(t);
	printf("%d\n",h);
	h=TreeWidth(t);
	printf("%d\n",h);
	showTree(t);
   	
   	
	
	
	
	return 0;
	
}

#include <stdio.h>
#include "BST.h"

int main(void){
	int value;
	Tree t=newTree();
	printf("Enter a tree: ");
	while (scanf("%d", &value) == 1) {
		Item v = value;
     	t=insertSplay(t, value);
      	printf("Enter a tree: ");
   	}
   	printf("done insert.\n");
   	/*printf("Enter a tree for root: ");
   	int a;
	scanf("%d",&a);
	printf("d\n",a);
   	printf("done root insert.\n");
	t=insertAtRoot(t,a);
	*/
	showTree(t);
   	
   	
	//t=rebalance(t);
	//showTree(t);
	freeTree(t);
	return 0;
	
}

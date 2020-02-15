#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node{
	int data;
	struct node *next;
}NodeT;

NodeT *makeNode(int v){
	NodeT *x;
	x=(NodeT*)malloc(sizeof(NodeT));
	assert(x!=NULL);
	x->data=v;
	x->next=NULL;
	return x;
}

void freeLL(NodeT *list){
	NodeT *p, *temp;
	p=list;
	while (p!=NULL){
		temp=list->next;
		free(p);
		p=temp;
	}
}

void showLL(NodeT *list) {
   NodeT *p;
   printf("Done. List is ");
   for (p = list; p != NULL; p = p->next){
   
      printf("%d", p->data);
      if (p->next!=NULL){
      	printf("->");
	  }
	}
	printf("\n");
}

NodeT *joinLL(NodeT *list1, NodeT *list2){
	NodeT *p;
	p=list1;
	while (p->next!=NULL){
		p=p->next;
	}
	p->next=list2;
	return list1;
} 

void showsplitLL(NodeT *list,int count) {
	NodeT *p;
   	int i;
   	printf("First part is ");
   	p=list;
   	if (count>1) { 
	   	for (i=1;i<=count-count/2;i++){
	      	printf("%d", p->data);
	      	p=p->next;
	      	if (i<count-count/2){
	      		printf("->");
		  	}else {
		  		printf("\n");
		  	}
		}
		printf("Second part is ");
		for (i=count-count/2+1;i<=count;i++){
			printf("%d", p->data);
	      	p=p->next;
	      	if (i<count){
	      		printf("->");
		  	}else {
		  		printf("\n");
		  	}
		}
	}else {
		printf("%d\n",list->data);
	}
}

int main(int argc, char *argv[]) {
	NodeT *all=makeNode(0);
	int a;
	int c;
	printf("Enter an integer: ");
	if (scanf("%d",&a)!=1){
		printf("Done.");
	}else{
		c=1;
		all->data=a;
		printf("Enter an integer: ");
		NodeT *p=all;
		while(scanf("%d",&a)==1){
			c++;
			p->next=makeNode(a);
			p=p->next;
			printf("Enter an integer: ");
		}	
		showLL(all);
		showsplitLL(all,c);
	}
	free(all); 
	
	return 0;
	
}

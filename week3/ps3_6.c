#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
	int data;
	struct Node *next;
}Node;


int main(int argc, char *argv[]) {
	Node x, y, z;
	x.data=5;
	x.next=&y;
	y.data=3;
	y.next=&z;
	z.data=8;
	z.next=NULL;
	printf("%p\n",y.next);
	printf("%p",&z);

	/*Node a,b,c;
  	Node *ptr=&a; //�ŧiptr�A�ñN�L�u�V�`�Ia
  
  	a.data=12;
  	a.next=&b;
  	b.data=30;
  	b.next=&c;
  	c.data=64;
  	c.next=NULL;
  
  	while(ptr!=NULL){
  		printf("address=%p, ",ptr); //�L�X�`�I����} 
  		printf("data=%d ",ptr->data); //�L�X�`�I����� 
  		printf("next=%p\n",ptr->next); //�L�X�U�@�Ӹ`�I��} 
  		ptr=ptr->next;  //�Nptr���V�U�@�Ӹ`�I 
  	} */
  
  	system("PAUSE");	 
	
	return 0;
}

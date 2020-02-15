// Red-Black Tree ADT implementation ... COMP9024 19T3

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "RBTree.h"

#define PRINT_COLOR_RED   "red"
#define PRINT_COLOR_RESET " "

#define data(tree)  ((tree)->data)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)
#define color(tree) ((tree)->color)
#define isRed(tree) ((tree) != NULL && (tree)->color == RED)

typedef enum {RED,BLACK} Colr;

typedef struct Node {
   int  data;
   Colr color;
   Tree left, right;
} Node;

// create a new empty Tree
Tree newTree() {
   return NULL;
}

// make a new node containing data
Tree newNode(Item it) {
   Tree new = malloc(sizeof(Node));
   assert(new != NULL);
   data(new) = it;
   color(new) = RED;
   left(new) = right(new) = NULL;
   return new;
}

Tree rotateRight(Tree);
Tree rotateLeft(Tree);

Tree insertRB(Tree t, Item it, int inRight){

	if (t==NULL){
   		t=newNode(it);
   	}
   	if (left(t)!=NULL&&right(t)!=NULL&&color(left(t))==RED&&color(right(t))==RED){	//if the current node is four-node, then split	 
   		color(t)=RED;
   		color(left(t))=BLACK;
   		color(right(t))=BLACK;
	}
	if (it<data(t)){
		left(t)=insertRB(left(t),it,0);
		// re-arrange links/colors after insert
		//inRight 
		if (inRight==1&&color(t)==RED&&left(t)!=NULL&&color(left(t))==RED){
			t=rotateRight(t);
			return t;
		}
		if (color(left(t))==RED&&left(t)!=NULL&&left(left(t))!=NULL&&color(left(left(t)))==RED){
			t=rotateRight(t);
			color(t)=BLACK;
			color(right(t))=RED;
		}
		
	}else if (it>data(t)){
		right(t)=insertRB(right(t),it,1);
		// re-arrange links/colors after insert
		if (inRight==0&&color(t)==RED&&right(t)!=NULL&&color(right(t))==RED){
			t=rotateLeft(t);
			return t;
		}
		if (color(right(t))==RED&&right(t)!=NULL&&right(right(t))!=NULL&&color(right(right(t)))==RED){
			t=rotateLeft(t);
			color(t)=BLACK;
			color(left(t))=RED;
		}
	}
	
	return t;	
	
}

// insert a new item into a tree
Tree TreeInsert(Tree t, Item it) {
	t=insertRB(t,it,0);
	color(t)=BLACK;
	return t;
}



// check whether a key is in a Tree
bool TreeSearch(Tree t, Item it) {
   if (t == NULL)
      return false;
   else if (it < data(t))
      return TreeSearch(left(t), it);
   else if (it > data(t))
      return TreeSearch(right(t), it);
   else                                 // it == data(t)
      return true;
}

Tree rotateRight(Tree n1) {
   if (n1 == NULL || left(n1) == NULL)
      return n1;
   Tree n2 = left(n1);
   left(n1) = right(n2);
   right(n2) = n1;
   return n2;
}

Tree rotateLeft(Tree n2) {
   if (n2 == NULL || right(n2) == NULL)
      return n2;
   Tree n1 = right(n2);
   right(n2) = left(n1);
   left(n1) = n2;
   return n1;
}

// free memory associated with Tree
void freeTree(Tree t) {
   if (t != NULL) {
      freeTree(left(t));
      freeTree(right(t));
      free(t);
   }
}

// display Tree sideways
void showTreeR(Tree t, int depth) {
   if (t != NULL) {
      showTreeR(right(t), depth+1);
      int i;
      for (i = 0; i < depth; i++)
	 putchar('\t');            // TAB character
      if (isRed(t))
	 printf("%s%d%s\n", PRINT_COLOR_RED, data(t), PRINT_COLOR_RESET);
       else
	 printf("%d\n", data(t));
      showTreeR(left(t), depth+1);
   }
}

void showTree(Tree t) {
   showTreeR(t, 0);
}

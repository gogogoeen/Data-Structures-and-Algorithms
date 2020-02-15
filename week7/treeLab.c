// Binary Search Tree ADT Tester ... COMP9024 19T3

#include <stdlib.h>
#include <stdio.h>
#include "BSTree.h"

#define MAX_STR_LEN 20

void help();

int main(void) {
   Tree mytree = newTree();

   bool noShow = false;
   char line[MAX_STR_LEN];
   printf("\n> ");
   while (fgets(line,MAX_STR_LEN,stdin) != NULL) {
      int value = atoi(&line[1]);
      switch (line[0]) {
	 
      case 'n':	 
         freeTree(mytree);
	 mytree = newTree();
         break;

      case 'i':
         mytree = TreeInsert(mytree, value);
         break;
	 
      case 'd':
         mytree = TreeDelete(mytree, value);
         break;
	 
      case 's':
         if (TreeSearch(mytree, value))
            printf("Found!\n");
         else
            printf("Not found\n");
         noShow = true;
	 break;
	 
      case 'q':
	 printf("Bye.\n");
	 freeTree(mytree);
         return 0;
	 
      default:
         help();
         noShow = true;
      }
      
      if (noShow) {
	 noShow = false;
	 printf("\n> ");
      } else {
	 printf("New Tree:");
	 printf("  #nodes = %d,  ", TreeNumNodes(mytree));
	 printf("  height = %d\n", TreeHeight(mytree));
	 printf("  width = %d\n", TreeWidth(mytree));
	 if (TreeHeight(mytree) < 8)
	    showTree(mytree);
	 else
	    printf("New Tree is too deep to display nicely\n");
	 printf("\n> ");
      }
   }
	int h = TreeHeight(mytree);
	printf("height is : %d",h);
	h = TreeWidth(mytree);
	printf("width is : %d",h);
   freeTree(mytree);
   return 0;
}

void help() {
   printf("Commands:\n");
   printf("n = make a new tree\n");
   printf("i N = insert N into tree\n");
   printf("d N = delete N from tree\n");
   printf("s N = search for N in tree\n");
   printf("q = quit\n");
}

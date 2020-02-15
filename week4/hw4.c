#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void func(int *a) {
   a = malloc(sizeof(int));
   assert(a != NULL);
}

int main(void) {
   int *p;
   func(p);
   *p=6;
   printf("%d\n",*p);
   free(p);
   
   /*int *p2;
   p2=malloc(sizeof(int));
   assert(p2!=NULL);
   *p2=4;
   printf("%d\n",*p2);
   return 0;
   */
}

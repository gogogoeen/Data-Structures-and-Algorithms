// PQueue client ... COMP9024 19T3
#include <stdio.h>
#include "PQueue.h"

int main(void) {
   int distance[1] = { 90};

   PQueueInit();
   joinPQueue(0);		// vertex 0 (distance = 90) joins the queue
   

   while (!PQueueIsEmpty()) {
      printf("Dequeueing %d.\n", leavePQueue(distance));
   }
   
  
   
   int dist[] = { 24, 90, 19 };
   Vertex n1, n2, n3;
   joinPQueue(1);
   joinPQueue(2);
   joinPQueue(0);
   n1 = leavePQueue(dist);
   n2 = leavePQueue(dist);
   n3 = leavePQueue(dist);
   printf("n1: %d, n2: %d, n3: %d \n", n1, n2, n3);
   
   return 0;
}

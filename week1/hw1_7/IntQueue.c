// Queue ADO implementation ... COMP9024 19T3
#include <stdio.h>
#include "IntQueue.h"
#include <assert.h>
typedef struct {
   int item[MAXITEMS];
   int  num;
} queueRep;      		 // defines the Data Structure

static queueRep queueObject;  // defines the Data Object

void QueueInit() {            // set up empty queue
   queueObject.num = 0;
}

int QueueIsEmpty() {          // check whether queue is empty
   return (queueObject.num < 1);
}

void QueueEnqueue(int input) {     // insert int at the back  of queue
   assert(queueObject.num < MAXITEMS);
   queueObject.num++;
   int i = queueObject.num;
   queueObject.item[i-1] = input;
}

int QueueDequeue() {             // remove int for the first item of queue
   assert(queueObject.num > 0);
   int n = queueObject.num;
   int output  =  queueObject.item[0];
   int i;
   for (i=0;i<n-1;i++){
   		 queueObject.item[i]= queueObject.item[i+1];	
   }
   queueObject.num--;
   return output;
}

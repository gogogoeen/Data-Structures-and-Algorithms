// Stack ADO implementation ... COMP9024 19T3
#include <stdio.h>
#include "IntStack.h"
#include <assert.h>

typedef struct {
   int item[MAXITEMS];
   int  top;
} stackRep;                   // defines the Data Structure

static stackRep stackObject;  // defines the Data Object

void StackInit() {            // set up empty stack
   stackObject.top = -1;
}

int StackIsEmpty() {          // check whether stack is empty
   return (stackObject.top < 0);
}

void StackPush(int num) {     // insert int on top of stack
   assert(stackObject.top < MAXITEMS-1);
   stackObject.top++;
   int i = stackObject.top;
   stackObject.item[i] = num;
}

int StackPop() {             // remove int from top of stack
   assert(stackObject.top > -1);
   int i = stackObject.top;
   int num = stackObject.item[i];
   stackObject.top--;
   return num;
}


// Priority Queue ADO implementation ... COMP9024 19T3

#include "PQueue.h"
#define LEN(x) sizeof(x) / sizeof(x[0])
#include <assert.h>
#include <stdio.h>

typedef struct {
   Vertex item[MAX_NODES];  // array of vertices currently in queue
   int    length;           // #values currently stored in item[] array
} PQueueT;

static PQueueT PQueue;      // defines the Priority Queue Object

// set up empty priority queue
void PQueueInit() {
   PQueue.length = 0;
}

// insert vertex v into priority queue
// no effect if v is already in the queue
void joinPQueue(Vertex v) {
   assert(PQueue.length < MAX_NODES);                // ensure queue ADO is not full
   int i = 0;
   while (i < PQueue.length && PQueue.item[i] != v)  // check if v already in queue
      i++;
   if (i == PQueue.length) {                         // v not found => add it at the end
      PQueue.item[PQueue.length] = v;
      PQueue.length++;
   }
}
// remove the highest priority vertex from PQueue
// remember: highest priority = lowest value priority[v]
// returns the removed vertex
int x=-1;  //last priority number
int n=0;
int last=-1; 	//last leave place
Vertex leavePQueue(int priority[]) {
	assert(PQueue.length > 0); 
	
	int index=0;
	int highpriority=-1;
	int i=0;
	Vertex a;
	if (x==-1){
		for (i=0;i<PQueue.length;i++){
    		if (highpriority==-1){
      			highpriority=priority[i];
      			index=i;
	  		}else if (highpriority>priority[i]){
	  			highpriority=priority[i];
	  			index=i;
			}
   		}
		x=highpriority;
		n=PQueue.length;
		last=index;
		   	
	}else {
		for (i=0;i<n;i++){
			if (highpriority==-1&&priority[i]>=x){
				if (priority[i]>x){
					highpriority=priority[i];
					index=i;
				}else if (priority[i]==x&&i>last){
					index=i;
					highpriority=priority[i];
					break;
				}
			}else if (priority[i]>=x&&highpriority>priority[i]){
				if (priority[i]>x){
					highpriority=priority[i];
					index=i;
				}else if (priority[i]==x&&i>last){
					index=i;
					highpriority=priority[i];
					break;
				}
			} 
		}
		x=highpriority;
		last=index;
	}
	
   	a=index;
   	PQueue.length--;
   	if (PQueue.length==0){
   		x=-1;
   		n=0;
	   }
   	return a;
}

// check if priority queue PQueue is empty
bool PQueueIsEmpty() {
	if (PQueue.length==0){
		return true;
	}else	{
		return false;
	}
	
}

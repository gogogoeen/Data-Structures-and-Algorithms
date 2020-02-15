// Starting code for Dijkstra's algorithm ... COMP9024 19T3

#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"

#define VERY_HIGH_VALUE 999999

void dijkstraSSSP(Graph g, Vertex source) {
   int  dist[MAX_NODES];
   int  pred[MAX_NODES];
   bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
   int s, t;

   PQueueInit();
   int nV = numOfVertices(g);
   for (s = 0; s < nV; s++) {
      joinPQueue(s);
      dist[s] = VERY_HIGH_VALUE;
      pred[s] = -1;
      vSet[s] = true;
   }
    dist[source] = 0;
	pred[source]=source;
  
	int k=1;
	int i;
	/*for (i=0;i<nV;i++){					//push all the vertex into PQueue
		Vertex a =i;
		joinPQueue(a);
	}*/
	while (k!=0){						//end while when all vertexs are false
		k=0;
		Vertex visit=leavePQueue(dist);			//leave the vextex with the shortest distance
		for (i=0;i<nV;i++){
			if (adjacent(g, visit, i)!=0){
				if (dist[visit]+adjacent(g, visit, i)<dist[i]){			//relaxation
					dist[i]=dist[visit]+adjacent(g, visit, i);
					pred[i]=visit;								
				}
			}
		}
		
		
		vSet[visit]=false;					//set visit vertex=false
		
		for (i=0;i<nV;i++){
			if (vSet[i]==true){			//check if all the vertexs are false. if all false let k=1 
				k++;
			}
		}
	}

	for (i=0;i<nV;i++){
		if (dist[i]==VERY_HIGH_VALUE){
			printf("%d: no path\n",i);
		}else if (i==source){
			printf("%d: distance = %d, shortest path: %d\n",i,dist[i],i);
		}else {
			printf("%d: distance = %d, shortest path: ",i,dist[i]);
			int path[1000];
			int j=0;
			path[0]=i;
			while (pred[path[j]]!=source){					//take out all the vertexes of in the path and print them reversely
				j++;
				path[j]=pred[path[j-1]];
			}
			printf("%d",source);
			int f;
			for (f=j;f>=0;f--){
				printf("-%d",path[f]);
			}
			printf("\n");
		}	
	}
}

void reverseEdge(Edge *e) {
   Vertex temp = e->v;
   e->v = e->w;
   e->w = temp;
}

int main(void) {
   Edge e;
   int  n, source;

   printf("Enter the number of vertices: ");
   scanf("%d", &n);
   Graph g = newGraph(n);

   printf("Enter the source node: ");
   scanf("%d", &source);
   printf("Enter an edge (from): ");
   while (scanf("%d", &e.v) == 1) {
      printf("Enter an edge (to): ");
      scanf("%d", &e.w);
      printf("Enter the weight: ");
      scanf("%d", &e.weight);
      insertEdge(g, e);
      reverseEdge(&e);               // ensure to add edge in both directions
      insertEdge(g, e);
      printf("Enter an edge (from): ");
   }
   printf("Done.\n");
   
   
   dijkstraSSSP(g, source);
   freeGraph(g);
   return 0;
}

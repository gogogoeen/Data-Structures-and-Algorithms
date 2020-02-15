// Graph ADT
// Adjacency Matrix Representation ... COMP9024 19T3
#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GraphRep {
   int  **edges;   // adjacency matrix
   int    nV;      // #vertices
   int    nE;      // #edges
} GraphRep;

Graph newGraph(int V) {
   assert(V >= 0);
   int i;

   Graph g = malloc(sizeof(GraphRep));
   assert(g != NULL);
   g->nV = V;
   g->nE = 0;

   // allocate memory for each row
   g->edges = malloc(V * sizeof(int *));
   assert(g->edges != NULL);
   // allocate memory for each column and initialise with 0
   for (i = 0; i < V; i++) {
      g->edges[i] = calloc(V, sizeof(int));
      assert(g->edges[i] != NULL);
   }

   return g;
}

int numOfVertices(Graph g) {
   return g->nV;
}

// check if vertex is valid in a graph
bool validV(Graph g, Vertex v) {
   return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
   assert(g != NULL && validV(g,e.v) && validV(g,e.w));

   if (!g->edges[e.v][e.w]) {  // edge e not in graph
      g->edges[e.v][e.w] = 1;
      g->edges[e.w][e.v] = 1;
      g->nE++;
   }
}

void removeEdge(Graph g, Edge e) {
   assert(g != NULL && validV(g,e.v) && validV(g,e.w));

   if (g->edges[e.v][e.w]) {   // edge e in graph
      g->edges[e.v][e.w] = 0;
      g->edges[e.w][e.v] = 0;
      g->nE--;
   }
}

bool adjacent(Graph g, Vertex v, Vertex w) {
   assert(g != NULL && validV(g,v) && validV(g,w));

   return (g->edges[v][w] != 0);
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
       for (j = i+1; j < g->nV; j++)
	  if (g->edges[i][j])
	      printf("Edge %d - %d\n", i, j);
}

void freeGraph(Graph g) {
   assert(g != NULL);

   int i;
   for (i = 0; i < g->nV; i++)
      free(g->edges[i]);
   free(g->edges);
   free(g);
}

void minmaxDegree(Graph g){
	int i;		
	int minCount=0;			//minCount maxCount count how many vertexs have the min or max degrees
	int maxCount=0;
	
	
	int MinMax[2][1+g->nE];
	MinMax[0][0]=-1;
	for (i=0;i<g->nV;i++){
		int j;
		int degreecount=0;
		for (j=0;j<g->nV;j++){
			if (i!=j){
				if (adjacent(g,i,j)==1){
					degreecount++;
				}
			}
		}
		if (MinMax[0][0]==-1||(degreecount==MinMax[0][0]&&degreecount==MinMax[1][0])){		//put the verxtex in both min and max if  putting the first vextex and if degree=min=max
			MinMax[0][0]=degreecount;
			MinMax[1][0]=degreecount;
			minCount++;
			maxCount++;
			MinMax[0][minCount]=i;
			MinMax[1][maxCount]=i;
		}else if (degreecount<MinMax[0][0]){				//if finding the miminum degrees vertex
			MinMax[0][0]=degreecount; 
			minCount=1;
			MinMax[0][minCount]=i;
		}else if (degreecount>MinMax[1][0]){				//if finding the maximum degrees vertex
			MinMax[1][0]=degreecount; 
			maxCount=1;
			MinMax[1][maxCount]=i;
		}else if (degreecount==MinMax[0][0]&&degreecount!=MinMax[1][0]){			//fing another mimumum degrees vertex
			minCount++;
			MinMax[0][minCount]=i;
		}else if (degreecount==MinMax[1][0]&&degreecount!=MinMax[0][0]){			//fing another maximum degrees vertex
			maxCount++;
			MinMax[1][maxCount]=i;
		}
	}
	printf("Minimum degree: %d\n",MinMax[0][0]);
	printf("Maximum degree: %d\n",MinMax[1][0]);
	printf("Nodes of minimum degree: \n");
	for (i=1;i<=minCount;i++){
		printf("%d\n",MinMax[0][i]);
	}
	printf("Nodes of maximum degree: \n");
	for (i=1;i<=maxCount;i++){
		printf("%d\n",MinMax[1][i]);
	}
}
void allTricliques(Graph g){
	int i, j, k;
	printf("Triangles: \n");
	for (i=0;i<g->nV-2;i++){
		for (j=i+1;j<g->nV-1;j++){
			if (adjacent(g,i,j)==1){
				for (k=j+1;k<g->nV;k++){
					if (adjacent(g,k,i)==1&&adjacent(g,j,k)==1){
						printf("%d-%d-%d\n",i,j,k);
					}
				}
			}
		}
	}
}

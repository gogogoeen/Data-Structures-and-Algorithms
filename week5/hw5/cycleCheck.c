#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 1000

int visit[MAX];
int mark;
int hascycle(Graph g, int n){
	int i, k;
	for (i=0;i<n;i++){
		mark=-1;
		for (k=0;k<n;k++){
			visit[k]=0;
		}
		if (dfsCyclecheck(g,i,n)==0){
			printf("The graph has a cycle.");
			return 0;
		}
	}
	printf("The graph is acyclic.");
	
	return 0;
}

int dfsCyclecheck(Graph g, int v, int n){			// graph    start visit      total vertexes 
	int i;             //specify which is the last visit
	visit[v]=1;
	for (i=0;i<n;i++){
		if (v!=i){
			if (adjacent(g,v,i)==1&&visit[i]==0){
				mark=v;
				dfsCyclecheck(g,i,n);
			}else if (adjacent(g,v,i)==1&&visit[i]==1&&mark!=i&&mark!=-1){
				return 0;
			}
		}
	}
	return 1;
}

int main(void){
	printf("Enter the number of vertices: ");
	int n, m;
	scanf("%d",&n);
	Graph g=newGraph(n);
	Edge e;
	printf("Enter an edge (from): ");
	while (scanf("%d",&m)==1){
		e.v=m;
		printf("Enter an edge (to): ");
		scanf("%d",&m);
		e.w=m;
		insertEdge(g,e);
		printf("Enter an edge (from): ");
	}
	printf("Done.\n");
	hascycle(g,n);
	freeGraph(g);
	
	
	return 0;
}


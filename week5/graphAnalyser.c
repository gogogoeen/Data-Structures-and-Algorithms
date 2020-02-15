#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>





int main(void){
	printf("Enter the number of vertices: ");
	int n;
	scanf("%d",&n);
	Graph g=newGraph(n);
	Edge e;
	printf("Enter an edge (from): ");
	while (scanf("%d",&n)==1){
		e.v=n;
		printf("Enter an edge (to): ");
		scanf("%d",&n);
		e.w=n;
		insertEdge(g,e);
		printf("Enter an edge (from): ");
	}
	printf("Done.\n");
	showGraph(g);
	minmaxDegree(g);
	allTricliques(g);
	freeGraph(g);
	
	
	
	
	return 0;
}

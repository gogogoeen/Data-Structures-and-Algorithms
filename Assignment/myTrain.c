//comp9024 19T3 assignment
//Using data structure: Weighted Graph data structure
//Vertextes divide to two part: trains and stations
//Edge connecting to one train and one station represent that train will arrive on that station
//the weight of the edge represents the time that arrive
//Details will be explained below 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "WGraph.h"
#define very_large 99999
#include <stdbool.h>


//dfsPathCheck divides into two part. The first one is when the starting vertex is train pointing to stations.
//The second part is when the starting vertex is station pointing to trains
//The function stop when the starting vertex is the destination (return true) or there is no path found(return false)
//g is the graph, v is the current vertex, dest is the ending vertex, last is the last station,n is the number of stations, 
//**visited is the matrix saving the traversal of the path and which train is taken. arrivetime is the expected 
//arrive time from the query
bool PathCheck(Graph g, Vertex v, Vertex dest, Vertex last, int n, int **visited, int arrivetime){
	int i;
	int j;
	if (v==dest&&adjacent(g,v,visited[1][visited[0][v]])<=arrivetime){			//Return true if finding the path and the arrive time is earlier 
		visited[1][v]=visited[1][visited[0][v]];								//Then the arrive time from the query
		return true;
	}else if(v>=n){								//if starting vertex is a train pointing to stations
		int next_depart=very_large;				//next station is the station that has never visited and has earliest time
		int next_station=-1;
		for (j=0;j<n;j++){
			if (adjacent(g, v, j)>adjacent(g, v, last)&&visited[0][j]==-1&&adjacent(g, v, j)<next_depart){  //This loop will find the unvisit station with the smallest weight, 
				next_depart=adjacent(g, v, j);																//and that is bigger than the weight this train connect to the last stop,
				next_station=j;																				//this mean to find the next stop this train going to arrive at
			}
		}
		//if find a station that train time is the later than the previos stop and is earliest among all satisfied
		if (next_station!=-1){							
			visited[0][next_station]=last;		//mark this station as traveled, the value of this element is the number of last station
			if (PathCheck(g, next_station, dest, last, n, visited,arrivetime)==true){
				return true;
			}
		}
		
	}else {										//if starting vertex is a station pointing to trains
		for (i=n;i<numOfVertices(g);i++){
			if (adjacent(g,v,i)!=0){
				if (i==visited[1][visited[0][v]]){							//Doesn't change the train
					visited[1][v]=i;
					if (PathCheck(g, i, dest, v, n, visited,arrivetime)==true){
						return true;
					}
				}else if(adjacent(g,v,i)>=adjacent(g,v,visited[1][visited[0][v]])){		//If Change the train, the later train can not be earlier
					visited[1][v]=i;													//Than the earlier one
					if (PathCheck(g, i, dest, v, n, visited,arrivetime)==true){
						return true;
					}
				}
				
			}
			
			
		}
		//There are no train from this station that can arrive to the destination successfully
		visited[0][v]=-1;		//go back to the previous train, mark this station as unvisit
	}
	return false;
}

//Because the findPath() will find a path that is reversly, so need to create a function that 
//can first recursively find the source of the path, and than print it from source to destination
void showpath(Graph g, int v, int **visited, char **StationName){
	if (v==visited[0][v]){
		if (adjacent(g, v, visited[1][v])<1000){
			printf("0%d %s\n",adjacent(g, v, visited[1][v]), StationName[v]);						//if the timing is before 10am
		}else{																						//put one zero before the time
			printf("%d %s\n",adjacent(g, v, visited[1][v]), StationName[v]);						//e.g., 930->0930. Same operation as below
		}
	}else {
		showpath(g, visited[0][v],visited,StationName);
		//Need to check whether the train that taken at this station is equal to the
		//train that is taken at the previous station or not. If not, which mean the
		//passenger change the train. Then need to print the change train information				
		if (visited[1][v]!=visited[1][visited[0][v]]){
			if (adjacent(g, v, visited[1][visited[0][v]])<1000){
				printf("0%d %s\n", adjacent(g, v, visited[1][visited[0][v]]), StationName[v]);
			}else {
				printf("%d %s\n", adjacent(g, v, visited[1][visited[0][v]]), StationName[v]);
			}
			printf("Change at %s\n", StationName[v]);
		}												
		if (adjacent(g, v, visited[1][v])<1000){
			printf("0%d %s\n",adjacent(g, v, visited[1][v]), StationName[v]);						
		}else{																						
			printf("%d %s\n",adjacent(g, v, visited[1][v]), StationName[v]);					
		}		
	}															
}

//**visited is the matrix saving the traversal of the path and which train is taken.
//visit[0][n] is use for saving the previous stop for the traversal
//visit[1][n] is use for saving the which train is being taken when leaving this station
//First choose the latest depature time for starting train, and call the function dfsPathCheck()
//If there are no path, then restart and choose the second latedst train.
//If dfsPathCheck return a success path, then print the correspond  station name and time of the path

void findPath(Graph g, Vertex src, Vertex dest, int n, int arrivetime, char **StationName){ 				//Using a dynamic memories to store path finding in the DFS
	
	//Allocate memory for 2 rows for the matrix. One for saving the previous 
	//location of the travel, one for saving which train is visiting during this stop
	//The length of the row is n (number of stations)
	int **visit;
	visit=malloc(2*sizeof(int*));
	assert(visit!=NULL);
	
	int i;
	//Allocate memory for the elements in each row
	for (i=0;i<2;i++){
		visit[i]=malloc(n*sizeof(int));
		assert(visit[i]!=NULL);
	}

	int j;
	int last_departure=very_large;						
	for (i=0;i<(numOfVertices(g)-n);i++){
		for (j=0;j<n;j++){								//Each station as unvisit
			visit[0][j]=-1;
			visit[1][j]=-1;
		}
		
		visit[0][src]=src;
		int depart_time=0;
		int start=-1;																	//The time depart at the beginning station. As late as possible	
		for (j=n;j<numOfVertices(g);j++){												//Choose the latest departure to start DFSfinding path 
			if (adjacent(g, src, j)>depart_time&&adjacent(g, src, j)<last_departure){
				depart_time=adjacent(g, src, j);
				start=j;
			}
		}
		if (start!=-1){
			//store the depature time for this time. next try shoold be earlier than this one
			last_departure=depart_time;								
			//put the starting train at visit[1][src]. indicates that at src station
			//we will take the this train to start traversal
			visit[1][src]=start;
			//go to dfsPathCheck to check whether there is path or not																								
			if (PathCheck(g, start, dest, src, n, visit, arrivetime)==true){	
				
				// if successfully find a path, then call the function showpath() to print
				showpath(g, dest, visit, StationName);
				//printf("\n");
				
				int k;													//Before the findPath() terminates, need to free the visit array
				for (k=0;k<2;k++){
					free(visit[k]);
				}
				free(visit);
				return;
				
			}
		}
		//There are no successful path from this starting path(starting departure time)
		//Reset the visit to start with an earlier path(train)
	
			
		
	}
	
	//If there are no path found
	
	
	printf("No connection found.\n");									//Before the findPath() terminates, need to free the visit array
	int k;
	for (k=0;k<2;k++){
		free(visit[k]);
	}
	free(visit);
	
}





/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	//Using Dynamic memories to save all the stations' name and use a double pointer **AllStaion
	//point to the dynamic memories. **AllStations points to all the pointers that point to 
	//Stations. All the AllStations[i] point to the memories spaces that same the station.
	char **AllStations;
	int n;													//    n = Number of stations
	int i;
	printf("Enter the number of stations: ");
	scanf("%d",&n);
	AllStations=malloc(n*sizeof(char*));					//Create Dynamic memories for stations
	assert(AllStations!=NULL);
	for (i=0;i<n;i++){
		AllStations[i]=malloc(31*sizeof(char));
		assert(AllStations[i]!=NULL);
		scanf("%s",AllStations[i]);
	}
	
	int t;													// t = the number of trains
	printf("Enter the number of trains: ");
	scanf("%d",&t);
	//Create a weighted graph to Save all the staions and trains(n+t vertexs). 0~(n-1) save as station, 
	//n~(n+t-1)save as train. The edge will only connect one station and one train, there will be no 
	//connection between train and train, or Station and station. The edge represents the train will 
	//stop by that station. The weight is the time that train stops at that station.
	Graph g=newGraph(n+t);
	for (i=0;i<t;i++){
		printf("Enter the number of stops: ");
		int j;
		int s;												// s = the number of stops 
		scanf("%d",&s);
		int k;									
		for (j=0;j<s;j++){
			int Time;
			scanf("%d",&Time);
			char Stop[31];
			scanf("%s",Stop);
			for (k=0;k<n;k++){								//find the stop of the train is in which station
				if (strcmp(Stop, AllStations[k])==0){
					break;
				}
			}
			Edge e;
			e.v=k;
			e.w=n+i;
			e.weight=Time;
			insertEdge(g, e);	
			
		}
	}
	//printf("\n");
	
	int a=1;
	//The queries while loop.The program will keep running unless typing
	
	while (a!=0){										
		//Save From stop and To stop from the query
		char From[31];								
		char To[31];
		int fromVertex;										//The no. vertex in the graph that correspond From Stop
		int toVertex;										//The no. vertex in the graph that correspond To Stop
		int ArriveBy;
		int k;
		//find the From qeries is which vertex(station) in the graph
		printf("From: ");
		scanf("%s",From);
		if (strcmp(From,"done")==0){						//To check whether want to stop the program or not
			printf("Thank you for using myTrain.\n");
			return 0;
		}
		for (k=0;k<n;k++){								
			if (strcmp(From, AllStations[k])==0){
				break;
			}
		}
		fromVertex=k;									
		//find the From qeries is which vertex(station) in the graph
		printf("To: ");
		scanf("%s",To);
		for (k=0;k<n;k++){								
			if (strcmp(To, AllStations[k])==0){
				break;
			}
		}
		toVertex=k;
		printf("Arrive by: ");
		scanf("%d",&ArriveBy);
		//printf("\n");
		//int **VisitResult;														//this need to be free later
		//VisitResult=findPath(g,fromVertex,toVertex,n, ArriveBy);				//Calling the findPath function to find the path
		findPath(g,fromVertex,toVertex,n, ArriveBy, AllStations);
		
		
	}
	
	
	
	//Before the program terminates, need to free all the memory created by malloc().
	//Including the AllStations(saving the name of the station), Graph g
	
	freeGraph(g);																//Free graph
	for (i=0;i<n;i++){															//Free Dynamic Memories of saving stations
		free(AllStations[i]);
	}
	free(AllStations);
	
	return 0;
}

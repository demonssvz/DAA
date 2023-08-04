
#include <stdio.h>

// Number of vertices in the graph
#define V 4

#define INF 999

// A function to print the solution matrix
void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
	int i, j, k;

	for (k = 0; k < V; k++) {
			for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][V])
{
	printf( "the shortest distances \n");
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				printf("%7s", "900");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int graph[V][V] ;
	
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
		scanf("%d", &graph[i][j]) ;
	}
	}
	for (int i = 0; i < V; i++) 
	{
		for (int j = 0; j < V; j++) 
		{
		if(graph[i][j] == 0 )
			graph[i][j] = 999 ;
		} 
	}
	
			
	

	floydWarshall(graph);
	return 0;
}

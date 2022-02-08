// C Program for Floyd Warshall Algorithm
#include<stdio.h>
#define V 4

#define INF 99999

void printSolution(_Array_ptr<int _Checked[V]> dist);

void floydWarshall (_Array_ptr<int _Checked[V]> graph)
_Checked {

	int dist _Checked[V] _Checked[V];
int i;
int j;
int k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < V; k++)
	{
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++)
		{
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

void printSolution(_Array_ptr<int _Checked[V]> dist)
_Checked {
	_Unchecked { printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n"); };
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		_Unchecked {
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		_Unchecked { printf("\n"); };
	}
}

int main()
_Checked {
	int graph _Checked[V] _Checked[V] = { {0, 5, INF, 10},
						{INF, 0, 3, INF},
						{INF, INF, 0, 1},
						{INF, INF, INF, 0}
					};

	// Print the solution
	floydWarshall(graph);
	printSolution(graph);
	return 0;
}


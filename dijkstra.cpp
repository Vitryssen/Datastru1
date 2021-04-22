/*
2020-04-19
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 1
*/
#include <vector>
#include "printer.h"
int minDistance(std::vector<int> dist, std::vector<bool> sptSet, int size)
{
	int min = INT_MAX, min_index{};
	//Check for reachable and unvisted nodes and return the index of the shortest path
	for (int v = 0; v < size; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}
void dijkstra(std::vector<std::vector<double> > matrix, int src, const int size)
{
	std::vector<int> distance(size, INT_MAX);
	std::vector<bool> visited(size, false);
	std::vector<int> parent(size, -1);
	distance[src] = 0;
	for (int count = 0; count < size - 1; count++)
	{	
		//Get the index of the node with shortest distance
		int u = minDistance(distance, visited, size);
		visited[u] = true;
		for (int v = 0; v < size; v++)
		{
			//If its a valid node add the path to the parent array
			//and add its distance to the distance array
			if (!visited[v] && matrix[u][v] && distance[u] + matrix[u][v] < distance[v]) {
				parent[v] = u;
				distance[v] = distance[u] + matrix[u][v];
			}
		}
	}
	printSolution(distance, size, parent, src);
}
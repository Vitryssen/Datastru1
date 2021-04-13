#include <vector>
#include "printer.h"
int minDistance(std::vector<int> dist, std::vector<bool> sptSet, int size)
{
	int min = INT_MAX, min_index{};
	for (int v = 0; v < size; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}
void dijkstra(std::vector<std::vector<double> > graph, int src, const int size)
{
	std::vector<int> dist(size, INT_MAX);
	std::vector<bool> sptSet(size, false);
	std::vector<int> parent(size, -1);
	dist[src] = 0;
	for (int count = 0; count < size - 1; count++)
	{
		int u = minDistance(dist, sptSet, size);
		sptSet[u] = true;
		for (int v = 0; v < size; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist, size, parent, src);
}
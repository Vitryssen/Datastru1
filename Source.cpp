#include <iostream>
#include <list>
#include "reader.h"
#include "printer.h"
#include "convert.h"
using namespace std;
void DFS(int start, int goal, int size, vector<bool>& visited);
int BFS(int start, adjacency_list_t test);
void resetVisited(vector<bool>& visited);
int allVisited(vector<bool>& visited);
int allNodesReachable(adjacency_list_t test, vector<bool> visited);
bool verifyMatrix(adjacency_list_t test, vector<bool> visited);
bool validMatrix(adjacency_list_t test);
void dijkstra(vector<std::vector<double> > graph, int src);
void printSolution(int dist[], int n, int parent[]);
int minDistance(int dist[], bool sptSet[]);
vector<std::vector<double> > matrix;
double totWeight = 0;
bool incomplete = false;
int const V = 48;
int main() {
	adjacency_list_t test = parse_file("export.txt");
	matrix = listToMatrix(test);
	dijkstra(matrix, 0);
	if (BFS(0, test) == -1) {
		cout << "BFS valid" << endl;
	}
	else {
		cout << "BFS not valid" << endl;
	}
	if (validMatrix(test)) {
		cout << "DFS valid" << endl;
	}
	else {
		cout << "DFS not valid" << endl;
	}
	return 0;
}
int minDistance(int dist[],bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false &&
			dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}
void printPath(int parent[], int j)
{
	if (parent[j] == -1)
		return;
	printPath(parent, parent[j]);
	printf("%d ", j);
}
void printSolution(int dist[], int n,int parent[])
{
	int src = 0;
	printf("Vertex\t Distance\tPath");
	for (int i = 1; i < V; i++)
	{
		printf("\n%d -> %d \t\t %d\t\t%d ",
			src, i, dist[i], src);
		printPath(parent, i);
	}
}
void dijkstra(vector<std::vector<double> > graph, int src)
{
	int dist[V];
	bool sptSet[V];
	int parent[V];
	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist, V, parent);
}
//--------------------------------------------------------
int BFS(int start, adjacency_list_t test) {
	vector<bool> visited(test.first.size(), false);
	list<int> queue;
	visited[start] = true;
	queue.push_back(start);
	list<int>::iterator it;
	while (!queue.empty())
	{
		start = queue.front();
		//cout << start << " ";
		queue.pop_front();
		for (auto j = test.second.begin(); j != test.second.end(); j++) {
			if (j[0].n1 == start) {
				if (!visited[j[0].n2]) {
					visited[j[0].n2] = true;
					queue.push_back(j[0].n2);
				}
			}
		}
	}
	return allVisited(visited);
}
//Add validMatrix and verifyMatrix to same function
bool validMatrix(adjacency_list_t test) {
	vector<bool> visited(test.first.size(), false);
	if (verifyMatrix(test, visited)) {
		return true;
	}
	else
		return false;
}
bool verifyMatrix(adjacency_list_t test, vector<bool> visited) {
	for (int x = 0; x < test.first.size(); x++) {
		for (int i = 0; i < test.first.size(); i++) {
			DFS(i, x, test.first.size(), visited);
			if (allVisited(visited) != -1) {
				return false;
			}
			resetVisited(visited);
		}
	}
	return true;
}
// Return list of ints in case of multiple unreachable nodes
int allNodesReachable(adjacency_list_t test, vector<bool> visited) {
	for (int x = 0; x < test.first.size(); x++) {
		for (int i = 0; i < test.first.size(); i++) {
			DFS(i, x, test.first.size(), visited);
			int valid = allVisited(visited);
			if (valid != -1) {
				return valid;
			}
			resetVisited(visited);
		}
	}
	return -1;
}
void resetVisited(vector<bool>& visited) {
	for (int i = 0; i < visited.size(); i++) {
		visited.at(i) = false;
	}
}
int allVisited(vector<bool>& visited) {
	for (int i = 0; i < visited.size(); i++) {
		if (!visited.at(i)) {
			return i;
		}
	}
	return -1;
}
void DFS(int start, int goal, int size, vector<bool>& visited)
{
	visited[start] = true;
	for (int i = 0; i < size; i++) {
		if (matrix[start][i] != 0 && (!visited[i])) {
			totWeight += matrix[start][i];
			DFS(i, goal, size, visited);
		}
	}
}
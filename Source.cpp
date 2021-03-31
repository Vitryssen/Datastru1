#include <iostream>
#include "reader.h"
#include "printer.h"
#include "convert.h"
using namespace std;
void DFS(int start, int goal, int size, vector<bool>& visited);
void resetVisited(vector<bool>& visited);
int allVisited(vector<bool>& visited, int start);
int allNodesReachable(adjacency_list_t test, vector<bool> visited);
bool validMatrix(adjacency_list_t test, vector<bool> visited);
std::vector<std::vector<double> > matrix;
double totWeight = 0;
bool incomplete = false;
int main() {
	adjacency_list_t test =	parse_file("export.txt");
	matrix = listToMatrix(test);
	vector<bool> visited(test.first.size(), false);
	if (validMatrix(test, visited)) {
		cout << "Valid matrix" << endl;

	}
	else
		cout << "Not valid matrix, node that failed " << allNodesReachable(test, visited) << endl;

}
bool validMatrix(adjacency_list_t test, vector<bool> visited) {
	for (int x = 0; x < test.first.size(); x++) {
		for (int i = 0; i < test.first.size(); i++) {
			DFS(i, x, test.first.size(), visited);
			if (allVisited(visited, i) != -1) {
				return false;
			}
			resetVisited(visited);
		}
	}
	return true;
}
int allNodesReachable(adjacency_list_t test, vector<bool> visited) {
	for (int x = 0; x < test.first.size(); x++) {
		for (int i = 0; i < test.first.size(); i++) {
			DFS(i, x, test.first.size(), visited);
			int valid = allVisited(visited, i);
			if (valid != -1) {
				return valid;
			}
			resetVisited(visited);
		}
	}
	return -1;
}
void resetVisited(vector<bool> &visited) {
	for (int i = 0; i < visited.size(); i++) {
		visited.at(i) = false;
	}
}
int allVisited(vector<bool>& visited, int start) {
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
#include <vector>
#include "reader.h"
void resetVisited(std::vector<bool>& visited) {
	for (int i = 0; i < visited.size(); i++) {
		visited.at(i) = false;
	}
}
int allVisited(std::vector<bool>& visited) {
	for (int i = 0; i < visited.size(); i++) {
		if (!visited.at(i)) {
			return i;
		}
	}
	return -1;
}
void DFS(int start, int size, std::vector<bool>& visited, std::vector<std::vector<double>> matrix)
{
	visited[start] = true;
	for (int i = 0; i < size; i++) {
		if (matrix[start][i] != 0 && (!visited[i])) {
			DFS(i, size, visited, matrix);
		}
	}
}
bool verifyMatrix(adjacency_list_t test, std::vector<std::vector<double>> matrix) {
	std::vector<bool> visited(test.first.size(), false);
	for (int x = 0; x < test.first.size(); x++) {
		for (int i = 0; i < test.first.size(); i++) {
			DFS(i, test.first.size(), visited, matrix);
			if (allVisited(visited) != -1) {
				return false;
			}
			resetVisited(visited);
		}
	}
	return true;
}
#include <iostream>
#include <list>
#include "reader.h"
#include "printer.h"
#include "convert.h"
using namespace std;
void DFS(int start, int goal, int size, vector<bool>& visited);
void BFS(int start, adjacency_list_t test);
void resetVisited(vector<bool>& visited);
int allVisited(vector<bool>& visited, int start);
int allNodesReachable(adjacency_list_t test, vector<bool> visited);
bool verifyMatrix(adjacency_list_t test, vector<bool> visited);
bool validMatrix(adjacency_list_t test);
std::vector<std::vector<double> > matrix;
double totWeight = 0;
bool incomplete = false;
int main() {
	adjacency_list_t test =	parse_file("export.txt");
	BFS(0, test);
	/*if (validMatrix) {
		matrix = listToMatrix(test);
	}
	else {
		return 0;
	}*/
}
void BFS(int start, adjacency_list_t test) {
	vector<bool> visited(test.first.size(), false);
	list<int> queue;
	visited[start] = true;
	queue.push_back(start);
	list<int>::iterator it;
	for (auto j = test.second.begin(); j != test.second.end(); j++) {
		cout << "Pair " << j[0].n1 << " and " << j[0].n2 << endl;
	}
	/*while (!queue.empty())
	{
		start = queue.front();
		//cout << start << " ";
		queue.pop_front();
		for (auto j = test.second.begin(); j != test.second.end(); j++) {
			if (j[0].n2 == start) {
				if (!visited[j[0].n1]) {
					visited[j[0].n1] = true;
					queue.push_back(j[0].n1);
					cout << " At node " << j[0].n2 << " adding node " << j[0].n1 << " to the queue" << endl;
				}
			}
		}
	}*/
}
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
#include <iostream>
#include <list>
#include "reader.h"
#include "printer.h"
#include "convert.h"
#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
using namespace std;
int main() {
	adjacency_list_t test = parse_file("export.txt");
	vector<std::vector<double>> matrix = listToMatrix(test);
	if (BFS(0, test) == -1) {
		cout << "BFS valid" << endl;
	}
	else {
		cout << "BFS not valid" << endl;
	}
	if (verifyMatrix(test, matrix)) {
		cout << "DFS valid" << endl;
	}
	else {
		cout << "DFS not valid" << endl;
	}
	dijkstra(matrix, 0, test.first.size());
	return 0;
}
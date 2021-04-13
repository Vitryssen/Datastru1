#include <iostream>
#include <list>
#include "reader.h"
#include "printer.h"
#include "convert.h"
#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
using namespace std;
/*
- Hur l�ng �r v�gen mellan Nackstav�gen till F�rr�det? Beskriv promenaden.
Nacksta node id 23
F�rr�det node id 37
V�gen fr�n 23 till 37
23 1 2 3 4 5 6 7 8 10 28 37
Vikt 105
- Hur l�ng �r v�gen mellan L319 och D025?
L319 node id 46
D025 node id 47
V�gen mellan 46 och 47
46 45 44 30 20 10 28 47
Vikt 32
- Hur l�ng �r v�gen fr�n Universitetet till Bite Line V�stra?
Universitet node id 20
Bite Line V�stra node id 19
V�gen mellan 20 och 19
20 10 8 7 6 5 4 3 19
Vikt 78
*/
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
	dijkstra(matrix, 20, test.first.size());
	return 0;
}
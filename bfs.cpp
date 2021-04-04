#include "reader.h"
#include "dfs.h"
#include <vector>
#include <list>
int BFS(int start, adjacency_list_t test) {
	std::vector<bool> visited(test.first.size(), false);
	std::list<int> queue;
	visited[start] = true;
	queue.push_back(start);
	std::list<int>::iterator it;
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
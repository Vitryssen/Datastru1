/*
2020-04-19
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 1
*/
#include "reader.h"
#include "dfs.h"
#include <vector>
#include <list>
int BFS(int start, adjacency_list_t test) {
	std::vector<bool> visited(test.first.size(), false);
	std::list<int> queue;
	visited[start] = true;
	//At starting node to queue
	queue.push_back(start);
	std::list<int>::iterator it;
	while (!queue.empty())
	{
		//get the first node in queue and then pop it
		start = queue.front();
		queue.pop_front();
		//Check for neighbors from the node
		for (auto j = test.second.begin(); j != test.second.end(); j++) {
			//If there is a neighbor and it is not visited at it to the back of the queue
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
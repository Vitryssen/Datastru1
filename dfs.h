/*
2020-04-19
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 1
*/
#ifndef DFS_H
#define DFS_H
#include <vector>
//Function to check if it can reach all nodes from a given start node
//Input for size/number of nodes as well as a vector to keep visited nodes and a vector with node weights
void DFS(int start, int size, std::vector<bool>& visited, std::vector<std::vector<double>> matrix);
//Runs the dfs function on all nodes to check that the list/matrix is complete
bool verifyMatrix(adjacency_list_t test, std::vector<std::vector<double>> matrix);
//Resets a given bool vector
void resetVisited(std::vector<bool>& visited);
//Checks that all nodes is visited or returns the index of the first node that is not reached
int allVisited(std::vector<bool>& visited);
#endif
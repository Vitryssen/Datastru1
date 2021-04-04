#ifndef DFS_H
#define DFS_H
#include <vector>
void DFS(int start, int size, std::vector<bool>& visited, std::vector<std::vector<double>> matrix);
bool verifyMatrix(adjacency_list_t test, std::vector<std::vector<double>> matrix);
void resetVisited(std::vector<bool>& visited);
int allVisited(std::vector<bool>& visited);
#endif
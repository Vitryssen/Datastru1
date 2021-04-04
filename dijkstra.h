#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
int minDistance(std::vector<int> dist[], std::vector<bool> sptSet[], int size);
void dijkstra(std::vector<std::vector<double> > graph, int src, int size);
#endif
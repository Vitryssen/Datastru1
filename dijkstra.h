/*
2020-04-19
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 1
*/
#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
//Returns the index of the node that has the least weight that is reachable and not already visited
int minDistance(std::vector<double> dist, std::vector<bool> sptSet, int size);
//Prints all paths and their corresponding total weight from a given start node
void dijkstra(std::vector<std::vector<double> > graph, int src, int size);
#endif
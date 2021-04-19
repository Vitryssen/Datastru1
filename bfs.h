/*
2020-04-19
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 1
*/
#ifndef BFS_H
#define BFS_H
//Function to check if from a given startpoint it can reach all other nodes in the adjencency list
//Returns -1 if all nodes is visited, otherwise return index of node that is not reached
int BFS(int start, adjacency_list_t test);
#endif
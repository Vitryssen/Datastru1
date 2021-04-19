/*
2020-04-19
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 1
*/
#ifndef CONVERT_H
#define CONVERT_H
#include<vector>
#include "reader.h"
//Inputs list and returns an matrix
std::vector<std::vector<double> > listToMatrix(adjacency_list_t test);
#endif
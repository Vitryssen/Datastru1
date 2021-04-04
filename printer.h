#ifndef PRINTER_H
#define PRINTER_H

#include <istream>
#include <map>
#include <vector>
#include "reader.h"
void printList(adjacency_list_t test);
void printMatrix(adjacency_list_t test);
void printPath(std::vector<int> parent, int j);
void printSolution(std::vector<int> dist, int n, std::vector<int> parent);
#endif
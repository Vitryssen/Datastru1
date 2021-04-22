/*
2020-04-19
André Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 1
*/
#ifndef PRINTER_H
#define PRINTER_H

#include <istream>
#include <map>
#include <vector>
#include "reader.h"
//Prints all paths for the nodes and their corresponding weight
void printList(adjacency_list_t test);
//Same as the function above but for a matrix
void printMatrix(adjacency_list_t test);
//Recursive function to print djikstra path
void printPath(std::vector<int> parent, int index);
//Prints the solution to the djikstra algoritm
void printSolution(std::vector<double> distance, std::vector<int> parent, int src);
#endif
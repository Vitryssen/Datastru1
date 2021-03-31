#include "reader.h"
#include "convert.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
void printList(adjacency_list_t test) {
	for (int i = 0; i < test.first.size(); i++) {
		std::cout << i;
		for (auto it : test.second) {
			if (it.n1 == i)
				std::cout <<  " --> " << it.weight << " --> " << it.n2;
		}
		std::cout << std::endl;
	}
}
void printMatrix(adjacency_list_t test) {
	std::vector<std::vector<double> > matrix = listToMatrix(test);
	std::cout << "     ";
	for (int x = 0; x < matrix.size(); x++) {
		if (x < 10)
			std::cout << x << "     ";
		else
			std::cout << x << "    ";
	}
	std::cout << std::endl << "     -----------------------------------------------------------------------------------------------------------------------------------------------"<< std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		if(i < 10)
			std::cout << i << "  | ";
		else 
			std::cout << i << " | ";
		for (int j = 0; j < matrix.size(); j++) {
			std::ostringstream streamObj3;
			streamObj3 << std::fixed;
			streamObj3 << std::setprecision(2);
			streamObj3 << matrix[i][j];
			std::string strObj3 = streamObj3.str();
			std::cout << strObj3 << " ";
			if (matrix[i][j] < 10)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
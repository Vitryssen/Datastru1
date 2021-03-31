#include <vector>
#include "reader.h"
std::vector<std::vector<double> > listToMatrix(adjacency_list_t test) {
	std::vector<std::vector<double> > matrix(test.first.size(), std::vector<double>(test.first.size(), 0));
	for (int i = 0; i < test.first.size(); i++) {
		for (auto it : test.second) {
			if (it.n1 == i)
				matrix[i][it.n2] = it.weight;
		}
	}
	return matrix;
}
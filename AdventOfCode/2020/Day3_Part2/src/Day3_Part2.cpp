//============================================================================
// Name        : Day2_Part1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int countTrees(std::vector<string> const &vec, unsigned rigth, unsigned down) {
	unsigned curRow{0}, curCol{0}, realCurCol;
	unsigned colLen = vec[0].size();
	int count{0};
	while (curRow < vec.size() - 1) {
		curCol += rigth;
		curRow += down;
		realCurCol = curCol % colLen;
		if (vec[curRow].at(realCurCol) == '#')
			count++;
	}

	return count;
}

int main() {
	std::ifstream file;
	file.open("input.txt");
	string line;
	std::vector<string> vec{};

	if(file){

		while (!file.eof()) {
			std::getline(file, line);
			vec.push_back(line);
		}
		unsigned result = countTrees(vec, 1, 1)
				* countTrees(vec, 3, 1)
				* countTrees(vec, 5, 1)
				* countTrees(vec, 7, 1)
				* countTrees(vec, 1, 2);

		std::cout << result << std::endl;
	}

}

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

int main() {
	std::ifstream file;
	file.open("input.txt");
	string line;
	std::vector<string> vec{};


	int count{0};
	if(file){

		while (!file.eof()) {

			std::getline(file, line);
			vec.push_back(line);
		}

		unsigned colLen = vec[0].size();
		unsigned curRow{0}, curCol{0}, realCurCol;

		while(curRow < vec.size() - 1){
			curCol += 3;
			curRow += 1;
			realCurCol = curCol % colLen;
			if(vec[curRow].at(realCurCol) == '#') count++;
		}

		std::cout << count << std::endl;
	}

}

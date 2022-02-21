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


		std::for_each(std::begin(vec), std::end(vec),[&count](string input) {
			int firstPos, secondPos;
			char tmp, c;
			std::string sequence;
			std::istringstream istrs (input);
			istrs >> firstPos >> tmp >> secondPos >> c >> tmp >> sequence;

			firstPos--;
			secondPos--;

			if((sequence.at(firstPos) == c && sequence.at(secondPos) != c)
				|| (sequence.at(firstPos) != c && sequence.at(secondPos) == c)) count++;
		});

		std::cout << count << std::endl;
	}

}

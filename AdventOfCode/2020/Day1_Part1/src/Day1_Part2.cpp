//============================================================================
// Name        : Day1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>
#include <filesystem>

#include <windows.h>

using namespace std;

int main() {
	std::ifstream file;
	std::cout << "my directory is " << std::filesystem::current_path() << "\n";
	file.open("input.txt");

	if(file){
		std::vector<int> vec{};
		std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(vec));
		std::cout << "Size: " << vec.size() << std::endl;

		std::for_each(std::begin(vec), std::end(vec), [&vec](int first){
			std::for_each(std::begin(vec), std::end(vec), [&vec, first](int second){
				std::for_each(std::begin(vec), std::end(vec), [first, second](int third){
					if(first + second + third == 2020) std::cout << first * second * third<< std::endl;
				});
			});
		});
	}

}

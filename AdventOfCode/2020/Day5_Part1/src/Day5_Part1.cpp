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
#include <functional>
#include <ios>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <ostream>
#include <utility>
#include <regex>

using namespace std;
using Seat = string;

using Seats = std::map<int, string, std::less<int>>;


int seatIDToColumnNr(std::string const seatid) {
	std::string column = seatid.substr(7, 9);
	std::cout << "Column : " << column << std::endl;
	std::replace(column.begin(), column.end(), 'R', '1');
	std::replace(column.begin(), column.end(), 'L', '0');

	return std::stoi(column, 0, 2);
}

int seatIDToRowNr(std::string const seatid) {
	std::string row = seatid.substr(0, 7);
	std::cout << "Row : " << row << std::endl;
	std::replace(row.begin(), row.end(), 'B', '1');
	std::replace(row.begin(), row.end(), 'F', '0');
	return std::stoi(row, 0, 2);
}

int main() {
	std::ifstream file;
	file.open("input.txt");

	Seats seats{};

	while(!file.eof()){
		string seatId{};
		file >> seatId;
		int seatNumber = seatIDToRowNr(seatId) * 8 + seatIDToColumnNr(seatId);
		seats.insert(std::pair<int,string>(seatNumber, seatId));
	}


	std::cout << "Highest seat ID: " << std::prev(seats.end())->first << std::endl;
}



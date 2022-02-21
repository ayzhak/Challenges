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
#include <bitset>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using Seat = string;

using Seats = std::map<int, string, std::less<int>>;


string seatNrToSeatID(unsigned seatNr) {

	std::string seatid = std::bitset<16>(seatNr).to_string();
	seatid = seatid.substr(seatid.length() - 10, seatid.length());

	// column
	std::string column = seatid.substr(7, 9);
	std::replace(column.begin(), column.end(), '1', 'R');
	std::replace(column.begin(), column.end(), '0', 'L');

	// Row
	std::string row = seatid.substr(0, 7);
	std::replace(row.begin(), row.end(), '1', 'B');
	std::replace(row.begin(), row.end(), '0', 'F');

	return row + column;
}


int seatIDToseatNr(std::string const seatid) {

	std::string column = seatid.substr(7, 9);
	std::replace(column.begin(), column.end(), 'R', '1');
	std::replace(column.begin(), column.end(), 'L', '0');
	int columnNr = std::stoi(column, 0, 2);

	std::string row = seatid.substr(0, 7);
	std::replace(row.begin(), row.end(), 'B', '1');
	std::replace(row.begin(), row.end(), 'F', '0');
	int rowNr = std::stoi(row, 0, 2);

	return rowNr * 8 + columnNr;
}

int main() {
	auto start = chrono::high_resolution_clock::now();
	std::ifstream file;
	file.open("input.txt");

	Seats seats{};
	string seatId{};

	while(!file.eof()){
		file >> seatId;
		seats.insert(std::pair<int,string>(seatIDToseatNr(seatId), seatId));
	}

	//std::cout << "Count of seats : " << seats.size() << std::endl;
	//std::cout << "Lowest seat Nr : " << seats.begin()->first << std::endl;
	//std::cout << "Highest seat ID: " << std::prev(seats.end())->first << std::endl;


	for (int i =  seats.begin()->first; i < std::prev(seats.end())->first ; ++i) {
		if(seats.find(i) == seats.end()) {
			std::cout << "Missing seat ID: " << seatNrToSeatID(i) << std::endl;
			std::cout << "Missing seat Nr: " << i << std::endl;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;

	cout << "Time taken by program is : " << fixed
			<< time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}



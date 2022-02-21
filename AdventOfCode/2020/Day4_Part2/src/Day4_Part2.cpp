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
#include <ios>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include <regex>
#include <chrono>

using namespace std;
using Passport = std::map<string, string>;

using Passports = std::vector<Passport>;

void splitLineToKeyValues(Passport & passport, std::string line){
	std::istringstream iline(line);
	std::string word, key, value;

	while (!iline.eof()){
		iline >> word;
		key = word.substr(0, word.find(":"));
		value = word.substr(word.find(":") + 1, word.length());
		passport.insert(std::pair<string, string>(key, value));
	}
}

void convertToPassports(Passports & p, std::istream & io) {
	io >> std::noskipws;

	std::string line{};
	int curPassport {0};

	if(p.size() == 0) p.push_back(Passport());
	while(!io.eof()){
		std::getline(io, line);
		if(line.empty()){
			p.push_back(Passport());
			curPassport++;
			continue;
		}
		splitLineToKeyValues(p.at(curPassport), line);
	}
}

bool passportValidate(Passport & p){
	std::map<string,string> const requiredFields {
		{"byr", "^(19[2-9][0-9]|200[0-2])$"},
		{"iyr", "^(201[0-9]|2020)$"},
		{"eyr", "^20[2-3][0-9]$"},
		{"hgt", "^((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in)$"},
		{"hcl", "^#[0-9a-fA-F]{6}$"},
		{"ecl", "^(amb|blu|brn|gry|grn|hzl|oth)$"},
		{"pid", "^[0-9]{9}$"}
	};

	if(p.size() < 7) return false;

	for (pair<string, string> const field : requiredFields) {
		auto attribute = p.find(field.first);

		if(attribute == end(p)) return false;
		if(!std::regex_match (attribute->second, std::regex(field.second) )) return false;
	}

	return true;
}

int main() {
	auto start = chrono::high_resolution_clock::now();
	std::ifstream file;
	file.open("input.txt");
	string line;
	std::vector<string> vec{};

	int count{0};

	Passports p{};
	if(file){
		convertToPassports(p, file);

		std::for_each(begin(p), end(p), [&count](Passport passport){

			if(passportValidate(passport)){
					count++;
			}
		});
	}
	auto stop = high_resolution_clock::now();

	std::cout << "Matches found: " << count << std::endl;
}



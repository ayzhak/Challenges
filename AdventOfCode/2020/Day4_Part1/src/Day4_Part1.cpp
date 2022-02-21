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

void splitPassports(Passports & p, std::istream & io) {
	io >> std::noskipws;

	std::string line{};
	int curPassport {0};

	if(p.size() == 0) p.push_back(Passport());
	while(!io.eof()){
		std::getline(io, line);
		if(line.compare("") == 0){
			p.push_back(Passport());
			curPassport++;
			continue;
		}
		splitLineToKeyValues(p.at(curPassport), line);
	}
}

bool passportValidate(Passport & p){
	vector<string> const requiredFields {"byr","iyr","eyr", "hgt","hcl", "ecl","pid"};

	for(string field : requiredFields){
		if(p.find(field) == end(p)) return false;
	}

	return true;
}

int main() {
	std::ifstream file;
	file.open("input.txt");
	string line;
	std::vector<string> vec{};

	int count{0};

	Passports p{};
	if(file){
		splitPassports(p, file);

		std::for_each(begin(p), end(p), [&count](Passport passport){

			if(passportValidate(passport)){
					count++;
			}
		});
	}

	std::cout << "Matches found: " << count << std::endl;
}



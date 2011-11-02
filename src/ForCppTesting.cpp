//============================================================================
// Name        : ForCppTesting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void output(const std::string &s) {
  cout << " " << s;
}

int main() {
	// old style c++ to define and print a vector
	std::vector<std::string> v1;
	v1.push_back("Eins");
	v1.push_back("Zwei");
	v1.push_back("Drei");
	v1.push_back("Vier");
	v1.push_back("Fuenf");

	for_each(v1.begin(), v1.end(), output);
	cout << endl;

	// c++11 style to define a vector
	std::vector<std::string> v2 = {"Eins", "Zwei", "Drei", "Vier", "Fuenf"};
	// one c++11 style to print a vector
	for(std::string &str : v2){
		cout << " " << str;
	}
	// TODO: another c++11 style to print a vector

	return 0;
}

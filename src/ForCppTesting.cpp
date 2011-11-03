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
	cout << "old style: ";
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
	cout << "new style 1: ";
	for(std::string &str : v2){
		cout << " " << str;
	}
	cout << endl;

	// another c++11 style to print a vector
	cout << "new style 2: ";
	for(auto iter = v2.begin(); iter != v2.end(); ++iter){
		cout << " " << *iter;
	}
	cout << endl;

	// another c++11 style to print a vector
	cout << "new style 3: ";
	for_each(v2.begin(), v2.end(), [](const std::string s){cout << " " << s;});

	return 0;
}

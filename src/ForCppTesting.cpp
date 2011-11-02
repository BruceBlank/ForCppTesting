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
	std::vector<std::string> v;
	v.push_back("Eins");
	v.push_back("Zwei");
	v.push_back("Drei");

	for_each(v.begin(), v.end(), output);
	cout << endl;
	return 0;
}

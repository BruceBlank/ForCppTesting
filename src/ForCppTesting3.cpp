/*
 * ForCppTesting3.cpp
 *
 *  Created on: 12.12.2014
 *      Author: bruce
 */

#include <exception>
#include <string>
#include <iostream>

// class for bad construction of pseudo-singletons
class ConstructionExcept : public std::exception {
public:
	std::string className;
	ConstructionExcept(std::string cn) : className(cn){}
};

class ClassN {
private:
	static bool ms_alreadyCreated;

public:
	ClassN(){
		// throw exception, if an object has already been created before
		if(ms_alreadyCreated) throw ConstructionExcept("ClassN");
		ms_alreadyCreated = true;
		// other code
	}
	~ClassN(){
		ms_alreadyCreated = false;
	}
};
bool ClassN::ms_alreadyCreated = false;

int main()
{
	try{
		// try with and without the bracket
		{
			std::cout << "Create the first time." << std::endl;
			ClassN cn1;
		}
		std::cout << "Create the second time." << std::endl;
		ClassN cn2;
		std::cout << "Still alive." << std::endl;
	}catch(ConstructionExcept &ce){
		std::cout << "Bad constrcution for class " << ce.className << std::endl;
	}

	return 0;
}

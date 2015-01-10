/** @file
 This program demonstrates the basic usage of the new C++11 pointer types
 unique_ptr<> and shared_ptr<>
 */

#include <memory>
#include <iostream>
using namespace std;

//! Just a helper class to demonstrate the basic usage of the new C++11 pointer types
class One {
public:
	//! The (default) constructor
	One(){
		cout << "* class One: Constructor" << endl;
	}

	//! The destructor
	~One(){
		cout << "* class One: Destructor" << endl;
	}

	//! Print out a string, showing that the object is still alive
	void print() const{
		cout << "* class One: print" << endl;
	}
};

//! unique_ptr cannot be copied => one pointer-value per object One
//! function parameter is a reference
void funcUnique(unique_ptr<One> &p)
{
	cout << "funcUnique begin" << endl;
	p->print();
	cout << "funcUnique end" << endl;
}

//! shared_ptr can be copied using reference counting
//! function parameter is not a reference => pointer will be copied on call
void funcShared(shared_ptr<One> p)
{
	cout << "funcShared begin" << endl;
	p->print();
	cout << "funcShared end" << endl;
}

int main()
{
	cout << "main begin\n" << endl;

	cout << "*** Demonstrate unique_ptr ***" << endl;
	cout << "block begin" << endl;
	{
		unique_ptr<One> pointer(new One());
		pointer->print();
		funcUnique(pointer);
		pointer->print();
	}
	cout << "block end" << endl;
	cout << endl;

	cout << "*** Demonstrate shared_ptr ***" << endl;
	cout << "block begin" << endl;
	shared_ptr<One> anotherPointer;
	{
		shared_ptr<One> pointer(new One());
		pointer->print();
		funcShared(pointer);
		pointer->print();
		anotherPointer = pointer;
	}
	cout << "block end" << endl;
	anotherPointer->print();

	cout << "\nmain end" << endl;
	return 0;
}

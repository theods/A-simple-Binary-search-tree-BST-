#include "BSTtemp.h"
#include <iostream>
#include <fstream>
#include <string>
//#include "Date.h"

using namespace std;

int main() {
	ifstream intInput("inputInt.txt");
	BSTtemp<int> intTest;
	int y;

	while (!intInput.eof()) {
		intInput >> y;
		intTest.Insert(y);
	}
	cout << "In order: " << endl;
	intTest.inorderTraversal();

	cout << endl;

	cout << "Post order: " << endl;
	intTest.postorderTraversal();
	cout << endl;

	system("pause");
	return 0;
}
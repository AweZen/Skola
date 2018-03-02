#include <string>
#include <iostream>
#include "Stack.h"
using namespace std;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	try {
		cout << s.peek() << endl;
	}
	catch (string e) {
		cout << e << endl;
	}

	try {
		cout << s.pop() << endl;
	}
	catch (string e) {
		cout << e << endl;
	}

	if (!s.isEmpty()) {
		try {
			cout << s.pop() << endl;
		}
		catch (string e) {
			cout << e << endl;
		}
		try {
			cout << s.pop() << endl;
		}
		catch (string e) {
			cout << e << endl;
		}
		try {
			cout << s.pop() << endl;
		}
		catch (string e) {
			cout << e << endl;
		}

	}


	try {
		cout << s.peek() << endl;
	}
	catch (string e) {
		cout << e << endl;
	}

	try {
		cout << s.pop() << endl;
	}
	catch (string e) {
		cout << e << endl;
	}

	if (s.isEmpty()) {
		cout << "Stack Empty" << endl;
	}
	system("pause");
	return 0;
}
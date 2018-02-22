#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<string> test(10, 10);
	try
	{
		cout << test.getFirst() << endl;
	}catch(string e)
	{
		cout << e << endl;
	}
	/*test.addFirst("hej");
	test.addFirst("I WAS FIRST");

	cout << test.getFirst() << endl;
	test.addFirst("I WAS FIRST AGIAN");
	cout << test.getFirst() << endl;
	cout << test.getFirst() << endl;
	test.addAt("first", 0);
	cout << test.getFirst() << endl;*/



	

	system("pause");
	return 0;
}
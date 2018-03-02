#include <string>
#include<iostream>
#include<ctime>
using namespace std;

template<typename T>
int partition(T theArray[], int start, int end);

template<typename T>
void swapThem(T& item1, T& item2);

template<typename T>
void sort(T theArray[], int start, int end);


int faculty(int n);
void info(int nr);
int sum(int start, int end);

int main() {
	//info(5);

	//cout << faculty(1) << endl;
	const int CAP = 100000;
	int nrs[CAP] = { 0 };
	for (int i = 0; i < CAP; i++) {
		nrs[i] = rand() % 1000 + 1;
	}

	/*for (int i = 0; i < CAP - 1; i++) {
		cout << nrs[i] << ", ";
	}
	cout << nrs[CAP - 1] << endl << endl << endl;*/
	time_t startTime = clock();
	sort(nrs, 0, CAP-1);
	time_t endTime = clock();

	//for (int i = 0; i < CAP-1; i++) {
	//	cout << nrs[i] << ", ";
	//}
	//cout << nrs[CAP - 1] << endl;

	cout << endTime - startTime << endl;
	system("pause");
	return 0;
}

template<typename T>
void sort(T theArray[], int start, int end) {
	if (start < end) {
		int pivotP = partition(theArray, start, end);
		sort(theArray, start, pivotP - 1);
		sort(theArray, pivotP + 1, end);
	}
}

template<typename T>
int partition(T theArray[], int start, int end) {
	T pivotValue = theArray[start];
	int pivotPosition = start;
	for (int i = start + 1; i <= end; i++) {
		if (theArray[i] < pivotValue) {
			swapThem(theArray[pivotPosition + 1], theArray[i]);
			swapThem(theArray[pivotPosition], theArray[pivotPosition +1]);
			pivotPosition++;
		}
	}
	return pivotPosition;
}

template<typename T>
void swapThem(T& item1, T& item2) {
	T temp;
	temp = item1;
	item1 = item2;
	item2 = temp;
}

int faculty(int n) {
	if (n > 1) {
		return n * faculty(n - 1);
	}
	else {
		return 1;
	}
}
void info(int nr) {
	if (nr > 0) {
		cout << "Number now == " << nr << endl;
		info(nr - 1);
	}
	cout << " info(...) leaving with number == " << nr << endl;
}

int sum(int start, int end) {
	if (start >= end) {
		return start + sum(start - 1, end);
	}
	else {
		return 0;
	}
}
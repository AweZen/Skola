
#include <iostream>
#include <string>

using namespace std;

//void sort(int array[], int nrOfElements);
//void print(int array[], int nrOfElements);
//void print(string array[], int nrOfElements);
//void sort(string array[], int nrOfElements);

template<typename T>
void print(T array[], int nrOfElements);
template<typename T>
void sort(T array[], int nrOfElements);
template<typename T>
int search(T array[], T search, int nrOfElements);

template<typename T>
int binarySearch(T array[], T search, int nrOfElements);



int main()
{
	const int CAP = 6;
	int array[CAP] = { 8,4,15,2,11,6 };
	string strarr[CAP] = { "Kajsa","Karin","Nisse","Adam","Anna","Kurt" };

	print(array,CAP);
	sort(array,CAP);
	print(array,CAP);

	print(strarr, CAP);
	sort(strarr, CAP);
	print(strarr, CAP);
	string search = "Kajsa";
	int test;
	//test = search(strarr,search,CAP);
	test = binarySearch(strarr, search, CAP);

	cout << strarr[test] << endl;
	system("pause");
	return 0;
}

void sort(int array[], int nrOfElements)
{
	int temp = 0;
	int minIndex = 0;
	for (int i = 0; i < nrOfElements-1; i++)
	{
		minIndex = i;
		for (int k = i + 1; k < nrOfElements; k++) {
			if (array[k] < array[minIndex])
			{
				minIndex = k;
			}
		}
		temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}

}

void print(int array[], int nrOfElements)
{
	for (int i = 0; i < nrOfElements; i++)
	{
		if (i != 0)
		{
			cout << ", ";
		}
		cout << array[i];
	}
	cout << endl << endl;
}

template<typename T>
void print(T array[], int nrOfElements)
{
	for (int i = 0; i < nrOfElements; i++)
	{
		if ( i != 0)
		{
			cout <<  ", ";
		}
		cout << array[i];
	}
	cout << endl << endl;
}

template<typename T>
void sort(T array[], int nrOfElements)
{
	T temp;
	int minIndex = 0;
	for (int i = 0; i < nrOfElements - 1; i++)
	{
		minIndex = i;
		for (int k = i + 1; k < nrOfElements; k++) {
			if (array[k] < array[minIndex])
			{
				minIndex = k;
			}
		}
		temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}

}

template<typename T>
int search(T array[], T search, int nrOfElements)
{
	int pos = -1;
	for (int i; i < nrOfElements && pos == -1; i++)
	{
		if (array[i] == search)
		{
			pos = i;
		}
	}
	return pos;
}
template<typename T>
int binarySearch(T array[], T search, int nrOfElements)
{
	int min = 0;
	int max = nrOfElements;
	int middle = nrOfElements / 2;
	while (search != array[middle] && min < max)
	{
		if(search < array[middle])
		{
			max = middle - 1;
			middle = (max + min) / 2;
		}else
		{
			min = middle + 1;
			middle = (max + min) / 2;

		}
	}
	return middle;
}

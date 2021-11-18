#include <iostream>
#include <conio.h>
#define N 10000;

using namespace std;

int linearSearch(int[], int, int);
int BinSearchQuick(int[], int);

int main()
{
	const int size = 10000;
	int a[size], search1 = 20, search2 = 100, search3 = 1000, search4 = 10000, element1, element2;
	double result1 = log2(search1), result2 = log2(search2), result3 = log2(search3), result4 = log2(search4);
	for (int x = 0; x < size; x++)
		a[x] = 2 * x;

	clock_t start11 = clock();
	clock_t start1 = clock();
	cout << "\n\tLINEAR SEARCH\n";
	cout << "\n\tAmount of elements: 20 ";
	element1 = linearSearch(a, search1, size);
	if (element1 != -1)
		cout << "\n\tFound values in element: " << element1 << endl;
	else
		cout << "\tNo values found" << endl;
	cout << "\tNumber of comparisons: " << result1 << endl;
	clock_t end1 = clock();
	printf("\tSearch time: %f\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

	clock_t start2 = clock();
	cout << "\n\tAmount of elements: 100 ";
	element1 = linearSearch(a, search2, size);
	if (element1 != -1)
		cout << "\n\tFound values in element: " << element1 << endl;
	else
		cout << "\tNo values found" << endl;
	cout << "\tNumber of comparisons: " << result2 << endl;
	clock_t end2 = clock();
	printf("\tSearch time: %f\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

	clock_t start3 = clock();
	cout << "\n\tAmount of elements: 1000 ";
	element1 = linearSearch(a, search3, size);
	if (element1 != -1)
		cout << "\n\tFound values in element: " << element1 << endl;
	else
		cout << "\tNo values found" << endl;
	cout << "\tNumber of comparisons: " << result3 << endl;
	clock_t end3 = clock();
	printf("\tSearch time: %f\n", (double)(end3 - start3) / CLOCKS_PER_SEC);

	clock_t start4 = clock();
	cout << "\n\tAmount of elements: 10000 ";
	element1 = linearSearch(a, search4, size);
	if (element1 != -1)
		cout << "\n\tFound values in element: " << element1 << endl;
	else
		cout << "\tNo values found" << endl;
	cout << "\tNumber of comparisons: " << result4 << endl;
	clock_t end4 = clock();
	printf("\tSearch time: %f\n", (double)(end4 - start4) / CLOCKS_PER_SEC);

	clock_t end11 = clock();
	printf("\n\tAll time for linear search: %f\n", (double)(end11 - start11) / CLOCKS_PER_SEC);

	cout << "\n\t============================\n";

	clock_t start10 = clock();
	clock_t start5 = clock();
	cout << "\n\tBINARY SEARCH\n";
	cout << "\n\tAmount of elements: 20 ";
	element2 = BinSearchQuick(a, search1);
	if (element2 != -1)
		cout << "\n\tFound values in element: " << element2 << endl;
	else
		cout << "\tNo values found" << endl;
	cout << "\tNumber of comparisons: " << result1 << endl;
	clock_t end5 = clock();
	printf("\tSearch time: %f\n", (double)(end5 - start5) / CLOCKS_PER_SEC);

	clock_t start6 = clock();
	cout << "\n\tAmount of elements: 100 ";
	element2 = BinSearchQuick(a, search2);
	if (element2 != -1)
		cout << "\n\tFound values in element: " << element2 << endl;
	else
		cout << "\tNo values found" << endl;
	cout << "\tNumber of comparisons: " << result2 << endl;
	clock_t end6 = clock();
	printf("\tSearch time: %f\n", (double)(end6 - start6) / CLOCKS_PER_SEC);

	clock_t start7 = clock();
	cout << "\n\tAmount of elements: 1000 ";
	element2 = BinSearchQuick(a, search3);
	if (element2 != -1)
		cout << "\n\tFound values in element: " << element2 << endl;
	else
		cout << "\tNo values found" << endl;
	cout << "\tNumber of comparisons: " << result3 << endl;
	clock_t end7 = clock();
	printf("\tSearch time: %f\n", (double)(end7 - start7) / CLOCKS_PER_SEC);

	clock_t start8 = clock();
	cout << "\n\tAmount of elements: 10000 ";
	element2 = BinSearchQuick(a, search4);
	if (element2 != -1)
		cout << "\n\tFound values in element: " << element2 << endl;
	else
		cout << "\tNo values found" << endl;
	cout << "\tNumber of comparisons: " << result4 << endl;
	clock_t end8 = clock();
	printf("\tSearch time: %f\n", (double)(end8 - start8) / CLOCKS_PER_SEC);

	clock_t end10 = clock();
	printf("\n\tAll time for binary search: %f\n", (double)(end10 - start10) / CLOCKS_PER_SEC);

	return 0;
}
int linearSearch(int array[], int key, int sizeOfArray)
{
	for (int n = 0; n < sizeOfArray; n++)
		if (array[n] == key)
			return n;
	return -1;
}
int BinSearchQuick(int array[], int key)
{
	int m, b = 0, e = N; 
	while (b <= e) 	
	{
		m = (b + e) / 2; 
		if (array[m] >= key) e = m - 1;
		else b = m + 1;
	}
	if (array[b] == key) return b;
	else return -1;
}


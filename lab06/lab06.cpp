
#include <iostream>
#include "list.h"
#include "vector.h"
using namespace std;
int main()
{
	clock_t start1 = clock();
	List list_str;
	list_str.Assign("hello my friend a z");
	list_str.Print();
	for (int i = 0; i < 10000; i++)
	list_str.UpperCase(4);
	list_str.Print();
	clock_t end1 = clock();
	printf("\nTime for list: %f", (double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << endl << endl;
	cout << sizeof(List);
	printf("\n=========================================================================\n\n");
	clock_t start2 = clock();
	MVector vector_str;
	vector_str.Assign("hello my friend a z");
	cout << vector_str.getString() << endl;
	for (int i = 0; i < 10000; i++)
	vector_str.UpperCase(4);
	cout << vector_str.getString() << endl;
	clock_t end2 = clock();
	printf("\nTime for vector: %f", (double)(end2 - start2) / CLOCKS_PER_SEC);
	cout << endl << endl;
	cout << sizeof(MVector) << endl;
	return 0;
}
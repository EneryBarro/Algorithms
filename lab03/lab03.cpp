
#include "stdlib.h"
#include "iostream"
#define PB(value)(byte*)(value)
#define LEN 3

using namespace std;
typedef unsigned char byte;
typedef unsigned int dword;
template <class T> 
void show(const T& value)
{
	for (dword i = 0; i < sizeof(T); i++)
	{
		byte Byte = *(PB(&value) + i);
		for (dword j = 0; j < 8; j++)
			cout << dword((Byte >> (7 - j)) & 1);
		cout << ' ';
	}
	cout << endl;
}
void BYTE(unsigned char A)
{
	for (int bit = 128; bit >= 1; bit >>= 1)
		cout << (A & bit ? "1" : "0");
	cout << " ";
}
void main()
{
	int val1 = 0;
	float val2 = 0;
	char va13 = '0';
	int val4[3] = { 0 };

	cout << "\nEnter int value :";
	cin >> val1;
	show(val1);

	cout << "\nEnter float value :";
	cin >> val2;
	show(val2);

	cout << "\nEnter char value :";
	cin >> va13;
	show(va13);

	cout << "\nEnter array value :";
	for (int i = 0; i < 3; i++) cin >> val4[i];
	show(val4);
}



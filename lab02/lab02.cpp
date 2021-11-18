//
//#include <iostream>
//#include <Windows.h>
//using namespace std;
//#define N 5
//unsigned long long get_timestamp()
//{
//	FILETIME ft;
//	LARGE_INTEGER li;
//	GetSystemTimeAsFileTime(&ft);
//	li.LowPart = ft.dwLowDateTime;
//	li.HighPart = ft.dwHighDateTime;
//	unsigned long long ret = li.QuadPart;
//	ret -= 116444736000000000LL;
//	ret /= 10000;
//	return ret;
//}
//void print(int* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//		printf("%d", arr[i]);
//}
//int FactR(int n) 
//{
//	int result;
//	if (n == 1)  return 1;
//	result = FactR(n - 1) * n;
//	return result;
//}
//int FactI(int n) 
//{
//	int result = 1;
//	for (int t = 1; t <= n; t++)  result *= t;
//	return result;
//}
//void main()
//{
//	setlocale(LC_CTYPE, "rus");
//	int arr[N] = { 0 };
//	unsigned long long t0 = 0, t1 = 0;
//	double R_sec, I_sec;
//	unsigned long long Ifac = 0, Rfac = 0;
//	t0 = get_timestamp();
//	for (int i = 0; i < 10000000; i++)
//		Rfac = FactR(N);
//	t1 = get_timestamp();
//	R_sec = (double)(t1 - t0) / 1000;
//	printf("\nРекурсивный метод : !%d = %d", N, FactR(N));
//	printf("\nThe time: %f seconds\n\n\n", R_sec);
//	t0 = get_timestamp();
//	for (int i = 0; i < 10000000; i++)
//		Ifac = FactI(N);
//	t1 = get_timestamp();
//	I_sec = (double)(t1 - t0) / 1000;
//	printf("Итерационный метод : !%d = %d", N, FactI(N));
//	printf("\nThe time: %f seconds\n\n\n", I_sec);
//	printf("Enter numbers:\n");
//	for (unsigned int i = 0; i < N; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//	int size = sizeof(arr) / sizeof(int);
//	printf("\n");
//	int i, j, r, k, cnt = 1;
//	while (1)
//	{
//		printf("%d : ", cnt++);
//		for (i = 0; i < N; i++)
//			printf("%d ", arr[i]);
//		printf("\n");
//		for (i = N - 1; i >= 0 && arr[i] > arr[i + 1]; i--);
//		if (i < 0) break;
//		for (j = N - 1; arr[i] > arr[j]; j--);
//		swap(arr[j], arr[i]);
//		for (k = i + 1, r = N - 1; r > k; k++, r--)
//			swap(arr[r], arr[k]);
//	}
//}



#include <iostream>
#include "Dll.h"

int main()
{
    CalculationApi obj;

    obj.Addition();

    obj.Subtraction();

    obj.Multiply();

    obj.Divide();

    return 0;
}

#include<iostream>
#include<conio.h>
using namespace std;
#define N 20

void Create1(int []);
void Copyarray1(const int [], int []);
void OutConsole1(int []);
void BarierSort1 (int []);
void OutConsole2(int[]);
void BarierSort2(int []);

void main()
{
    clock_t start1 = clock();
    int array1[N], copyarray1[N];
    Create1(array1);
    cout << "\nDYNAMIC ARRAY \n";
    OutConsole1(array1);
    Copyarray1 (array1, copyarray1);
    BarierSort1(array1);
    cout << "\nSORT ARRAY \n";
    OutConsole1(array1);
    clock_t end1 = clock();
    printf("\nTime for dynamic array: %f\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

    cout << "\t\n===============================================================================\n";

    clock_t start2 = clock();
    int b[20] = { 9, 5, 27, 17, 45, 66, 0, 26, 19, 65, 46, 3, 56, 76, 58, 8, 57, 71, 65, 33 };
    cout << "\nSTATIC ARRAY \n";
    OutConsole2(b);
    BarierSort2(b);
    cout << "\nSORT ARRAY \n";
    OutConsole2(b);
    clock_t end2 = clock();
    printf("\nTime for static array: %f\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
}
void Create1(int a[])
{   for(int i = 0; i < N; i++)
        a[i]=rand() % 100;
}
void Copyarray1(const int a[], int copy_a[])
{    for(int i = 0; i < N; i++)
	copy_a[i] = a[i];
}
void OutConsole1(int a[])
{   for(int i = 0; i < N; i++)
	cout << "  " << a[i];
    cout << "\n";
}
void BarierSort1 (int a[])
{  int  i,j,k,t;
   for( i=1; i< N; i++) 
   {  a[0]=a[i]; 
      t=a[i];  
	 j=i-1;	     	
       while (a[j]>t) 	
	 { a[j+1]=a[j]; 
	     j--;	 
	 }
	 a[j+1]=t;  
	}
}
void OutConsole2(int b[])
{
    for (int i = 0; i < N; i++)
       cout << "  " << b[i];
       cout << "\n";
}
void BarierSort2(int b[])
{
    int  i, j, k, t;
    for (i = 1; i < N; i++) 
    {
        b[0] = b[i]; 
        t = b[i];  
        j = i - 1;
        while (b[j] > t)
        {
            b[j + 1] = b[j];  
            j--;	
        }
        b[j + 1] = t;  
    }
}


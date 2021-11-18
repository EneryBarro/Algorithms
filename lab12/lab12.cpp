#include<iostream>
#include<conio.h>
#define N 20

using namespace std;

void Create(int[]);
void CopyArray(const int[], int[]);
void OutConsole(int[]);
void TournamantSort(int[]);
void bucketSort(int[]);
void MergeSort(int[]);
#define swap(x,y)  {int t=x; x=y; y=t;}


void main()
{
 
    int array[N], copyArray[N];
    Create(array);

    clock_t start1 = clock();
    cout << "\nTOURNAMANT SORT\n";
    cout << "\nORIGINAL ARRAY\n";
    OutConsole(array);
    CopyArray(array, copyArray);
    TournamantSort(array);
    cout << "\nSORT ARRAY \n";
    OutConsole(array);
    CopyArray(copyArray, array);
    clock_t end1 = clock();
    printf("\nTime: %f\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

    cout << "\t\n===============================================================================\n";

    clock_t start2 = clock();
    cout << "\nBUCKET SORT\n";
    cout << "\nORIGINAL ARRAY\n";
    OutConsole(array);
    bucketSort(array);
    cout << "\nSORT ARRAY \n";
    OutConsole(array);
    CopyArray(copyArray, array);
    clock_t end2 = clock();
    printf("\nTime: %f\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

    cout << "\t\n===============================================================================\n";

    clock_t start3 = clock();
    cout << "\nMERGE SORT\n";
    cout << "\nORIGINAL ARRAY\n";
    OutConsole(array);
    MergeSort(array);
    cout << "\nSORT ARRAY \n";
    OutConsole(array);
    clock_t end3 = clock();
    printf("\nTime: %f\n", (double)(end3 - start3) / CLOCKS_PER_SEC);
}
void Create(int a[])
{
    for (int i = 0; i < N; i++)
        a[i] = rand() % 100;
}
void CopyArray(const int a[], int copy_a[])
{
    for (int i = 0; i < N; i++)
        copy_a[i] = a[i];
}
void OutConsole(int a[])
{
    for (int i = 0; i < N; i++)
        cout << "  " << a[i];
    cout << "\n";
}
void bucketSort(int a[])
{
    int temp;
    int key = 0; 
    int i, j;
    for (i = 1; i < N - 1; i++)
    {
        if (key) break;
        key = 1;
        for (j = i; j < N - i; j++)
            if (a[j - 1] > a[j])
            {
                key = 0;
                temp = a[j - 1]; a[j - 1] = a[j]; a[j] = temp;
            }
        for (; i; i--)
            if (a[j] < a[j - 1])
            {
                key = 0;
                temp = a[j]; a[j] = a[j - 1]; a[j - 1] = temp;
            }
    }
}
void  TournamantSort(int a[])
{
    int tmp, i, j;

    for (i = 0; i < N - 1; ++i)
    {
        for (j = 0; j < N - 1; ++j) 
        {
            if (a[j + 1] < a[j])
            {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void downHeap(int a[], int k, int n)
{ 
    int new_elem;
    int child;
    new_elem = a[k];
    while (k <= n / 2)  		
    {
        child = 2 * k;
        if (child < n && a[child] < a[child + 1])
            child++;
        if (new_elem >= a[child]) break;
        a[k] = a[child]; 
        k = child;
    }
    a[k] = new_elem;
}
void MergeSort(int a[])
{
    int i;
    for (i = N / 2 - 1; i >= 0; i--) downHeap(a, i, N - 1);
    for (i = N - 1; i > 0; i--)
    { 
        swap(a[i], a[0]);
        downHeap(a, 0, i - 1);
    }
}



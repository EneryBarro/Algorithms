
#define SIZE 8
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

void RandMatrix(int arr[SIZE][SIZE]);

void PrintMatrix(int arr[SIZE][SIZE]);

void RandMatrix(int arr[SIZE][SIZE])
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (SIZE % 2 == 0)
            {
                if (j >= SIZE / 2)
                {
                    arr[i][j] = rand() % 50;
                }
                else
                {
                    arr[i][j] = 0;
                }
            }
            else
            {
                if (i >= (SIZE - 1) / 2)
                {
                    arr[i][j] = rand() % 50;
                }
                else
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
}

void PrintMatrix(int arr[SIZE][SIZE])
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            printf("%3i", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    const int inicializator = SIZE % 2 == 0 ? SIZE / 2 : (SIZE - 1) / 2;
    const size_t os_size = inicializator * SIZE;
    int one_string[os_size];
    int array[SIZE][SIZE];
    RandMatrix(array);
    PrintMatrix(array);
    int a;
    double begin_t = clock();
    for (int r = 1; r < 100000; r++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                a = array[i][j];
            }
        }
    }
    double end_t = clock();
    int k = 0;
    for (int i = inicializator; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            one_string[k] = array[j][i];
            k++;
        }
    }
    for (int j = 0; j < os_size; j++)
    {
        printf("%3i", one_string[j]);
    }
    double begin_an = clock();
    for (int r = 1; r < 100000; r++)
    {
        for (int i = 0; i < os_size; i++)
        {
            a = one_string[i];
        }
    }
    double end_an = clock();
    double time_spent_t = (double)(end_t - begin_t) / CLOCKS_PER_SEC;
    double time_spent_an = (double)(end_an - begin_an) / CLOCKS_PER_SEC;
    printf("\n\nTime for traditional: %f", time_spent_t);
    printf("\nTime for economical: %f\n", time_spent_an);
    return 0;
}


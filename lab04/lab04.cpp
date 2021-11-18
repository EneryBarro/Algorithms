
#include <iostream>
#include <conio.h>
using namespace std;

void BYTE(unsigned char A)
{
    for (int bit = 128; bit >= 1; bit >>= 1)
        cout << (A & bit ? '1' : '0');
    cout << ' ';
}

#pragma pack(push,1)
struct CargoAirplane2
{
    int Tons;
    short cars;
    short foods;
    short people;
    short electro;
    union
    {
        struct
        {
            double  weight;
            bool loaded;
        } our;
        struct
        {
            short foreing;
        } their;
    } add;
};

#pragma pack(pop)
struct CargoAirplane1
{
    int Tons;
    short cars;
    short foods;
    short people;
    short electro;
    union
    {
        struct
        {
            double  weight;
            bool loaded;
        } our;
        struct
        {
            short foreing;
        } their;
    } add;
};

void main()
{
    int byte1 = 0;
    clock_t start1 = clock();
    CargoAirplane1 prg1 = { 29675542, 1, 0, 0, 1 };
    prg1.add.our.weight = 6540034118;
    prg1.add.our.loaded = true;
    unsigned char* p1 = (unsigned char*)&prg1;
    for (; byte1 < sizeof(CargoAirplane1); byte1++, p1++)
    {
        if (byte1 && !(byte1 % 8)) cout << endl;
        BYTE(*p1);
    }
    clock_t end1 = clock();
    printf("\nTime without alignment: %f", (double)(end1 - start1) / CLOCKS_PER_SEC);
    cout << endl << endl;

    cout << sizeof(CargoAirplane1);

    printf("\n=========================================================================\n\n");


    int byte2 = 0;
    clock_t start2 = clock();
    CargoAirplane2 prg2 = { 29675542, 1, 0, 0, 1 };
    prg2.add.our.weight = 6540034118;
    prg2.add.our.loaded = true;
    unsigned char* p2 = (unsigned char*)&prg2;
    for (; byte2 < sizeof(CargoAirplane2); byte2++, p2++)
    {
        if (byte2 && !(byte2 % 8)) cout << endl;
        BYTE(*p2);
    }
    clock_t end2 = clock();
    printf("\nTime with alignment: %f", (double)(end2 - start2) / CLOCKS_PER_SEC);
    cout << endl << endl;

    cout << sizeof(CargoAirplane2);
    getchar(); getchar();

}





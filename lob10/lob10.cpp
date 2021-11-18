#include <iostream>
#include <string>
using namespace std;
int Insert(string& key, string& books, int tiket, int adr, int overload_num);
void Init();
int Search(string& key, int overload_num);
int Hash(string& key);

#define N 6
#define EMPTY -1

struct Book
{
    string surname;
    string books;
    int tiket;
    int adr = EMPTY;
};

Book hashTable[N];
Book overload[N];

int main()
{
    clock_t start1 = clock();
    string surname[N] = { "Ivanov", "Petrenko", "Semenov", "Savchenko", "Sergeev", "Sirik" };
    string books[N] = { "| 3 books | tiket", "| 4 books | tiket", "| 2 books | tiket", "| 6 books | tiket", "| 4 books | tiket", "| 5 books | tiket" };
    int tiket[N] = { 20, 25, 30, 35, 40, 45 };
    int overload_num = 0;
    int i;
    int res;
    string key;
    Init();
    cout << "\nKeys -> ";
    for (i = 0; i < N; i++)
        cout << surname[i] << " ";
    for (i = 0; i < N; i++)
        Insert(surname[i], books[i], tiket[i], i, overload_num);
    cout << "\nHashed table \n key - adr \n ";
    for (i = 0; i < N; i++)
        if (hashTable[i].adr != EMPTY)
            cout << "  " << hashTable[i].surname << " " <<
            hashTable[i].books << " " << hashTable[i].tiket <<
            " - " << hashTable[i].adr << "\n";
    for (i = 0; i < N; i++)
        if (overload[i].adr != EMPTY)
            cout << "  " << overload[i].surname << "  " << overload[i].books << "  " << overload[i].tiket << " - " << overload[i].adr << "\n";

    cout << " Input searched surname (key < 0 - exit) -> ";
    cin >> key;
    clock_t end1 = clock();
    printf("Search time: %f\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
    while (key >= "0") {
        res = Search(key, overload_num);
        if (res == EMPTY)	  
            cout << " not search \n";
        else	cout << " " << res << "\n";
        cout << " Input searched surname (key < 0 - exit) -> ";
        cin >> key;
    }
}

int Hash(string& key)
{
    int result = 0;
    for (auto c : key) {
        result += (char)c;
    }
    return (result % N);
}

void Init()
{
    for (auto& i : hashTable)
        i.adr = EMPTY;
}

int Insert(string& key, string& books, int tiket, int adr, int overload_num)
{
    int addr;
    addr = Hash(key);
    if (hashTable[addr].adr != EMPTY) {
        overload[overload_num].surname = key;
        overload[overload_num].adr = adr;
        overload[overload_num].books = books;
        overload[overload_num].tiket = tiket;
        overload_num++;
    }
    else {
        hashTable[addr].surname = key;
        hashTable[addr].adr = adr;
        hashTable[addr].books = books;
        hashTable[addr].tiket = tiket;
    }
    return 1;
}

int Search(string& key, int overload_num)
{
    int addr;
    addr = Hash(key);
    if (hashTable[addr].surname == key)
        return hashTable[addr].adr;
    else {
        int i = 0;
        while ((overload[i].surname != key) && (i <= overload_num))
            i++;
        return overload[i].surname != key ? EMPTY : overload[i].adr;
    }
}
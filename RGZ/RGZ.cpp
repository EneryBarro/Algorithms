#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

typedef struct List {
    int data;
    struct List* ptr_next;
} list;

list* init(int data);

void addelem(list* root, int data);

void show_list(list* root);

int check_count_of_empty_elem(list* root);

void fill_vector(list* root, int* vector, int size, int size_list);

void deleten(list** root, int n);

list* getNth(list* root, int n);

int getNth_vector(int* vector, int n);

int main() {
    srand(time(NULL));

    list* root = init(rand() % 100);
    cout << "Enter size of the array: ";
    int size = 0;
    cin >> size;
    size -= 1;
    int temp_size = size;

    for (int i = 0; i < size - 1; i++) {
        int j = rand() % 2;
        int k = rand() % 2;
        if (j == 0 || k == 0) {
            addelem(root, 0);
        }
        else {
            addelem(root, rand() % 100);
        }
    }
    addelem(root, rand() % 100);
    int number;
    cout << "Enter number you want to get: ";
    cin >> number;
    number -= 1;
    show_list(root);
    time_t start_list = clock();
    list* N_elem;
    for (int i = 0; i < 10000; i++) {
        N_elem = getNth(root, number);
    }
    time_t end_list = clock();

    cout << endl << "Elem " << number + 1 << ": " << N_elem->data << endl << endl;

    long double res_list = (long double)(end_list - start_list) / CLOCKS_PER_SEC;
    cout << "List time:" << res_list << endl << "---------------------------------------------------------------------------------------------" << endl << endl << "Delete elem" << endl << endl;
    int del = 0;
    //cout << "Enter index to delete: " << endl;
    //cin >> del;
    //deleten(&root, del);
    //show_list(root);

    int count = check_count_of_empty_elem(root);
    size = size - count + 1;
    int* vector;
    vector = new int[size];



    cout << "---------------------------------------------------------------------------------------------" << endl << endl << "vector " << endl << endl;


    time_t start_vector = clock();
    fill_vector(root, vector, size, temp_size);
    int N_elem_vector;
    for (int i = 0; i < 10000; i++) {
        N_elem_vector = getNth_vector(vector, number);
    }
    time_t end_vector = clock();
    for (int i = 0; i < size; i++) {
        cout << " " << vector[i];
    }
    cout << endl << "Elem " << number + 1 << ": " << N_elem_vector << endl << endl;

    long double res_vec = (long double)(end_vector - start_vector) / CLOCKS_PER_SEC;
    cout << endl << "Vector time: " << res_vec << endl << endl;

    return 0;
}

list* init(int data) {
    list* new_root = new list;
    new_root->data = data;
    new_root->ptr_next = NULL;
    return (new_root);
}

void addelem(list* root, int data) {
    list* current = root;
    while (current->ptr_next != NULL) {
        current = current->ptr_next;
    }
    current->ptr_next = new list;
    current->ptr_next->data = data;
    current->ptr_next->ptr_next = NULL;
}

int check_count_of_empty_elem(list* root) {
    int count = 0;
    do {
        if (root->data == 0)
            count++;
        root = root->ptr_next;
    } while (root != NULL);
    return(count);
}

void show_list(list* root) {
    cout << "list" << endl;
    do {
        cout << " " << root->data;
        root = root->ptr_next;
    } while (root != NULL);
    cout << endl << endl;
}

void fill_vector(list* root, int* vector, int size, int size_list) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size_list - 1; j++) {
            if (root->data == 0) {
                if (root->ptr_next != NULL) {
                    root = root->ptr_next;
                }
            }
        }
        vector[i] = root->data;
        root = root->ptr_next;
    }
}

list* getNth(list* root, int n) {
    int counter = 0;
    while (counter < n && root) {
        root = root->ptr_next;
        counter++;
    }
    return root;
}

int getNth_vector(int* vector, int n) {
    int temp;
    if (vector[n] == 0) {
        temp = getNth_vector(vector, n - 1);
    }
    else {
        temp = vector[n];
    }
    return temp;
}

void deleten(list** root, int n) {

    list* prev = getNth(*root, n - 1);
    list* elm = prev->ptr_next;
    int val = elm->data;

    prev->ptr_next = elm->ptr_next;
    free(elm);

}
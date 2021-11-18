#include <iostream>
using namespace std;


struct node {
    node* left;
    node* right;
    int val;
    node(int v) :left(NULL), right(NULL), val(v) {}
};

const node* tree_max(const node* tr);
void tree_add(node*& tr, int val);
void tree_clear(node* tr);



int main(void) {
    node* tr = NULL;

    int a[] = { 3, 6, 8, -3, 5, -4, 4 };
    cout << "\nTREE" << endl;
    for (int i = 0; i < 7; i++)
    {
       
        cout << "\n" << "" << a[i] << endl;
    }
    for (unsigned i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
        tree_add(tr, a[i]);

    const node* pmax = tree_max(tr);
    if (pmax != NULL)
        cout << "\nMAX KEY: " << pmax->val << endl;

    tree_clear(tr);
    cin.get();
    return 0;
}


const node* tree_max(const node* tr) {
    if (tr == NULL)
        return NULL;

    const node* p = tr;
    while (p->right != NULL)
        p = p->right;
    return p;
}

void tree_add(node*& tr, int val) {
    node** p = &tr;
    node* i = tr;
    while (i != NULL) {
        if (val < i->val) {
            p = &i->left;
            i = i->left;
        }
        else if (val > i->val) {
            p = &i->right;
            i = i->right;
        }
        else
            return;
    }
    *p = new node(val);
}

void tree_clear(node* tr) {
    if (tr != NULL) {
        if (tr->left != NULL)
            tree_clear(tr->left);
        if (tr->right != NULL)
            tree_clear(tr->right);
        delete tr;
    }
}
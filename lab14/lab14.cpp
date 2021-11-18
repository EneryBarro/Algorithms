#include "stdlib.h"
#include "stdio.h"
#include <iostream>
using namespace std;

struct node 
{
	int key;
	unsigned char height;
	node* left;
	node* right;
};
unsigned char Height(node* p)
{
	return p ? p->height : 0;
}
int Bfactor(node* p)
{
	return Height(p->right) - Height(p->left);
}
void FixHeight(node* p)
{
	unsigned char hl = Height(p->left);
	unsigned char hr = Height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}
node* RotateRight(node* p)
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	FixHeight(p);
	FixHeight(q);
	return q;
}
node* RotateLeft(node* q)
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	FixHeight(q);
	FixHeight(p);
	return p;
}
node* Balance(node* p)
{
	FixHeight(p);
	if (Bfactor(p) == 2)
	{
		if (Bfactor(p->right) < 0)
			p->right = RotateRight(p->right);
		return RotateLeft(p);
	}
	if (Bfactor(p) == -2)
	{
		if (Bfactor(p->left) > 0)
			p->left = RotateLeft(p->left);
		return RotateRight(p);
	}
	return p; 
}
node* Insert(node* p, int k) 
{
	if (!p)
	{
		p = new node;
		p->key = k; p->left = p->right = 0; p->height = 1;
		return p;
	}
	if (k < p->key)
		p->left = Insert(p->left, k);
	else
		p->right = Insert(p->right, k);
	return Balance(p);
}
node* FindMin(node* p) 
{
	return p->left ? FindMin(p->left) : p;
}
node* RemoveMin(node* p) 
{
	if (p->left == 0)
		return p->right;
	p->left = RemoveMin(p->left);
	return Balance(p);
}
node* Remove(node* p, int k)
{
	if (!p) return 0;
	if (k < p->key)
		p->left = Remove(p->left, k);
	else if (k > p->key)
		p->right = Remove(p->right, k);
	else
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = FindMin(r);
		min->right = RemoveMin(r);
		min->left = q;
		return Balance(min);
	}
	return Balance(p);
}
void Print(node* tree, int level)
{
	int i;
	if (tree == NULL)  return;
	Print(tree->left, level - 2);
	for (i = 0; i < level; i++)
		printf("-");
	printf("%d\n", tree->key);
	Print(tree->right, level - 2);
}
void Delete(node* tree) 
{
	if (tree == NULL) return;
	Delete(tree->left);
	Delete(tree->right);
	free(tree);
}

int main()
{
	int q = 0;
	node* tree = NULL;
	tree = Insert(tree, 9);  
	tree = Insert(tree, 6);
	tree = Insert(tree, 3);
	tree = Insert(tree, 0);
	tree = Insert(tree, 4);
	tree = Insert(tree, 13);
	tree = Insert(tree, 16);
	tree = Insert(tree, 19);
	tree = Insert(tree, 11);
	Print(tree, 30);
	printf("\n");
	cout << "\tElement to remove: ";
	cin >> q;
	printf("\n");
	Remove(tree, q);
	Print(tree, 30);
	Delete(tree);
	return 0;
}

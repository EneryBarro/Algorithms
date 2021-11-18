#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;

typedef struct _node {
    struct _node* next;
    int val;
} node;

typedef struct {
    node* lst;
} pqueue;

inline void pqueue_init(pqueue* pq) { pq->lst = NULL; }
inline  int pqueue_top(pqueue* pq) { return pq->lst->val; }
inline  int pqueue_empty(pqueue* pq) { return (pq->lst == NULL); }

int  pqueue_push(pqueue* pq, int val);
void pqueue_pop(pqueue* pq);
void pqueue_clear(pqueue* pq);


int pqueue_push(pqueue* pq, int val) {
    node* p, * i, ** q = &pq->lst;
    for (i = pq->lst; (i != NULL) && (i->val > val); ) {
        q = &i->next;
        i = i->next;
    }

    p = (node*)malloc(sizeof(node));
    if (p != NULL) {
        p->val = val;
        p->next = i;

        if (pq->lst == NULL)
            pq->lst = p;
        else
            *q = p;
    }
    return (p != NULL);
}


void pqueue_pop(pqueue* pq) {
    node* t;
    if (pq->lst != NULL) {
        t = pq->lst;
        pq->lst = pq->lst->next;
        free(t);
    }
}


void pqueue_clear(pqueue* pq) {
    node* t;
    while (pq->lst != NULL) {
        t = pq->lst;
        pq->lst = pq->lst->next;
        free(t);
    }
}


class PriorityQueue
{
public:
	enum Priority { Low, Normal, High };
	struct Item {
		Priority priority = Priority::Normal;
		int value = 0;
	};
	PriorityQueue() = default;

	~PriorityQueue();
	PriorityQueue(const PriorityQueue& source);
	PriorityQueue(PriorityQueue&& source);

	void Push(int value, Priority priority = Priority::Normal);
	void Pop();
	Item& Front();
	bool IsEmpty();
private:
	Item* _arr = nullptr;
	size_t _size = 0;
	size_t FindIndexByPriority(PriorityQueue::Priority pr);
};

PriorityQueue::~PriorityQueue()
{
	if (_arr)
	{
		delete[] _arr;
		_arr = nullptr;
		_size = 0;
	}
}
PriorityQueue::PriorityQueue(const PriorityQueue& source)
{
	_arr = new Item[source._size];
	for (size_t i = 0; i < source._size; i++)
	{
		_arr[i] = source._arr[i];
	}
	_size = source._size;
}
PriorityQueue::PriorityQueue(PriorityQueue&& source)
{
	_arr = source._arr;
	_size = source._size;
	source._arr = nullptr;
	source._size = 0;
}
//
void PriorityQueue::Push(int value, Priority priority)
{
	Item* tmp = new Item[_size + 1];
	size_t index = FindIndexByPriority(priority);
	for (size_t i = 0; i < index; i++)
	{
		tmp[i] = _arr[i];
	}
	tmp[index].priority = priority;
	tmp[index].value = value;
	for (size_t i = index; i < _size; i++)
	{
		tmp[i + 1] = _arr[i];
	}
	delete[] _arr;
	_arr = tmp;
	_size++;
}
void PriorityQueue::Pop()
{
	Item* tmp = new Item[_size - 1];
	for (size_t i = 0; i < _size - 1; i++)
	{
		tmp[i] = _arr[i + 1];
	}
	delete[] _arr;
	_arr = tmp;
	_size--;
}
PriorityQueue::Item& PriorityQueue::Front()
{
	return _arr[0];
}
bool PriorityQueue::IsEmpty()
{
	return _size == 0;
}
size_t PriorityQueue::FindIndexByPriority(PriorityQueue::Priority pr)
{
	size_t index = 0;
	for (; index < _size && _arr[index].priority >= pr; index++);
	return index;
}
int main()
{
	clock_t start1 = clock();
	printf("ARRAY\n");
	PriorityQueue pQueue;
	pQueue.Push(4);
	pQueue.Push(10, PriorityQueue::High);
	pQueue.Push(4, PriorityQueue::Low);
	pQueue.Push(4);
	pQueue.Push(9, PriorityQueue::High);
	pQueue.Push(2, PriorityQueue::Low);
	pQueue.Push(8, PriorityQueue::High);
	pQueue.Push(1, PriorityQueue::Low);
	pQueue.Push(8, PriorityQueue::High);
	pQueue.Push(0, PriorityQueue::Low);
	pQueue.Push(7, PriorityQueue::High);
	pQueue.Push(-10, PriorityQueue::Low);
	for (int i = 0; i < 10000; i++)
	while (!pQueue.IsEmpty())
	{
		PriorityQueue::Item item = pQueue.Front();
		switch (item.priority)
		{
		case PriorityQueue::High:
			cout << "High";
			break;
		case PriorityQueue::Normal:
			cout << "Normal";
			break;
		case PriorityQueue::Low:
			cout << "Low";
			break;
		}
		cout << " -> " << item.value << endl;
		pQueue.Pop();
	}
	clock_t end1 = clock();
	printf("\nTime for array: %f", (double)(end1 - start1) / CLOCKS_PER_SEC);

	printf("\n=============================================\n");

	clock_t start2 = clock();
	printf("STRUCK\n");

	int    i;
	pqueue pq;
	for (int i = 0; i < 10000; i++)
	pqueue_init(&pq);
	for (i = 0; i < 10; ++i)
		pqueue_push(&pq, rand() % 10);

	pqueue_push(&pq, 10);
	pqueue_push(&pq, -10);

	while (!pqueue_empty(&pq)) {
		printf("%d\n ", pqueue_top(&pq));
		pqueue_pop(&pq);
	}
	clock_t end2 = clock();
	printf("\nTime for struck: %f\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
	return 0;
}


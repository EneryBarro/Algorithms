
#include <stdio.h>
#include <stdlib.h>
#include "wList.h"
#include "mainList.h"
using namespace wList1;

void wList1::initializeHead(wList1::wList* ptrCurrentMain)
{
	ptrHead = ptrCurrentMain;
}
void wList1::initializeAux(wList1::wList* ptrAuxMain)
{
	ptrAux = ptrAuxMain;
}
wList1::wList* wList1::getPtrHead()
{
	return ptrHead;
}
wList1::wList* wList1::getPtrAux()
{
	return ptrAux;
}
wList1::wList* wList1::rightSearch(const int& id)
{
	wList* ptrTemp = ptrHead;
	if (ptrTemp->inf == id)
	{
		return ptrTemp;
	}
	if (ptrTemp->ptrLeft == ptrHead && ptrTemp->ptrRight == ptrHead)
	{
		return 0;
	}

	ptrTemp = ptrHead->ptrRight;
	while (ptrTemp != ptrHead)
	{
		if (ptrTemp->inf == id)
		{
			return ptrTemp;
		}
		ptrTemp = ptrTemp->ptrRight;
	}
	return 0;
}
wList1::wList* wList1::reverseSearch(const int& id)
{
	wList* ptrTemp = ptrHead;

	if (ptrTemp->inf == id)
	{
		return ptrHead;
	}
	if (ptrTemp->ptrLeft == ptrHead && ptrTemp->ptrRight == ptrHead)
	{
		return 0;
	}
	ptrTemp = ptrTemp->ptrLeft;
	while (ptrTemp != ptrHead)
	{
		if (ptrTemp->inf == id)
		{
			return ptrTemp;
		}
		ptrTemp = ptrTemp->ptrLeft;
	}
	return 0;
}
void wList1::pushAfter(const int& id)
{
	int key;
	int number;
	wList* ptrTemp;
	wList* ptrCurrent;
	if (!ptrHead)
	{
		ptrTemp = (wList*)malloc(sizeof(wList));
		if (ptrTemp)
		{
			ptrHead = ptrTemp;
			printf("\nEnter number\n");
			scanf_s("%d", &number);
			ptrHead->inf = number;
			ptrTemp->ptrRight = ptrTemp;
			ptrTemp->ptrLeft = ptrTemp;
			return;
		}
		else
		{
			printf("\nERROR\n");
			return;
		}
	}
loop1:
	printf("\n1-right search\n2-reverse search");
	scanf_s("%d", &key);
	switch (key)
	{
	case 1:
		ptrCurrent = wList1::rightSearch(id);
		break;
	case 2:
		ptrCurrent = wList1::reverseSearch(id);
		break;
	default:
		goto loop1;
		break;
	}

	if (!ptrCurrent)
	{
		printf("\nElement not found\n");
		return;
	}
loop2:
	printf("\n1-Create new element\n2-Enter element from auxiliary list");
	scanf_s("%d", &key);
	switch (key)
	{
	case 1:
		ptrTemp = (wList*)malloc(sizeof(wList));
		if (ptrTemp)
		{
			printf("\nEnter element\n");
			scanf_s("%d", &number);
			ptrTemp->inf = number;
			ptrTemp->ptrRight = ptrCurrent->ptrRight;
			ptrTemp->ptrLeft = ptrCurrent;
			ptrCurrent->ptrRight->ptrLeft = ptrTemp;
			ptrCurrent->ptrRight = ptrTemp;
			return;
		}
		else if (ptrTemp == NULL)
		{
			printf("\nERROR\n");
			return;
		}
		return;
	case 2:
		if (ptrAux)
		{
			ptrAux->ptrRight = ptrCurrent->ptrRight;
			ptrAux->ptrLeft = ptrCurrent;
			ptrCurrent->ptrRight->ptrLeft = ptrAux;
			ptrCurrent->ptrRight = ptrAux;
			ptrAux = ptrAux->ptrLeft;
			return;
		}
		else if (ptrAux == NULL)
		{
			printf("\nauxiliary list empty\n");
			goto loop2;
		}
	default:
		goto loop2;
		break;
	}
}
void wList1::pushBefore(const int& id)
{
	int key;
	int number;
	wList* ptrTemp;
	wList* ptrCurrent;
	if (!ptrHead)
	{
		ptrTemp = (wList*)malloc(sizeof(wList));
		if (ptrTemp)
		{
			printf("\nEnter element\n");
			scanf_s("%d", &number);
			ptrHead = ptrTemp;
			ptrHead->inf = number;
			ptrTemp->ptrRight = ptrTemp;
			ptrTemp->ptrLeft = ptrTemp;
			return;
		}
		else
		{
			printf("\nERROR\n");
			return;
		}
	}

loop1:
	printf("\n1-right search\n2-reverse search");
	scanf_s("%d", &key);
	switch (key)
	{
	case 1:
		ptrCurrent = wList1::rightSearch(id);
		break;
	case 2:
		ptrCurrent = wList1::reverseSearch(id);
		break;
	default:
		goto loop1;
		break;
	}

	if (!ptrCurrent)
	{
		printf("\nElement not found\n");
		return;
	}
loop2:
	printf("\n1-Create new element\n2-Enter element from auxiliary list");
	scanf_s("%d", &key);
	switch (key)
	{
	case 1:
		ptrTemp = (wList*)malloc(sizeof(wList));
		if (ptrTemp)
		{
			printf("\nEnter element\n");
			scanf_s("%d", &number);
			ptrTemp->inf = number;
			ptrTemp->ptrLeft = ptrCurrent->ptrLeft;
			ptrTemp->ptrRight = ptrCurrent;
			ptrCurrent->ptrLeft->ptrRight = ptrTemp;
			ptrCurrent->ptrLeft = ptrTemp;
			if (ptrCurrent == ptrHead)
				ptrHead = ptrTemp;
			return;
		}
		else
		{
			printf("\nERROR\n");
			return;
		}
	case 2:
		if (ptrAux)
		{
			ptrCurrent->ptrLeft->ptrRight = ptrAux;
			ptrCurrent->ptrLeft = ptrAux;
			ptrTemp = ptrAux->ptrRight;
			ptrAux->ptrRight = ptrCurrent;
			ptrAux->ptrLeft = ptrCurrent->ptrLeft;
			ptrAux = ptrTemp;
			if (ptrCurrent == ptrHead)
				ptrHead = ptrTemp;
			return;
		}
		else if (ptrAux == NULL)
		{
			printf("\nAux list empty\n");
			goto loop2;
		}
		break;
	default:
		goto loop2;
	}
}
void wList1::showRight()
{
	wList* ptrTemp = ptrHead;
	if (!ptrTemp)
	{
		printf("wList empty");
		return;
	}
	printf("\n%d", ptrTemp->inf);

	if (ptrTemp->ptrLeft == ptrHead && ptrTemp->ptrRight == ptrHead)
		return;

	ptrTemp = ptrHead->ptrRight;
	while (ptrTemp != ptrHead)
	{
		printf("\n%d", ptrTemp->inf);
		ptrTemp = ptrTemp->ptrRight;
	}

}
void wList1::showReverse()
{
	wList* ptrTemp = ptrHead;
	if (!ptrTemp)
	{
		printf("wList empty");
		return;
	}
	printf("\n%d", ptrTemp->inf);
	if (ptrTemp->ptrLeft == ptrHead && ptrTemp->ptrRight == ptrHead)
		return;

	ptrTemp = ptrTemp->ptrLeft;
	while (ptrTemp != ptrHead)
	{
		printf("\n%d", ptrTemp->inf);
		ptrTemp = ptrTemp->ptrLeft;
	}
}

void wList1::showAux()
{
	wList* ptrTemp = ptrAux;
	if (!ptrTemp)
	{
		printf("\nAux list empty\n");
		return;
	}
	while (ptrTemp)
	{
		printf("\nElement aux %d", ptrTemp->inf);
		ptrTemp = ptrTemp->ptrRight;
	}

}
void wList1::pop(const int& id)
{
	int key;
	wList* ptrTemp;
	wList* ptrCurrent;
	if (!ptrHead)
	{
		printf("\nList empty\n");
		return;
	}
loop1:
	printf("\n1-right search\n2-reverse search");
	scanf_s("%d", &key);
	switch (key)
	{
	case 1:
		ptrCurrent = wList1::rightSearch(id);
		break;
	case 2:
		ptrCurrent = wList1::reverseSearch(id);
		break;
	default:
		goto loop1;
	}
	if (!ptrCurrent)
	{
		printf("\nElement not found\n");
		return;
	}
loop2:
	printf("\n1-delete element with free\n2-transfer element in auxiliary list\n");
	scanf_s("%d", &key);
	switch (key)
	{
	case 1:
		ptrCurrent->ptrLeft->ptrRight = ptrCurrent->ptrRight;
		ptrCurrent->ptrRight->ptrLeft = ptrCurrent->ptrLeft;
		free(ptrCurrent);
		break;
	case 2:
		ptrCurrent->ptrLeft->ptrRight = ptrCurrent->ptrRight;
		ptrCurrent->ptrRight->ptrLeft = ptrCurrent->ptrLeft;
		ptrCurrent->ptrRight = ptrAux;
		ptrCurrent->ptrLeft = NULL;
		ptrAux = ptrCurrent;
		break;
	default:
		goto loop2;
		break;
	}
}
void wList1::popBranch()
{
	wList* ptrTemp = ptrHead->ptrLeft;
	ptrHead->ptrLeft = 0;
	wList* ptrDel;
	while (ptrTemp)
	{
		ptrDel = ptrTemp;
		ptrTemp = ptrTemp->ptrLeft;
		free(ptrDel);
	}
}
void wList1::popAux()
{
	if (ptrAux)
	{
		wList* ptrTemp = ptrAux->ptrRight;
		wList* ptrDel = ptrAux;

		while (ptrTemp)
		{
			free(ptrDel);
			ptrDel = ptrTemp;
			ptrTemp = ptrTemp->ptrRight;
		}
	}
}

void wList1::menu(wList1::wList* ptrCurrentMain, wList1::wList* ptrAux)
{
	initializeHead(ptrCurrentMain);
	initializeAux(ptrAux);

	int key;
	int number;

	printf("\n1-push after element\n2-push before element\n3-show base list(easy flow direction)\n4-show base list (reverse)\n5-pop\n6-show auxiliary list\n7-exit\n");
	scanf_s("%d", &key);
	while (1)
	{
		switch (key)
		{
		case 1:
			printf("\nEnter element\n");
			scanf_s("%d", &number);
			pushAfter(number);
			break;
		case 2:
			printf("\nEnter element\n");
			scanf_s("%d", &number);
			pushBefore(number);
			break;
		case 3:
			showRight();
			break;
		case 4:
			showReverse();
			break;
		case 5:
			printf("\nEnter element for find\n");
			scanf_s("%d", &number);
			pop(number);
			break;
		case 6:
			showAux();
			break;
		case 7:
			printf("\nBye\n");
			return;
		default:
			break;
		}
		printf("\n1-push after element\n2-push before element\n3-show base list(easy flow direction)\n4-show base list (reverse)\n5-pop\n6-show auxiliary list\n7-exit\n");
		scanf_s("%d", &key);
	}
}
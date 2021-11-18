#pragma once
#ifndef _wList_H
#define _wList_H
#include "wList.h"

namespace mainList1
{
	enum result_Add { NOT_FOUND, ADD_TRUE, ADD_FALSE };

	typedef struct mainList
	{
		int inf;
		mainList* ptrNext;
		wList1::wList* ptrSub;
		wList1::wList* ptrAuxSub;
	}_mainList;

	extern mainList* ptrHead;
	static mainList* ptrAux;
	void initMainList();
	mainList* afterSearchInMainList(const int& id);
	mainList* beforeSearchInMainList(const int& id);
	result_Add pushAfterInMainList(const int& id);
	result_Add pushBeforeInMainList(const int& id);
	void showMainList();
	void popInMainList(const int& id);
	void menuMainList();
}
#endif
#pragma once
#ifndef _mainList_H
#define _mainList_H
namespace wList1
{
	typedef struct wList
	{
		int inf;
		wList* ptrLeft;
		wList* ptrRight;
	}_wList;
	static wList* ptrHead;
	static wList* ptrAux;
	void initializeHead(wList1::wList*);
	void initializeAux(wList1::wList*);
	wList* getPtrHead();
	wList* getPtrAux();
	wList* rightSearch(const int& id);
	wList* reverseSearch(const int& id);
	void pushAfter(const int& id);
	void pushBefore(const int& id);
	void showRight();
	void showReverse();
	void showAux();
	void popBranch();
	void popAux();
	void pop(const int& id);
	void menu(wList1::wList*, wList1::wList*);
}
#endif
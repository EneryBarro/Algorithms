#pragma once

#include <iostream>
#define BUF_MAXLEN 255
class List
{
public:
	List() = default;
	void Assign(const char* c_str);
	void UpperCase(unsigned int index);
	void Print() const;
	~List();
	List(const List& source);
	List(List&& source);
	List& operator=(const List& source);
	List& operator=(List&& source);
	void Clear();
private:
	class ListItem
	{
	public:
		ListItem() = default;
		explicit ListItem(char value) {
			this->value = value;
		}
		ListItem* next = nullptr;
		char value;
	};
	ListItem* _head = nullptr;
	size_t _size = 0;
	void AddItem(char value);
	void Copy(const List& src);
	void Move(List& src);
};

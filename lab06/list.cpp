

#include "list.h"
List::~List()
{
	Clear();
}
List::List(const List& source)
{
	Copy(source);
}
List::List(List&& source)
{
	Move(source);
}
List& List::operator=(const List& source)
{
	if (&source == this)
		return *this;
	Clear();
	Copy(source);
	return *this;
}
List& List::operator=(List&& source)
{
	if (&source == this)
		return *this;
	Clear();
	Move(source);
	return *this;
}
void List::AddItem(char value)
{
	ListItem* newItem = new ListItem(value);
	if (_head == nullptr)
	{
		_head = newItem;
	}
	else
	{
		ListItem* cursor = _head;
		while (cursor->next != nullptr)
		{
			cursor = cursor->next;
		}
		cursor->next = newItem;
	}
	_size++;
}
void List::Copy(const List& src)
{
	ListItem* tmp = src._head;
	while (tmp != nullptr)
	{
		AddItem(tmp->value);
		tmp = tmp->next;
	}
	_size = src._size;
}
void List::Move(List& src)
{
	_head = src._head;
	_size = src._size;
	src._head = nullptr;
	src._size = 0;
}
void List::Clear()
{
	if (_head)
	{
		ListItem* DelItem;
		while (_head != nullptr)
		{
			DelItem = _head;
			_head = _head->next;
			delete DelItem;
		}
		_size = 0;
	}
}
void List::Assign(const char* c_str)
{
	Clear();
	size_t cstr_size = strnlen_s(c_str, BUF_MAXLEN);
	if (cstr_size == 0)
		return;
	_head = new ListItem(c_str[0]);
	ListItem* tmp = _head;
	size_t i = 1;
	while (i < cstr_size)
	{
		AddItem(c_str[i]);
		tmp = tmp->next;
		i++;
	}
}
void List::UpperCase(unsigned int index)
{
	ListItem* tmp = _head;
	for (size_t i = 0; i < index; i++)
		tmp = tmp->next;
	for (size_t i = index; i <= _size; i++)
	{
		if (tmp->value >= 97 && tmp->value <= 122)
			tmp->value = (tmp->value - 32);
		tmp = tmp->next;
	}
}
void List::Print() const
{
	ListItem* cursor = _head;
	while (cursor != nullptr)
	{
		std::cout << cursor->value;
		cursor = cursor->next;
	}
	std::cout << std::endl;
}
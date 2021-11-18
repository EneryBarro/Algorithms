

#include "vector.h"
void MVector::Clear()
{
	if (_str)
	{
		delete[] _str;
		_size = 0;
		_str = nullptr;
	}
}
void MVector::Copy(const MVector& sourceStr)
{
	_str = new char[sourceStr._size + 1];
	for (size_t i = 0; i < sourceStr._size; i++)
	{
		_str[i] = sourceStr._str[i];
	}
	_str[sourceStr._size] = '\0';
	_size = sourceStr._size;
}
void MVector::Move(MVector& sourceStr)
{
	_str = sourceStr._str;
	_size = sourceStr._size;
	sourceStr._str = nullptr;
	sourceStr._size = 0;
}
MVector::MVector(const char* str)
{
	Assign(str);
}
MVector::~MVector()
{
	Clear();
}
MVector::MVector(const MVector& sourceStr)
{
	Copy(sourceStr);
}
MVector& MVector::operator=(const MVector& sourceStr)
{
	if (this == &sourceStr)
		return *this;
	Clear();
	Copy(sourceStr);
	return *this;
}
MVector& MVector::operator=(const char* sourceCStr)
{
	Assign(sourceCStr);
	return *this;
}
MVector::MVector(MVector&& sourceStr)
{
	Move(sourceStr);
}
MVector& MVector::operator=(MVector&& sourceStr)
{
	if (this == &sourceStr)
		return *this;
	Clear();
	Move(sourceStr);
	return *this;
}
void MVector::Assign(const char* str)
{
	size_t new_size = strnlen_s(str, BUF_MAXLEN);
	if (new_size == 0)
		return;
	char* tmp = new char[new_size + 1]; // + '\0'
	if (!tmp)
	{
		std::cout << "Could not allocate memory" << std::endl;
		return;
	}
	for (size_t i = 0; i < new_size; i++)
	{
		tmp[i] = str[i];
	}
	tmp[new_size] = '\0';
	delete[] _str;
	_str = tmp;
	_size = new_size;
}
void MVector::UpperCase(unsigned int index)
{
	for (size_t i = index; i < _size; i++)
	{
		if (_str[i] >= 97 && _str[i] <= 122)
			_str[i] = (_str[i] - 32);
	}
}
const char* MVector::getString()
{
	return _str ? _str : ""/*nullptr*/;
}
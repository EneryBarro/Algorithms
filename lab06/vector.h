#pragma once

#include <iostream>
#define BUF_MAXLEN 255
class MVector
{
private:
	char* _str = nullptr;
	size_t _size = 0;
	void Copy(const MVector& sourceStr);
	void Move(MVector& sourceStr);
public:
	MVector() = default;
	MVector(const char* str);
	~MVector();
	MVector(const MVector& sourceStr);
	MVector& operator=(const MVector& sourceStr);
	MVector& operator=(const char* sourceCStr);
	MVector(MVector&& sourceStr);
	MVector& operator=(MVector&& sourceStr);
	void Assign(const char* str);
	void UpperCase(unsigned int index);
	const char* getString();
	void Clear();
};

#pragma once
#include <iostream>

class LengthException
{
};

class IndexException
{
};

class Oversize
{
};

class BiggerOrEqual
{
};

class IntArray
{
private:
	int m_length;
	int* m_data;
public:
	IntArray() = default;

	IntArray(int length);

	IntArray(const IntArray& other);

	int getLength() const;

	int& operator[](int index);

	IntArray& operator=(const IntArray& obj);


	void reallocate(int newLength);

	void resize(int newLength);

	void erase();

	void insertBefore(int value, int index);

	void remove(int index);

	void insertAtBegonning(int value);

	void insertAtEnd(int valur);
};


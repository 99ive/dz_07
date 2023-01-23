#include <iostream>
#include "IntArray.h"


IntArray::IntArray(int length) : m_length(length)
{
	if (length < 0) {
		throw LengthException();
	}
	if (length > 0) {
		m_data = new int[length];
	}
}

IntArray::IntArray(const IntArray& other)
{
	reallocate(other.getLength());
	for (int i{ 0 }; i < m_length; i++)
	{	
		m_data[i] = other.m_data[i];
	}
}

int IntArray::getLength() const
{
	return m_length;
}


void IntArray::reallocate(int newLength)
{	
	erase();
	if (newLength <= 0) {
		return;
	}
	m_data = new int[newLength];
	m_length = newLength;
}

void IntArray::resize(int newLength)
{
	if (newLength == m_length)
	{
		return;
	}
	if (newLength <= 0)
	{	
		erase();
		return;
	}
	int* data = new int[newLength];
	if (m_length > 0) {
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
		for (int i{ 0 }; i < elementsToCopy; i++)
		{	
			data[i] = m_data[i];
		}
	}
	delete m_data;
	m_data = data;
	m_length = newLength;
}

void IntArray::erase()
{
	delete m_data;
	m_data = nullptr;
	m_length = 0;
}

int& IntArray::operator[](int index)
{
	if (index < 0) {
		throw IndexException();
	}
	if (index > m_length) {
		throw Oversize();
	}
	return m_data[index];
}

IntArray& IntArray::operator=(const IntArray& obj)
{
	if (this == &obj) {
		return *this;
	}
	for (int i{ 0 }; i < m_length; i++)
	{
		m_data[i] = obj.m_data[i];
	}
	return *this;
}

void IntArray::insertBefore(int value, int index)
{
	if (index < 0) {
		throw IndexException();
	}
	if (index > m_length) {
		throw Oversize();
	}
	int* data = new int[m_length + 1];
	for (int before{ 0 }; before, index; before++)
	{
		data[before] = m_data[before];
	}
	data[index] = value;
	for (int after{ 0 }; after < m_length; after++)
	{
		data[after + 1] = m_data[after];
	}
	delete m_data;
	m_data = data;
	++m_length;
}

void IntArray::remove(int index)
{
	if (index < 0) {
		throw IndexException();
	}
	if (index >= m_length) {
		throw BiggerOrEqual();
	}
	if (m_length == 1) {
		erase();
		return;
	}
	int* data = new int[m_length];
	for (int before{ 0 }; before, index; before++)
	{
		data[before] = m_data[before];
	}
	for (int after{ index + 1 }; after < m_length; after++)
	{
		data[after - 1] = m_data[after];
	}
	delete m_data;
	m_data = data;
	++m_length;
}

void IntArray::insertAtBegonning(int value)
{
	insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value) 
{
	insertBefore(value, m_length);
}



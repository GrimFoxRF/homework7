#include <iostream>
#include <exception>
#include "Func.h"

using namespace std;

const char* bad_range::what() const noexcept
{
	return "ОШИБКА: Выход за пределы массива!";
}
const char* bad_length::what() const noexcept
{
	return "ОШИБКА: Неправильная длина массива!";
}

IntegerArray::IntegerArray(int length)
{
	this->_length = length;
	if (length < 0)
	{
		throw bad_length();
	}
	_data = new int[length];
}

int& IntegerArray::operator[](int index)
{
	if (index < 0 || index >= _length)
	{
		throw bad_range();
	}
	return _data[index];
}

int IntegerArray::getElement(int index) const
{
	if (index < 0 || index >= _length) {
		throw bad_range();
	}
	return _data[index];
}

int IntegerArray::getSize() const
{
	return _length;
}

void IntegerArray::erase()
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
}

void IntegerArray::reallocate(int newLength)
{
	if (newLength < 0)
	{
		erase();
		throw bad_length();
	}

	_data = new int[newLength];
	_length = newLength;
}

void IntegerArray::resize(int newLength)
{
	if (newLength == _length)
		return;

	if (newLength < 0)
	{
		erase();
		throw bad_length();
	}

	int* data = new int[newLength];

	int elementsToCopy{ (newLength > _length) ? _length : newLength };

	for (int i = 0; i < elementsToCopy; ++i)
		data[i] = _data[i];
	for (int i = elementsToCopy; i < newLength; ++i)
		data[i] = i + 1;

	delete[] _data;

	_data = data;
	_length = newLength;
}

IntegerArray::IntegerArray(const IntegerArray& a)
{
	reallocate(a.getSize());

	for (int i = 0; i < _length; ++i)
		_data[i] = a._data[i];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a)
{
	if (&a == this)
		return *this;

	reallocate(a.getSize());

	for (int i = 0; i < _length; ++i)
		_data[i] = a._data[i];

	return *this;
}

void IntegerArray::insertBefore(int value, int i)
{
	if (i<0 || i>_length)
	{
		throw bad_range();
	}

	int* data = new int[_length + 1];

	for (int before = 0; before < i; ++before)
		data[before] = _data[before];

	data[i] = value;

	for (int after = i; after < _length; ++after)
		data[after + 1] = _data[after];

	delete[] _data;
	_data = data;
	++_length;
}

void IntegerArray::remove(int i)
{
	if (i < 0 || i >= _length)
	{
		throw bad_range();
	}
	if (_length == 1)
	{
		erase();
		return;
	}

	int* data{ new int[_length - 1] };

	for (int before = 0; before < i; ++before)
		data[before] = _data[before];

	for (int after = (i + 1); after < _length; ++after)
		data[after - 1] = _data[after];

	delete[] _data;
	_data = data;
	--_length;
}

void IntegerArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}

void IntegerArray::insertAtEnd(int value)
{
	insertBefore(value, _length);
}



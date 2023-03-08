#pragma once
#include <iostream>
#include <exception>

using namespace std;

class bad_range : public exception //Выход за пределы массива
{
public:
	const char* what() const noexcept override;
};
class bad_length : public exception //Неправильная длина массива
{
public:
	const char* what() const noexcept override;
};

class IntegerArray 
{
	int _length;
	int* _data;
public:
	IntegerArray(int length);

	~IntegerArray() 
	{
		delete[] _data;
	}
	int& operator[](int index);
	int getElement(int index) const; //Получение значения элемента по индексу
	int getSize() const; //Получение размера массива
	void erase(); //Очистка массива

	void reallocate(int newLength);
    void resize(int newLength);
   
	IntegerArray(const IntegerArray& a);
	IntegerArray& operator=(const IntegerArray& a);

    void insertBefore(int value, int index); //Вставка значения перд указанным индексом
    void remove(int index); //Удаление элемента массива
	void insertAtBeginning(int value); //Вставка элемента в начало массива
	void insertAtEnd(int value); //Вставка элемента в конец массива
};

#pragma once
#include <iostream>
#include <exception>

using namespace std;

class bad_range : public exception //����� �� ������� �������
{
public:
	const char* what() const noexcept override;
};
class bad_length : public exception //������������ ����� �������
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
	int getElement(int index) const; //��������� �������� �������� �� �������
	int getSize() const; //��������� ������� �������
	void erase(); //������� �������

	void reallocate(int newLength);
    void resize(int newLength);
   
	IntegerArray(const IntegerArray& a);
	IntegerArray& operator=(const IntegerArray& a);

    void insertBefore(int value, int index); //������� �������� ���� ��������� ��������
    void remove(int index); //�������� �������� �������
	void insertAtBeginning(int value); //������� �������� � ������ �������
	void insertAtEnd(int value); //������� �������� � ����� �������
};

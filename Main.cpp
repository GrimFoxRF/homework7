// �������� ������� � ������ 7 - �������� �.�.
#include <iostream>
#include <exception>
#include "Func.h"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

    int newL;
    int a;
    int indexA;
    int del;
    int ab;
    int ae;
    int q;
    int x;
    int index=-1;
    
    IntegerArray array(10);
    cout << "������� ������ �� 10 ���������:\n" << endl;
    for (int i = 0; i < 10; ++i)
        array[i] = i + 1;

    for (int i = 0; i < array.getSize(); ++i)
        cout << array[i] << " ";

    cout << "\n"<<endl;

	try 
	{
        cout << "������� ����� ������ ����������: " << endl;
        cin >> newL;
        array.resize(newL); //��������� ������ �������

        cout << "������� ����� ��� ������� � ��������� � ������: " << endl;
        cin >> a;
        cin >> indexA;
        array.insertBefore(a, indexA); //������� �������� ����� ������
        
        cout << "������� ������� ��� �������: " << endl;
        cin >> del;
        array.remove(del); //�������� �������� �������

        cout << "������� ����� ��� ������� � ������ � ����� ��� ������� � ����� ����������: " << endl;
        cin >> ab;
        cin >> ae;
        array.insertAtBeginning(ab); //��������� �������� � ������
        array.insertAtEnd(ae); //���������� �������� � ����� �������

        {
            IntegerArray b = array; //����������� �������
            b = array;
            b = b;
            array = array;
        }

        cout << "���������� ������: \n" << endl;
        for (int i = 0; i < array.getSize(); ++i)
            cout << array[i] << " ";

        cout << '\n';
        cout << "\n������ ������� :" << array.getSize() << endl;
        cout << "\n������� �������� ��� ������ � �������: " << endl;
        cin >> x;
        cin.clear();
        for (int i = 0; i < array.getSize(); i++)
        {
            if (array.getElement(i) == x)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "\n�������� ��� � �������"<<"\n" << endl;
        }
        else
        {
            cout << "\n�������� ������� ��� ��������: " << index<<"\n" << endl;
        }

        cout << "������� ����� �������� ������� ����� ������ ��� ��������: " << endl;
        cin >> q;
        cin.clear();

        cout<<"\n������� "<<q<< " - ��� "<<array.getElement(q)<<endl;
	}
    catch(const exception& e)
	{
		cerr << "\n"<<e.what() << endl;
		return 0;
	}
    catch (...) 
    {
        cerr << "����������� ������" << endl;
    }
	return 0;
}
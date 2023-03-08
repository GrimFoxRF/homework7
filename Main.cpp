// Домашнее задание к модулю 7 - Данченко М.В.
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
    cout << "Базовый массив из 10 элементов:\n" << endl;
    for (int i = 0; i < 10; ++i)
        array[i] = i + 1;

    for (int i = 0; i < array.getSize(); ++i)
        cout << array[i] << " ";

    cout << "\n"<<endl;

	try 
	{
        cout << "Введите новый размер контейнера: " << endl;
        cin >> newL;
        array.resize(newL); //Изменение длинны массива

        cout << "Введите число для вставки в контейнер и индекс: " << endl;
        cin >> a;
        cin >> indexA;
        array.insertBefore(a, indexA); //Вставка элемента перед другим
        
        cout << "Удалите элемент под номером: " << endl;
        cin >> del;
        array.remove(del); //Удаление элемента массива

        cout << "Введите число для вставки в начало и число для вставки в конец контейнера: " << endl;
        cin >> ab;
        cin >> ae;
        array.insertAtBeginning(ab); //Добавлене элемента в начало
        array.insertAtEnd(ae); //Добавление элемента в конец массива

        {
            IntegerArray b = array; //Копирование массива
            b = array;
            b = b;
            array = array;
        }

        cout << "Измененный массив: \n" << endl;
        for (int i = 0; i < array.getSize(); ++i)
            cout << array[i] << " ";

        cout << '\n';
        cout << "\nРазмер массива :" << array.getSize() << endl;
        cout << "\nВведите значение для поиска в массиве: " << endl;
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
            cout << "\nЗначения нет в массиве"<<"\n" << endl;
        }
        else
        {
            cout << "\nЗначение найдено под индексом: " << index<<"\n" << endl;
        }

        cout << "Введите номер элемента массива чтобы узнать его значение: " << endl;
        cin >> q;
        cin.clear();

        cout<<"\nЭлемент "<<q<< " - это "<<array.getElement(q)<<endl;
	}
    catch(const exception& e)
	{
		cerr << "\n"<<e.what() << endl;
		return 0;
	}
    catch (...) 
    {
        cerr << "Неизвестная ОШИБКА" << endl;
    }
	return 0;
}
#include "Hash_Twin_Chain.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <time.h>

using namespace std;

struct AAA
{
	int key;
	const char* mas;
	AAA(int k, const char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = NULL;
	}
};
//-------------------------------
int hf(void* d)                                                                         //Функция создания указателя как информационного элемента списка
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << "  ";
}
//-------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");                                                            //Установление кодировки
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int current_size = 0;                                                                //Переменная, определяющая размер таблицы                                                    
	cout << "Введите размер хеш-таблицы: ";                             //Сообщение о вводе размера таблицы
	cin >> current_size;                                                                 //Ввод пользователем размера таблицы
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)																			//Меню
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA;                                            //Создание нового элемента списка. Список - элемент таблицы
			char* str = new char[100];                                              //Создание новой строки как данных, хранящихся в поле элемента списка
			cout << "Введите номер школы(начало c 0): ";
			cin >> k;
			k = k;//Ввод ключа, хранящегося в поле элемента списка
			a->key = k;                                                            //Присваивание полю "ключ" списка вводимый ключ
			cout << "Введите фамилию директора: ";
			cin.ignore();
			cin.getline(str, 100);
			a->mas = str;                                                          //Присваивание полю "строка" списка вводимую строку
			H.insert(a);                                                           //Вставка элемента в объкт-таблицу
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "Введите номер школы: ";
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "Введите номер школы: ";
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else
			{
				cout << "Первый элемент с данным номером школы: ";
				AAA_print(H.search(c));
				cout << endl;
			}
		}
			  break;
		break;
		}
	}
	return 0;
}

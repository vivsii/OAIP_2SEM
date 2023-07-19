#include <iostream>
#include <fstream>
#include <string>

struct Stack
{
	int data;             
	Stack* head;		 
	Stack* next;		 
};

struct Stack1
{
	char letter;
	Stack1* head;
	Stack1* next;
};

struct Stack2
{
	int data;             
	Stack2* head;		 
	Stack2* next;		 
};

void show(Stack* myStk);
int pop(Stack* myStk);
void push(int x, Stack* myStk);
void clear(Stack* myStk);
void del2(Stack*& head);
int ifile(Stack* myStk);
void ofile(Stack* myStk);

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;

	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	

	Stack1* myStk1 = new Stack1; //выделение памяти для стека
	myStk1->head = NULL;

	Stack2* myStk2 = new Stack2; //выделение памяти для стека
	myStk2->head = NULL;

	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Очистка стека" << endl;
		cout << "5 - Удаление первого положительного элемента" << endl;
		cout << "6 - Запись в файл" << endl;
		cout << "7 - Чтение из файла" << endl;
		cout << "8 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: clear(myStk);
			break;
		case 5: del2(myStk);
			break;
		case 6: ofile(myStk);
			break;
		case 7: ifile(myStk);
			break;
		case 8: return 0;
			break;
		}
	}
	return 0;
}

void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}
int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void clear(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст\n";
	}

	else
	{
		while (myStk->head != NULL)
		{
			Stack* e = myStk->head;
			int a = myStk->head->data;
			myStk->head = myStk->head->next;
			delete e;

		}
		cout << "Стек очищен" << endl;
	}

}

Stack* findPos(Stack* myStk)
{
	Stack* temp = myStk->head;
	while (temp != NULL)
	{
		if (temp->next != nullptr) //проверка что следующий элемент существует
			if (temp->next->data > 0) //смотрим чтобы он был был больше нуля
				return temp; //и возвращаем элемент ЗА следующим, который является положительным
		temp = temp->next; //иначе идём далее
	}
	return NULL; //если ничего не нашли, возвращаем NULL
}

void del2(Stack*& myStk)
{
	Stack* prev;

	prev = findPos(myStk); //вызов функции что выше
	if (prev != NULL)//если мы нашли, то следующий элемент положительный
	{
		Stack* deleting = prev->next; //временно сохраняем его
		prev->next = prev->next->next; //перенастраиваем связи, если нужно подробно объяснить, то скажи
		cout << "Было удалено: " << deleting->data; //выводим элемент что удаляем
		cout << '\n';
		delete deleting; //возвращаем им занятую память


	}
	else
		cout << "Нет положительных элементов\n";
}

int ifile(Stack* myStk)
{
	ifstream file1("data.txt");
	Stack* e = myStk->head;
	int value;
	file1 >> value;
	if (file1.eof())
	{
		file1.close();
		return -1;
	}
	Stack* Stkfile = new Stack;
	Stkfile->data = value;
	myStk->head = Stkfile;
	while (true)
	{
		file1 >> value;
		if (file1.eof())
		{
			break;
		}
		Stkfile->next = new Stack;
		Stkfile = Stkfile->next;
		Stkfile->data = value;
	}
	Stkfile->next = NULL;
	file1.close();
}

void ofile(Stack* myStk)
{
	ofstream file1("data.txt");
	Stack* temp = myStk->head;
	if (file1.fail())           // если файл не открыт
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)        // пока элемент списка не равен NULL
	{
		int nn = temp->data;      // переменная для записи
		file1 << nn << " ";        // записываем
		temp = temp->next;          // переходим на следующий
	}
	file1.close();
	cout << "Стек записан в файл data.txt\n";
}

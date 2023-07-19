#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <string>
const char FOUND1[] = "0123456789-";


using namespace std;
struct Tree
{
	int key;
	char text[256] = {};
	Tree* Right, * Left;
};

unsigned int getLeafCount(Tree* node)
{
	if (node == NULL)
		return 0;
	if (node->Left == NULL && node->Right == NULL)
		return 1;
	else
		return getLeafCount(node->Left) +
		getLeafCount(node->Right);
}

int sumary(Tree* t)
{
	if (t == 0) return 0;
	return t->key + sumary(t->Left) + sumary(t->Right);
}
void print2(Tree* t, int u)    //Вывод на экран
{
	if (t == NULL)  return;
	else
	{
		print2(t->Right, ++u);     //левое поддерево
		for (int i = 0; i < u; i++)
		{
			cout << '\t';
		}
		for (int i = 0; i < u; i++)
		{
			cout << '|';
		}
		cout << t->key << endl;
		u--;
	}
	print2(t->Left, ++u);          // правое поддерево
}

int cpp = 0;
void var2(Tree* t, int u)    //Вывод на экран
{
	if (t == NULL)  return;
	else
	{
		var2(t->Right, ++u);     //левое поддерево
		if (t->Right)
		{
			if (t->Right->Left == nullptr && t->Right->Right == nullptr)
				cpp++;
		}

		var2(t->Left, ++u);
	}
}

int countK = 0, c_b = 0;
int CountTopK(Tree* t);
Tree* makeTree(Tree* Root);
Tree* list(int i, char* s);
Tree* insertElem(Tree* Root, int key, char* s);
Tree* search(Tree* n, int key);
Tree* delet(Tree* Root, int key);
void delAll(Tree* t);

int c = 0;
Tree* Root = NULL;

void main()
{
	system("chcp 1251");
	int key, choice, n;
	Tree* rc;
	char s[256] = {}, letter;
	string str1, str2;
	int u = 0;

	for (;;)
	{
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по ключу\n";
		cout << "4 -	удаление элемента\n";
		cout << "5 -	вывод дерева\n";
		cout << "6 -	очистка дерева\n";
		cout << "7 -	выход\n";

		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);
			break;
		case 2:
			do
			{
				cout << "Введите значение ключа: ";
				cin >> str1;
			} while (str1.find_first_not_of(FOUND1) != string::npos);
			key = stoi(str1);


			cout << "Введите строку: ";
			cin.ignore();
			getline(cin, str2);

			for (int i = 0; i < str2.length(); i++)
			{
				s[i] = str2[i];

			}
			insertElem(Root, key, s);
			break;
		case 3:
			do
			{
				cout << "Введите значение ключа: ";
				cin >> str1;
			} while (str1.find_first_not_of(FOUND1) != string::npos);
			key = stoi(str1);
			rc = search(Root, key);

			if (rc)
			{
				cout << "Найденная строка= ";
				puts(rc->text);
			}
			break;
		case 4:
			do
			{
				cout << "Введите значение ключа: ";
				cin >> str1;
			} while (str1.find_first_not_of(FOUND1) != string::npos);
			key = stoi(str1);
			Root = delet(Root, key);
			break;
		case 5:  if (Root->key >= 0)
		{
			print2(Root, u);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6:  delAll(Root); break;
		case 7: exit(0);
		}
	}

}

Tree* makeTree(Tree* Root)
{
	string str1, str2;

	int key; char s[256] = {};
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		do
		{
			cout << "Введите значение ключа: ";
			cin >> str1;
		} while (str1.find_first_not_of(FOUND1) != string::npos);
		key = stoi(str1);


		cout << "Введите строку: ";
		cin.ignore();
		getline(cin, str2);


		for (int i = 0; i < str2.length(); i++)
		{
			s[i] = str2[i];

		}
		Root = list(key, s);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		do
		{
			cout << "Введите значение ключа: ";
			cin >> str1;
		} while (str1.find_first_not_of(FOUND1) != string::npos);
		key = stoi(str1);
		if (key < 0)
			break;
		if (key > 0)
		{
			cout << "Введите строку: ";
			cin.ignore();
			getline(cin, str2);

			for (int i = 0; i < str2.length(); i++)
			{
				s[i] = str2[i];

			}
			insertElem(Root, key, s);
		}
	}
	return Root;
}


Tree* list(int i, char* s)
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < strlen(s); i++)
		*((t->text) + i) = *(s + i);
	t->Right = t->Left = NULL;
	return t;
}


Tree* insertElem(Tree* t, int key, char* s)  //Добавление нового элемента
{
	Tree* Prev = NULL;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
		{
			find = 1;	   //ключи должны быть уникальны
			cout << "Дублирование ключа" << endl;
			cout << "Повторите ввод" << endl;
		}
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key, s);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Right);
		delAll(t->Left);
		delete t;
	}
}


int CountTopK(Tree* Root)
{

	if (Root == NULL) return 0;
	if (Root->key % 2 == 0)
	{
		countK++;
	}
	return 1 + CountTopK(Root->Right) + CountTopK(Root->Left);
}

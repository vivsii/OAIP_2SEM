#include "Tree.h"
int countK = 0;
int CountTopK(tNode* Root)
{

	if (Root == NULL) return 0;
	if (Root->data % 2 == 0)
	{
		countK++;
	}
	return 1 + CountTopK(Root->right) + CountTopK(Root->left);
}




int main()
{
	// 13 8 17 4 11 15 25 2 6 22 27 20 33 

	system("chcp 1251");
	tNode* tree = nullptr;
	int choice;
	cout << " ____________________Меню____________________" << endl;
	cout << "/1  - для добавления элемента;\n";
	cout << "|2  - для удаления элемента;	\n";
	cout << "|3  - для вывода дерева;\n";
	cout << "|4  - для очистки дерева;\n";
	cout << "|5 - для прямого(нисходящего) обхода;\n";
	cout << "|6 - для симметричного обхода;\n";
	cout << "|7 - для обратного(смешанного) обхода;\n";
	cout << "|8 - для проверки сбалансированности дерева;\n";
	cout << "|0 - для выхода:\n";
	cout << "\\___________________________________________/" << endl;

	do {
		do
		{
			cout << "Ваш выбор: ";
			choice = Correct_Input_Integer();
		} while (choice > 10);

		switch (choice) {
		case 1:
		{
			int x;
			cout << "Введите число: "; x = Correct_Input_Integer();
			if (search(x, tree) != NULL)
			{
				cout << "Дублирование ключа" << endl;
				break;

			}
			tree = input(tree, x);
			break;
		}
		case 2: {
			int x;
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Введите число: "; x = Correct_Input_Integer();
			tree = del(tree, x);
			break;
		}
		case 3:
		{
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Вывод:" << endl;
			print(tree, 0);
			break;
		}
		case 4: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Очистка..." << endl;
			tClear(tree);
			tree = nullptr;
			break;
		}
		case 5: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Прямой обход:" << endl;
			Directbypass(tree);
			break;
		}
		case 6: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Симметричный обход:" << endl;
			Symmetricbypass(tree);
			break;
		}
		case 7: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Обратный обход:" << endl;
			Reversebypass(tree);
			break;
		}
		case 8: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			if (AVL(tree)) cout << "Дерево сбалансированное" << endl;
			else cout << "Дерево не сбалансированное" << endl;
			break;
		}

		}
		if (choice) cout << "\nЧего желаете? --> ";
	} while (choice);
}


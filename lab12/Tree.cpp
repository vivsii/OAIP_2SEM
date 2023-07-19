#include "Tree.h"
void print(tNode* t, int u) {
	if (t == NULL)
		return;
	else {
		print(t->right, ++u);     //левое поддерево
		for (int i = 0; i < u; i++)
			cout << '\t';
		for (int i = 0; i < u; i++)
			cout << '|';
		cout << t->data << endl;
		u--;
	}
	print(t->left, ++u);
}
tNode* input(tNode* tree, int x) {
	if (!tree) {
		tree = new tNode;
		tree->data = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (x < tree->data) {
		tree->left = input(tree->left, x);
	}
	else {
		tree->right = input(tree->right, x);
	}
	return(tree);
}
tNode* search(int key, tNode* leaf) { //(Ключевое значение, указатель ну узел)
	if (leaf != NULL) { //Если узел //инициализирован
		if (key == leaf->data)	//И ключевое значение узла совпадает с искомым ключевым значением.
			return leaf;	//Возвращается указатель на найденный элемент.
		if (key < leaf->data)	//Иначе, если искомое ключевое значение меньше ключевого значения узла
			return search(key, leaf->left);	//Вызывается эта же функция для левого потомка.
		else							//Иначе
			return search(key, leaf->right);	//Вызывается эта же функция для правого потомка.
	}
	else return NULL;					//Иначе возвращается NULL.
}
int check(tNode* tree, int x) {
	int find = 0;        // признак поиска
	while (tree->left != NULL || tree->left != NULL) {
		if (x == tree->data)
			find = 1;	   //ключи должны быть уникальны
	}
	return find;
}
tNode* del(tNode* tree, int x) {
	tNode* Del, * Prev_del, * R, * Prev_r;
	Del = tree;
	Prev_del = NULL;
	while (Del && Del->data != x) {
		Prev_del = Del;
		if (Del->data > x)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (!Del) {
		cout << "Элемент не найден!" << endl;
		return tree;
	}
	if (!Del->right)
		R = Del->left;
	else if (!Del->left)
		R = Del->right;
	else {
		Prev_r = Del;
		R = Del->left;
		while (R->right) {
			Prev_r = R;
			R = R->right;
		}
		if (Prev_r == Del)
			R->right = Del->right;
		else {
			R->right = Del->right;
			Prev_r->right = R->left;
			R->left = Prev_r;
		}
	}
	if (Del == tree)
		tree = R;
	else if (Del->data < Prev_del->data)
		Prev_del->left = R;
	else
		Prev_del->right = R;
	cout << "Удален элемент с ключом: " << Del->data << endl;
	delete Del;
	return tree;
}
void tClear(tNode* tree) {
	if (tree) {
		tClear(tree->left);
		tClear(tree->right);
		delete tree;
	}
}
void Directbypass(tNode* tree) {
	if (tree) {
		cout << tree->data << " ";
		Directbypass(tree->left);
		Directbypass(tree->right);
	}
}
void Symmetricbypass(tNode* tree) {
	if (tree) {
		Symmetricbypass(tree->left);
		cout << tree->data << " ";
		Symmetricbypass(tree->right);
	}
}
void Reversebypass(tNode* tree) {
	if (tree) {
		Reversebypass(tree->left);
		Reversebypass(tree->right);
		cout << tree->data << " ";
	}
}
int maxi(int x, int y) {
	return (x >= y) ? x : y;
}

int height(tNode* node) {
	if (node == NULL) return 0;
	return 1 + maxi(height(node->left), height(node->right));
}
int AVL(tNode* root) {
	if (root == NULL)
		return 1;
	int lh = height(root->left);
	int rh = height(root->right);
	if (abs(lh - rh) <= 1 && AVL(root->left) && AVL(root->right)) return 1;
	return 0;
}
//Корректный ввод integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[20];

	while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
	{ //Если proverka_2 = 1, значит ввод неверный.
		cin.ignore(cin.rdbuf()->in_avail());
		proverka_2 = 0;
		gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
			for (int i = 1; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
					break;
				}
		if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
			for (int i = 0; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
					break;
				}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}

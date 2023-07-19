#include <iostream>
#include <string>
using namespace std;

/*
Ученики. Ф.И.О., класс (цифра+буква), оценки, средний балл. Выбор по
фамилии. Класс реализовать с помощью битового поля, предметы через перечисление.
*/

const int SIZE = 30;
int current_size = 0;

enum Sublects {
	math = 1,
	physics,
	literature,
	english,
	kpo,
	oaip
};

struct Klass {
	unsigned num : 4;
	char letter;
};

struct Pupils {
	string surname;
	string name;
	string middlename;
	Klass klass;
	int marks[7];
	float average;
} pupils[SIZE];
struct Pupils empty_pupil;

void addNew();
void displayOneStructure(Pupils onePupil);
void display();
void deleteRecord();
void search();

void main()
{
	setlocale(LC_ALL, "ru");
	short choose;
	do
	{
		cout << "Введите:\n1 - ввести новую запись;\n2 - вывод информации;\n3 - удалить запись;\n4 - поиск\n5 - выход.\n";
		cin >> choose;
		switch (choose) {
		case 1: addNew(); break;
		case 2: display(); break;
		case 3: deleteRecord(); break;
		case 4: search(); break;
		}
	} while (choose != 5);

}

void addNew() {
	cout << "Ввод информации" << endl;
	cout << "Номер записи " << current_size + 1 << endl;

	if (current_size < SIZE) {
		cout << "Фамилия: ";
		cin >> pupils[current_size].surname;

		cout << "Имя: ";
		cin >> pupils[current_size].name;

		cout << "Отчество: ";
		cin >> pupils[current_size].middlename;

		cout << "класс (номер): ";
		int klass_num;
		cin >> klass_num;
		if (klass_num < 1 or klass_num > 11) {
			cout << "Неправильный ввод" << endl;
			cin >> klass_num;
		}
		pupils[current_size].klass.num = klass_num;

		cout << "класс (буква): ";
		cin >> pupils[current_size].klass.letter;

		cout << "Оценки(матем, физика, литература, английский, кпо, оаип): ";
		for (int i = 1; i < 7; i++) {
			cin >> pupils[current_size].marks[i];
		}
		pupils[current_size].average = (((float)pupils[current_size].marks[math] +
			(float)pupils[current_size].marks[physics] +
			(float)pupils[current_size].marks[literature] +
			(float)pupils[current_size].marks[english] +
			(float)pupils[current_size].marks[kpo] +
			(float)pupils[current_size].marks[oaip]) / 6);

		current_size++;
	}
	else
		cout << "никакие другие записи не могут быть введены" << endl;
}


void displayOneStructure(Pupils onePupil) {
	setlocale(LC_ALL, "ru");
	cout << endl;
	cout << "Фамилия: " << onePupil.surname << endl;
	cout << "Имя: " << onePupil.name << endl;
	cout << "Отчество: " << onePupil.middlename << endl;
	cout << "класс(номер): " << onePupil.klass.num << endl;
	cout << "класс(буква): " << onePupil.klass.letter << endl;
	cout << "Оценки:" << endl;
	cout << "Метам: " << onePupil.marks[math] << endl;
	cout << "Физика: " << onePupil.marks[physics] << endl;
	cout << "Литература: " << onePupil.marks[literature] << endl;
	cout << "Английский: " << onePupil.marks[english] << endl;
	cout << "КПО: " << onePupil.marks[kpo] << endl;
	cout << "ОАип: " << onePupil.marks[oaip] << endl;
	cout << "Средний балл: " << onePupil.average << endl;
}

void display() {
	int ch, num;
	cout << "1 - вывести одну запись" << endl;
	cout << "2 - вывести все записи" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Введите номер записи" << endl;
		cin >> num;
		if (num > current_size or num < 1)
			cout << "Неправильный ввод";
		cout << endl;
		displayOneStructure(pupils[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			displayOneStructure(pupils[i]);
			cout << endl;
		}
	}
	else
		cout << "Некорректный ввод";
}

void deleteRecord() {
	int rec_number;
	cout << "Введите номер записи для удаления" << endl;
	cin >> rec_number;
	if (rec_number != 0) {
		for (int de = (rec_number - 1); de < current_size - 1; de++)
			pupils[de] = pupils[de + 1];
		current_size -= 1;
	}
	if (rec_number == 0)
		for (int i = 0; i < SIZE; i++)
			pupils[i] = empty_pupil;
}

void search() {
	string nedded_surname;
	cout << "Введите фамилию для поиска: ";
	cin >> nedded_surname;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (pupils[i].surname == nedded_surname)
			displayOneStructure(pupils[i]);
	}
}

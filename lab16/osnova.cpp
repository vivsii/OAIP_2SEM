#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

void osnova()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int size, i, max = 0, index, j;
	int A[100], B[100];
	cout << "Ведите размер массива А: ";
	cin >> size;
	cout << "\nМассив А: | ";
	for (i = 0; i < size; i++)
	{
		A[i] = 1 + rand() % 20;
		cout << A[i] << " | ";
		if (A[i] > max)
		{
			max = A[i];
			index = i;
		}
	}
	cout << "\nМассив В: | ";
	if (size % 2 == 0)
	{
		if (index % 2 == 0)		
		{
			int kolvo = size - index + 1, sizeB = kolvo / 2, indexFirst = index + 1;
			for (j = 0; j < sizeB; j++)
			{
				B[j] = A[indexFirst];
				indexFirst += 2;
				cout << B[j] << " | ";
			}

			bubbleSort(B, sizeB);
			cout << "\n\nПузырьковая сортировка:\t  | ";
			for (i = 0; i < sizeB; i++)
				cout << B[i] << " | ";

			sortHoar(B, 0, sizeB);
			cout << "\nСортировка Хоара: | ";
			for (i = 0; i < sizeB; i++)
				cout << B[i] << " | ";
		}
		if (index % 2 != 0)
		{
			int kolvo = size - index, sizeB = kolvo / 2, indexFirst = index + 2;
			for (j = 0; j < sizeB; j++)
			{
				B[j] = A[indexFirst];
				indexFirst += 2;
				cout << B[j] << " | ";
			}

			bubbleSort(B, sizeB);
			cout << "\n\nПузырьковая сортировка:\t  | ";
			for (i = 0; i < sizeB; i++)
				cout << B[i] << " | ";

			sortHoar(B, 0, sizeB);
			cout << "\nСортировка Хоара: | ";
			for (i = 0; i < sizeB; i++)
				cout << B[i] << " | ";
		}
	}
	if (size % 2 != 0)
	{
		if (index % 2 == 0)
		{
			int kolvo = size - index, sizeB = kolvo / 2, indexFirst = index + 1;
			for (j = 0; j < sizeB; j++)
			{
				B[j] = A[indexFirst];
				indexFirst += 2;
				cout << B[j] << " | ";
			}

			bubbleSort(B, sizeB);
			cout << "\n\nПузырьковая сортировка:\t  | ";
			for (i = 0; i < sizeB; i++)
				cout << B[i] << " | ";

			sortHoar(B, 0, sizeB);
			cout << "\nСортировка Хоара: | ";
			for (i = 0; i < sizeB; i++)
				cout << B[i] << " | ";
		}
		if (index % 2 != 0)
		{
			int kolvo = size - index - 1, sizeB = kolvo / 2, indexFirst = index + 2;
			for (j = 0; j < sizeB; j++)
			{
				B[j] = A[indexFirst];
				indexFirst += 2;
				cout << B[j] << " | ";
			}

			bubbleSort(B, sizeB);
			cout << "\n\nПузырьковая сортировка:\t  | ";
			for (i = 0; i < sizeB; i++)
				cout << B[i] << " | ";

			sortHoar(B, 0, sizeB);
			cout << "\nСортировка Хоара: | ";
			for (i = 0; i < sizeB; i++)
				cout << B[i] << " | ";
		}
	}

	cout << '\n';
}


#include <iostream>
using namespace std;
int fmax(int n, ...);
double fmax(double n, ...);

void main()
{
	cout << fmax(5, 2, 3, 4, 5) << endl;
	cout << fmax(6, 3, 21, 56, 22, 7) << endl;
	cout << fmax(3.0, 1.7, -5.5) << endl;
	cout << fmax(4.0, 3.33, -1.44, -7.99) << endl;
}

int fmax(int n, ...)
{
	int* p = &n;
	int min = *p;
	int k = *p;
	for (int i = 0; i < k; i++)
	{
		if (min > *(p + i))
		{
			min = *(p + i);
		}
	}
	return min;
}

double fmax(double n, ...)
{
	double* p = &n;
	double min = *p;
	int k = *p;
	for (int i = 0; i < k; i++)
	{
		if (min > *(p + i))
		{
			min = *(p + i);
		}
	}
	return min;

}

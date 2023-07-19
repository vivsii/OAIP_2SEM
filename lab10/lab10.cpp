#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

// ============================ ВАРИАНТ 3 ============================

double square(int n, int i)
{
	if (i < n) return (sqrt(1 + (n + i) * square(n, i + 1)));
	else return sqrt(1 + (n + n));
}




// ============================ ВАРИАНТ 5 ============================

double factorial(int n)
{
	if (n < 0) return 0;
	if (n == 0 ) return 1;
	else return n * factorial(n - 1);
}


double cNM(int n, int m)
{
	return factorial(n) / (factorial(m) * factorial(n - m));
}


double cCount(int n, int m)
{
	if (m > n || m < 0 || n < 0) return 0;
	if (m == 0 || n == m) return 1;
	else return cNM(n - 1, m) + cNM(n - 1, m - 1);
}


// ============================  MAIN  ============================

int main()
{
	setlocale(LC_ALL, "russian");


	int i = 1, r, n, m;
	cout << "Введите n:";
	cin >> r;
	cout << "3 вар: " << square(r, i) << endl;

	cout << "Введите n:";
	cin >> n;
	cout << "Введите m:";
	cin >> m;
	cout << "5 вар: " << cCount(n, m) << endl;

}

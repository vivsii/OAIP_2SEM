#define _CRT_SECURE_NO_WARNINGS 
#include <string> 
#include <sstream> 
#include <fstream> 
#include <iostream>                     
# define str_len 30                                
# define size 30   
using namespace std;
void enter_new();
void del();
void output();
void input();
int find(int number);
void out();
struct BankAccoutnt
{
    string FIO;
    string type;
    int number;
    double amount;
    string date;
};
BankAccoutnt Accounts[size];
BankAccoutnt bad;
int current_size = 0; int choice;
int main()
{


    setlocale(LC_CTYPE, "Russian");
    cout << "Введите:" << endl;
    cout << "1-для удаления записи" << endl;
    cout << "2-для ввода новой записи" << endl;
    cout << "3-для вывода записи(ей)" << endl;
    cout << "4-Чтение из файла" << endl;
    cout << "5-Запись в файл" << endl;
    cout << "6-для выхода" << endl;
    cin >> choice;
    do
    {
        switch (choice)
        {
        case 1:  del(); break;
        case 2:  enter_new();  break;
        case 3:  out(); break;
        case 4: input(); break;
        case 5: output(); break;
        }
    } while (choice != 6);
}
void enter_new()
{
    cout << "Ввод информации" << endl;
    if (current_size < size)
    {
        cin.ignore(32767, '\n');
        cout << "Строка номер ";
        cout << current_size + 1;
        cout << endl << "Фамилия " << endl;

        getline(cin, Accounts[current_size].FIO);
        cout << "Номер счёта " << endl;

        cin >> Accounts[current_size].number;
        cin.ignore(32767, '\n');
        cout << "Тип счёта " << endl;
        getline(cin, Accounts[current_size].type);
        cout << "Сумма на счёте " << endl;
        cin >> Accounts[current_size].amount;
        cin.ignore(32767, '\n');
        cout << "Дата в формате дд.мм.гг " << endl;
        int day = 0, month = 0, year = 0;

        scanf("%d.%d.%d", &day, &month, &year);
        if ((day > 31 || day <= 0) || (month > 12 || month <= 0) || (year <= 0 || year > 2023))
        {
            cout << "Ошибка, начните ввод заново\n";
            enter_new();
            return;

        }

        Accounts[current_size].date = to_string(day) + '.' + to_string(month) + '.' + to_string(year);
        current_size++;
    }
    else
        cout << "Введено максимальное кол-во строк";
    cout << "Что дальше?" << endl;
    cin >> choice;
}
void del()
{
    int d;
    cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
    if (d != 99)
    {
        for (int de1 = (d - 1); de1 < current_size; de1++)
            Accounts[de1] = Accounts[de1 + 1];
        current_size = current_size - 1;
    }
    if (d == 99)
        for (int i = 0; i < size; i++)
            Accounts[i] = bad;
    cout << "Что дальше?" << endl;
    cin >> choice;
}
int find(int number)
{
    int i = 0;
    for (i; i < current_size && number != Accounts[i].number; i++)
    {

    }
    return i;
}
void out()
{
    int sw, n;
    cout << "1-вывод 1 строки" << endl;
    cout << "2-вывод всех строк" << endl;
    cin >> sw;
    if (sw == 1)
    {
        cout << "Введите номер счёта " << endl;   cin >> n; int f = find(n);
        cout << "Фамилия ";
        cout << Accounts[f].FIO << endl;
        cout << "Номер счёта " << endl;
        cout << Accounts[f].number << endl;
        cout << "Тип счёта ";
        cout << Accounts[f].type << endl;
        cout << "Сумма ";
        cout << Accounts[f].amount << endl;
        cout << "Дата" << endl;
        cout << Accounts[f].date << endl;
    }
    if (sw == 2)
    {
        for (int i = 0; i < current_size; i++)
        {
            cout << "Фамилия ";
            cout << Accounts[i].FIO << endl;
            cout << "Номер счёта " << endl;
            cout << Accounts[i].number << endl;
            cout << "Тип счёта ";
            cout << Accounts[i].type << endl;
            cout << "Сумма ";
            cout << Accounts[i].amount << endl;
            cout << "Дата" << endl;
            cout << Accounts[i].date << endl;
        }
    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}

void input()
{
    fstream in("input.txt");
    while (!in.eof())
    {

        string last, name, father;
        in >> last; in >> name; in >> father;
        Accounts[current_size].FIO = last + " " + name + " " + father;

        in >> Accounts[current_size].number;
        in >> Accounts[current_size].type;
        in >> Accounts[current_size].amount;
        in >> Accounts[current_size].date;
        current_size++;




    }
    cout << "Что дальше?" << endl;
    cin >> choice;
}
void output()
{
    fstream out("output.txt");
    out.clear();
    for (int i = 0; i < current_size; i++)
    {
        out << Accounts[i].FIO;
        out << '\n';
        out << Accounts[i].number << " ";
        out << Accounts[i].type << " ";
        out << Accounts[i].amount << " ";
        out << Accounts[i].date << " ";
        out << "\n";
    }
    cin >> choice;
}

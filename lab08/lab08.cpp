#include<iostream> 
#define MYQUEUE1_EQE  0x0000  

using namespace std;

struct Number
{
    int info;
    Number* next;
};

void osnova();

void create(Number** begin, Number** end, int p);
void view(Number* begin);
void Delete(Number** begin);
short sizeQ(Number* begin);
void task(Number** begin); 
Number* maxNum(Number* begin);

void main()
{
    setlocale(LC_ALL, "ru");
    Number* begin = NULL, * end, * t;
    t = new Number;
    short size, choose = 0, p, sizeQueue;
    while (choose != 7)
    {
        cout << "Выберите, что сделать:\n1 — ввод очереди;\n2 — вывод очереди;\n3 — очистка очереди;\n4 — определение размера очереди;"
            "\n5 — найти максимальный элемент;\n6 — удалить 3 первых элемента и вывести размер оставшейся очереди;\n7 — выход из программы.\n\n";
        cin >> choose;
        cout << '\n';
        switch (choose)
        {
        case 1:
            cout << "Введите размер очереди:\n";
            cin >> size;
            cout << "Введите число: ";
            cin >> p;
            create(&begin, &end, p);
            t->info = p;
            t->next = NULL;
            begin = end = t;
            for (int i = 1; i < size; i++) //создание очереди
            {
                cout << "Введите число: ";
                cin >> p;
                create(&begin, &end, p);
            }
            cout << '\n';
            break;
        case 2:
            view(begin);
            break;
        case 3:
            Delete(&begin);
            break;
        case 4:
            sizeQueue = sizeQ(begin);
            break;
        case 5:
            maxNum(begin);
            break;
        case 6:
            task(&begin);
            sizeQ(begin);
            break;
        case 7:
            cout << "До свидания!\n"; exit(0);
        }
    }
}

void create(Number** begin, Number** end, int p)
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Number* begin) 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Очередь пуста\n";
        return;
    }
    else
        cout << "Размер:\n";
    while (t != NULL)
    {
        cout << t->info << endl;
        t = t->next;
    }
    cout << '\n';
}

void Delete(Number** begin)
{
    Number* t;
    t = new Number;
    if (*begin == NULL)
    {
        cout << "Очередь пуста" << endl;
    }
    while (*begin != NULL)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }

    cout << "Очередь очищена" << endl;
}


short sizeQ(Number* begin) 
{
    Number* t = begin;
    short counter = 0, data = t->info;
    while (t != NULL)
    {
        if (data != 0)
        {
            counter++;
            t = t->next;
        }
        else t = t->next;
    }
    cout << "Размер очереди составляет " << counter << " элемента.\n\n";
    return counter;
}

Number* maxNum(Number* begin) 
{
    Number* t = begin, * mx = NULL;
    int max;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        max = t->info;
        while (t != NULL)
        {
            if (t->info >= max)
            {
                max = t->info;
                mx = t;
            }
            t = t->next;
        }
    }
    cout << "Максимальный элемент в очереди: " << max << ".\n\n";
    return mx;
}

void task(Number** begin) 
{
    Number* t;
    t = new Number;
    if (*begin == NULL)
    {
        cout << "Очередь пуста" << endl;
    }
    for (short i = 0; i < 3; i++)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}


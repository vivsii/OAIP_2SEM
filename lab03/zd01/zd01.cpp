// Скопировать из файла FILE1 в файл FILE2 строки, начиная с к до к + 3. Подсчитать количество гласных букв в FILE2. 
#include <fstream> 
#include <string> 
#include <stdio.h> 
#include <iostream> 
#define LEN 256 
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int row1, row2;
    ifstream ifile("FILE1.txt");
    fstream ofile("FILE2.txt");
    cout << "k строки:\n";
    cin >> row1;
    row2 = row1 + 3;
    int sum = 0, count = 0;
    string str;

    if (ifile.peek() == EOF)
    {
        cout << "Nothing in file";
        exit(0);
    }
    for (int i = 0; i < row1; getline(ifile, str), i++); //Спукаемся в файле до строки под номером row1, котору. вводим ранее 

    for (row1; row1 <= row2; row1++, getline(ifile, str)) //Записывам в файл строки с row1 по row2 
    {


        ofile << str + '\n';

    }
    ofile.close();
    fstream read("FILE2.txt");
    while (!read.eof()) //Считаем гласные 
    {

        getline(read, str);
        for (int i = 0; i < str.length(); i++)
            if (str[i] == 'a'|| str[i] == 'e' || str[i] == 'y' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o')
                count++;
    }

    cout << "количество гласных: " << count;

    ifile.close();
    read.close();
}

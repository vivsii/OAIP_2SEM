#include <stdio.h>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "ru");
    int a;
    errno_t err, columns = 4;
    FILE* f;
    err = fopen_s(&f, "matrix.txt", "w"); 
    if (err != 0)
    {
        perror("Невозможно создать файл\n");  
        return EXIT_FAILURE;
    }
    double Matrix[16] = { 2.3,7.5,1.0,-4.3,
                     5.6,-4.3,1.0,3.4,
                     9.2,44.5,-2.4,8.2,
                     3.4,-5.1,6.3,-1.1 };
    fprintf(f, "%d столбца\n", columns);    
    for (int j = 0; j < 16; j += 4)
    {
        for (int i = j; i < j + 4; i++)
        {
            fprintf(f, "%.1f\t", Matrix[i]);  
        }
        fprintf(f, "\n");
    }
    err = fopen_s(&f, "matrixT.txt", "w"); 
    if (err != 0)
    {
        perror("Невозможно создать файл\n");    
        return EXIT_FAILURE;
    }
    fprintf(f, "%d столбца.\n", columns);   
    for (int j = 0; j < 4; j++)                     
    {
        for (int i = j; i <= j + 12; i += 4)
        {
            fprintf(f, "%.1f\t", Matrix[i]);  
        }
        fprintf(f, "\n");
    }
    fprintf(f, "\n");

    printf("Данные записаны в файл matrixT.txt\n");
    fclose(f);  
    return 0;
}

#include "header.h"


int main(int argc, char *argv[])
    {
    flag_checking(argc, argv);

    #ifdef DEBUG
    debug_solving();
    #endif

    #ifndef DEBUG

    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;
    int num_of_roots = 0;
    char ch = 'n';

    printf("Привет! Я могу решать квадратные уравнения!\n");
    printf("y. Решать!      n. Не надо(\n");

    while ((ch = getchar()) != 'n')
        {
        if (ch == 'y')
            {
            printf("Введите коэффициенты a, b и c квадратного уравнения:\n");
            a = import_koef();
            b = import_koef();
            c = import_koef();

            printf("%.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
            num_of_roots = solvingSq(a, b, c, &x1, &x2);

            output(num_of_roots, x1, x2);
            printf("Продолжаем?\n");
            printf("y. Решать!      n. Не надо(\n");
            }
        else
            printf("Можно вводить только n или y: ");

        while (getchar() != '\n')
                continue;
        }
    #endif

    return 0;
    }

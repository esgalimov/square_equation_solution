#include "header.h"

double import_koef(void)
    {
    double num = NAN;

    while (scanf("%lf", &num) != 1)
        {
        printf("Неверный ввод! Требуются числа с плавающей запятой!");
        while (getchar() != '\n')
            continue;
        }

    return num;
    }

int solvingSq(double a, double b, double c, double * x1, double * x2)
    {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);

    double d = NAN;

    if (is_equal(a, 0.0, EPSILON))
        return solvingLin(b, c, x1);
    else
        {
        d = b * b - 4 * a * c;
        if (is_equal(d, 0.0, EPSILON))
            {
            *x1 = -b / (2 * a);
            return ONEROOT;
            }
        else if (d < 0)
            return ZEROROOTS;
        else
            {
            *x1 = (-b + sqrt(d)) / (2 * a);
            *x2 = (-b - sqrt(d)) / (2 * a);
            return TWOROOTS;
            }
        }
    }

int solvingLin(double b, double c, double * x1)
    {

    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);

    if (is_equal(b, 0.0, EPSILON))
        {
        if (is_equal(c, 0.0, EPSILON))
            return SS_INF;
        else
            return ZEROROOTS;
        }
    else
        {
        if (is_equal(c, 0.0, EPSILON))
            *x1 = 0.0;
        else
            *x1 = -c / b;
        return ONEROOT;
        }
}

void output(int num_of_roots, double x1, double x2)
    {
    switch (num_of_roots)
        {
        case ZEROROOTS:
            printf("Решений нет!\n");
            break;
        case ONEROOT:
            printf("Одно решение: %f\n", x1);
            break;
        case TWOROOTS:
            printf("Два решения: %f %f\n", x1, x2);
            break;
        case SS_INF:
            printf("Решение - любое число!\n");
            break;
        default:
            printf("Ошибка! Число решений не определено.\n");
        }
    }

int is_equal(double num1, double num2, double eps)
    {
    assert(isfinite(num1));
    assert(isfinite(num2));
    assert(isfinite(eps));

    return fabs(num1 - num2) < eps;
    }

void debug_solving(void)
    {
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;
    int num_of_roots = 0;

    double x1_test = NAN;
    double x2_test = NAN;
    int num_of_roots_test = 0;

    FILE *fp = NULL;
    int passed = 0;
    int test_cnt = 0;

    if ((fp = fopen("test.txt", "r")) != NULL)
        {
            while (fscanf(fp, "%d %lf %lf %lf", &num_of_roots_test, &a, &b, &c) == 4)
                {
                test_cnt++;
                num_of_roots = solvingSq(a, b, c, &x1, &x2);

                // printf("%d %d\n", num_of_roots_test, num_of_roots);

                if (num_of_roots == num_of_roots_test)
                    {
                    switch (num_of_roots_test)
                        {
                        case ZEROROOTS:
                        case SS_INF:
                            printf("Test %d passed\n", test_cnt);
                            passed++;
                            break;
                        case ONEROOT:
                            fscanf(fp, "%lf", &x1_test);
                            if (is_equal(x1, x1_test, EPSILON))
                                {
                                    passed++;
                                    printf("Test %d passed\n", test_cnt);
                                }
                            else
                                printf("Test %d FAILED\n", test_cnt);
                            break;

                        case TWOROOTS:
                            fscanf(fp, "%lf %lf", &x1_test, &x2_test);
                            if ((is_equal(x1, x1_test, EPSILON) && is_equal(x2, x2_test, EPSILON)) \
                                || (is_equal(x1, x2_test, EPSILON) && is_equal(x2, x1_test, EPSILON)))
                                {
                                    passed++;
                                    printf("Test %d passed\n", test_cnt);
                                }
                            else
                                printf("Test %d FAILED\n", test_cnt);
                            break;
                        }
                    }
                else
                    printf("Test %d FAILED\n", test_cnt);
                }
        printf("Пройдено %d/%d тестов!\n", passed, test_cnt);
        }
    else
        printf("Ошибка теста!");

    fclose(fp);
    }

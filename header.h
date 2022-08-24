#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

#define DEBUG

enum numRoots
{
    ZEROROOTS = 0,
    ONEROOT = 1,
    TWOROOTS = 2,
    SS_INF = -1,
};

const double EPSILON = 0.000001;

int solvingSq(double a, double b, double c, double * x1, double * x2);
int solvingLin(double b, double c, double * x1);
double import_koef();
void output(int num_of_roots, double x1, double x2);
int is_equal(double num1, double num2, double eps);
void debug_solving(void);

#endif

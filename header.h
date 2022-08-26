#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define DEBUG

//! @brief My ASSERT maked with using #define
//! @param [in] condition
//! stop programm if condition is true and prints message about error:
//! condition, line, name of function, name of file

#define ASSERT(condition)                                              \
    if (!(condition))                                                  \
    {                                                                  \
        printf("Error in %s in %d line in function %s in file %s\n",   \
                #condition, __LINE__, __PRETTY_FUNCTION__, __FILE__);  \
        abort();                                                       \
    }

//! @brief numRoots - square equation can have these numbers of roots

enum numRoots
{
    ZEROROOTS = 0,
    ONEROOT = 1,
    TWOROOTS = 2,
    SS_INF = -1,
};

//! @brief Const that using for comparing two double numbers with is_equal() function
//! it is the biggest difference between two number what we can consider them equal

const double EPSILON = 0.000001;

//! @brief Function what solves square eqution
//! ax2 + bx + c = 0 - equation type
//!
//! @param [in] a - coefficient a in equation
//! @param [in] b - coefficient b in equation
//! @param [in] c - coefficient c in equation
//! @param [out] x1 - pointer to the 1st root
//! @param [out] x2 - pointer to the 2nd root
//!
//! @return Number of roots (what is in enum numRoot)
//! @note Function solve the equation and assign with pointers x1 and x2
//!       In case of infinite number of roots returns SS_INF

int solvingSq(double a, double b, double c, double * x1, double * x2);

//! @brief Function what solves linear eqution
//! It is one of cases when coefficient a = 0
//! bx + c = 0 - equation type
//! @param [in] b - coefficient b in equation
//! @param [in] c - coefficient c in equation
//! @param [out] x1 - pointer to the root
//!
//! @return Number of roots (what is in enum numRoot)
//! @note Function solve the equation and assign with pointer x1
//!       In case of infinite number of roots returns SS_INF

int solvingLin(double b, double c, double * x1);

//! @brief Function fot import number from console
//! @return imported double number

double import_koef();

//! @brief Function for printing roots
//! @param [in] num_of_roots - number of roots
//! @param [in] x1 - 1st root
//! @param [in] x2 - 2nd root

void output(int num_of_roots, double x1, double x2);

//! @brief Function for compare two double numbers
//! @param [in] num1 - 1st number
//! @param [in] num2 - 2nd number
//! @param [in] eps - biggest difference between two number
//! @return 1 if defference smaller than eps, 0 if defference bigger than eps

int is_equal(double num1, double num2, double eps);

//! @brief Unit tests for solvingSq
//! it import values from test.txt and compare solutions with these values
//! then prints result for every test

void debug_solving(void);

//! @brief Function for checking console arguments
//! if -h - print path to the file's folder

void flag_checking(int argc, char *argv[]);

#endif

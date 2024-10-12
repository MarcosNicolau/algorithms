#ifndef INCLUDE_TEST_H
#define INCLUDE_TEST_H
#define TESTING

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

#define assert(expr) test_assert(expr, __FILE__, __LINE__)

static jmp_buf env;

void test(char *test, void fn(va_list), ...)
{
    printf("\n=============== %s ===============\n", test);
    va_list args;
    va_start(args, fn);
    if (setjmp(env) == 0)
    {
        fn(args);
    }
    va_end(args);
}

void test_assert(int expression, char *file, int line)
{
    if (expression == 0)
    {
        printf("%s %sfailed%s at %s:%d: \n", __func__, RED, RESET, file, line);
        longjmp(env, 1);
    }
    else
    {
        printf("%spassed%s\n", GRN, RESET);
    }
}

#endif
#include "test.h"
#include "stdarg.h"
#include "../src/number-name.c"
#include <signal.h>

void test_str_concat(va_list)
{
    char *res = str_concat("Hey", " ", "how", " ", "are", " ", "you", NULL);

    assert(strcmp(res, "Hey how are you") == 0);
}

void test_get_digit_at(va_list vargs)
{
    int num = va_arg(vargs, int);
    int pos = va_arg(vargs, int);
    int value = va_arg(vargs, int);

    int digit = get_digit_at(num, pos);

    assert(digit == value);
}

int main()
{
    printf("BEGINNING TESTS...\n");
    test("str_concat", test_str_concat, NULL);
    test("get_digit_at 1", test_get_digit_at, 12345678, 0, 1);
    test("get_digit_at 2", test_get_digit_at, 12345678, 7, 8);
    test("get_digit_at 2", test_get_digit_at, 12345678, 4, 5);
    printf("\nTESTS_FINISHED...\n");
}
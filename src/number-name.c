#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define MAX_SIZE 250

char *number_pos[] = {
    "",
    "Hundred",
    "Thousand",
    "Million",
    "Billion",
    "Trillion",
};

char *str_concat(char *first, ...)
{
    char *result = malloc(strlen(first) + 1);
    va_list args;
    strcpy(result, first);
    va_start(args, first);
    char *str = va_arg(args, char *);
    while (str != NULL)
    {
        result = realloc(result, strlen(result) + strlen(str) + 1);
        strcat(result, str);
        str = va_arg(args, char *);
    }
    va_end(args);

    return result;
}

int is_int(float num)
{
    int x = num;

    return num - x > 0 ? 0 : 1;
}

char *get_units_name(int digit)
{
    switch (digit)
    {
    case 0:
        return "Zero";
    case 1:
        return "One";
    case 2:
        return "Two";
    case 3:
        return "Three";
    case 4:
        return "Four";
    case 5:
        return "Five";
    case 6:
        return "Six";
    case 7:
        return "Seven";
    case 8:
        return "Eight";
    case 9:
        return "Nine";
    default:
        return "";
    }
};

char *get_dozens_name(int dozen, int unit)
{
    switch (dozen)
    {
    case 0:
        return get_units_name(unit);
    case 1:
        if (unit == 0)
            return "Ten";
        if (unit == 1)
            return "Eleven";
        if (unit == 2)
            return "Twelve";
        if (unit == 3)
            return "Thirteen";
        return str_concat(get_units_name(unit), "teen", NULL);
    case 2:
        return str_concat("Twenty ", get_units_name(unit), NULL);
    case 3:
        return str_concat("Thirty ", get_units_name(unit), NULL);
    case 4:
        return str_concat("Forty ", get_units_name(unit), NULL);
    case 5:
        return str_concat("Fifty ", get_units_name(unit), NULL);
    case 6:
        return str_concat("Sixty ", get_units_name(unit), NULL);
    case 7:
        return str_concat("Seventy ", get_units_name(unit), NULL);
    case 8:
        return str_concat("Eighty ", get_units_name(unit), NULL);
    case 9:
        return str_concat("Ninety ", get_units_name(unit), NULL);
    default:
        return "";
    }
}

char *get_hundreds_name(int hundred)
{
    return hundred == 0 ? "" : str_concat(get_units_name(hundred), " Hundred ", NULL);
}

char *get_pos_num_name(int pos)
{
    return number_pos[pos];
};

char *get_full_num_name(int hundred, int dozen, int unit, int pos)
{
    char *d = get_dozens_name(dozen, unit);
    char *h = get_hundreds_name(hundred);
    char *quant = pos <= 1 || (hundred == 0 && dozen == 0 && unit == 0) ? "" : str_concat(" ", get_pos_num_name(pos), NULL);

    char *res = str_concat(h, d, quant, NULL);

    return res;
}

int get_int_length(int num)
{
    int count = 0;

    while (num > 0)
    {
        num = num / 10;
        count++;
    }

    return count;
}

int power(int x, int y)
{
    int result = 1;

    if (y == 0)
        return 1;

    if (y < 0)
    {
        for (int i = y; i >= 0; i++)
        {
            result *= 1 / x;
        }
        return result;
    }

    for (int i = 0; i < y; i++)
    {
        result *= x;
    }

    return result;
}

int get_digit_at(int num, int pos)
{
    int result = num;
    int length = get_int_length(num);

    if (pos < 0)
        return 0;

    for (int i = length; i > length - 1 - pos; i--)
    {
        int zeros = power(10, i);
        int factor = (result / zeros);
        result -= zeros * factor;
    };

    if (pos == length - 1)
        return result;

    return result / power(10, length - 1 - pos);
}

int round_upf(float num)
{
    if (!is_int(num))
        return (int)num + 1;
    return (int)num;
}

#ifndef TESTING
int main()
{

    int test_cases = 0;
    printf("ENTER TEST CASES: ");
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++)
    {

        int num = 0;
        printf("ENTER NUM: ");
        scanf("%d", &num);

        char *result = malloc(1);
        result[0] = '\0';
        int length = get_int_length(num);

        int i = length - 1;

        if (num == 0)
        {
            result == get_units_name(num);
            continue;
        }

        while (i >= 0)
        {
            int hundred = get_digit_at(num, i - 2);
            int dozen = get_digit_at(num, i - 1);
            int unit = get_digit_at(num, i);
            int pos = round_upf((float)(length - i) / 3);
            char *name = get_full_num_name(hundred, dozen, unit, pos);
            if (strcmp(name, ""))
            {
                result = realloc(result, strlen(result) + strlen(name));
                result = str_concat(name, " ", result, NULL);
            }
            i -= 3;
        }

        printf("\nRESULT: %s\n", result);

        free(result);
    }

    return 0;
}

#endif
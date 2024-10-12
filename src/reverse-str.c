#include <stdio.h>
#include <stdlib.h>

int str_length(char *str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;

    return count;
}

char *str_reverse(char *str)
{
    int length = str_length(str);
    char *res = malloc(length + 1);

    for (int i = length; i > 0; i--)
        res[length - i] = str[i - 1];

    return res;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("you must provide a string as a parameter");
        return 1;
    }
    char *str = argv[1];
    char *res = str_reverse(str);
    printf("result: %s\n", res);
    free(res);

    return 0;
}

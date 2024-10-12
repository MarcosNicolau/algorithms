#include <stdio.h>
#include <stdlib.h>

char *str_subtr(char *str, int first, int second)
{
    char *result = malloc(second - first + 1);
    int j = 0;

    for (int i = first; i <= second; i++)
        result[j++] = str[i];

    return result;
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("you must provide three arguments...");
        return 1;
    }

    char *str = argv[1];

    char *res = str_subtr(str, atoi(argv[2]), atoi(argv[3]));

    printf("result: %s\n", res);
}
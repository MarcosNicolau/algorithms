#include <stdlib.h>
#include <stdio.h>

int str_len(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

void str_cpy(char *str, char *str_to_copy)
{
    for (int i = 0; i < str_len(str_to_copy); i++)
        str[i] = str_to_copy[i];
}

char **split(char *str, char token, int *res_size)
{
    int size = 0;
    char **res = malloc(1);
    int str_size = str_len(str);

    int splitted_size = 0;
    char *splitted = malloc(1);

    for (int i = 0; i <= str_size; i++)
    {
        if (i == str_size || str[i] == token)
        {
            if (splitted_size == 0)
                continue;
            res = realloc(res, (++size) * sizeof(char *));
            res[size - 1] = malloc(splitted_size);
            str_cpy(res[size - 1], splitted);
            splitted_size = 0;
            splitted = realloc(splitted, 0);
            continue;
        }
        splitted = realloc(splitted, (splitted_size + 1));
        splitted[splitted_size++] = str[i];
    }

    *res_size = size;

    return res;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("you must provide a string and a token\n");
        return 1;
    }

    char *str = argv[1];
    char *token = argv[2];
    int res_size = 0;

    char **res = split(str, token[0], &res_size);

    for (int i = 0; i < res_size; i++)
    {
        printf("result: %s\n", res[i]);
    }

    // free resources
    for (int i = 0; i < res_size; i++)
        free(res[i]);
    free(res);

    return 0;
}
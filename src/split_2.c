#include <stdio.h>
#include <stdlib.h>

int str_size(char *str)
{
    int count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

void str_cpy(char *str, char *str_to_copy)
{
    for (int i = 0; i < str_len(str_to_copy); i++)
        str[i] = str_to_copy[i];
}

char **str_split(char *str, char token, int *result_size)
{
    int str_length = str_size(str);
    char **results = NULL;

    int splitted_size = 0;
    char *splitted = malloc(1);

    for (int i = 0; i < str_length; i++)
    {
        if (str[i] == token)
        {
            results = realloc(results, ++*result_size * sizeof(char *));
            results[*result_size - 1] = malloc(splitted_size);
            str_cpy(results[*result_size - 1], splitted);
            splitted_size = 0;
            splitted = realloc(splitted, 0);
            continue;
        }
        splitted = realloc(splitted, splitted_size + 1);
        splitted[splitted_size++] = str[i];
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("you must provide three arguments...");
        return 1;
    }

    char *str = argv[1];
    char *token = argv[2];

    int result_size = 0;
    char **result = str_split(str, token[0], &result_size);

    printf("string splitted result:\n");
    for (int i = 0; i < result_size; i++)
        printf("\t- %s \n", result[i]);

    for (int i = 0; i < result_size; i++)
        free(result[i]);
    free(result);
    return 0;
}
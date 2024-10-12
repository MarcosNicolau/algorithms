#include <stdlib.h>
#include <stdio.h>

int str_len(char *str)
{
    int i = 0;
    int size = 0;

    while (str[i] != '\0')
    {
        size++;
        i++;
    }

    return size;
}

int find(char *str, char *substr)
{
    int str_length = str_len(str);
    int substr_length = str_len(substr);

    int matched_pos = 0;

    for (int i = 0; i < str_length; i++)
    {
        if (str[i] == substr[matched_pos])
        {
            if (matched_pos == substr_length - 1)
                return 1;
            matched_pos++;
        }
        else
            matched_pos = 0;
    }

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("you must provide a string and a substring\n");
        return 1;
    }

    char *str = argv[1];
    char *subs = argv[2];

    int res = find(str, subs);
    printf("result: %d\n", res);

    // free resources
    free(res);

    return 0;
}
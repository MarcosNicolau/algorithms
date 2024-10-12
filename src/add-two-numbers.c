#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void freeList(struct ListNode *l)
{
    struct ListNode *tmp;
    while (l != NULL)
    {
        tmp = l;
        l = l->next;
        free(tmp);
    }
}

void addToList(struct ListNode **l, int val)
{
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = *l;
    *l = node;
}

void printList(struct ListNode *l)
{
    int pos = 0;
    while (l->next != NULL)
    {
        printf("Value %d at pos %d \n", l->val, pos);
        l = l->next;
        pos++;
    }
}

void reverseLinkedList(struct ListNode **l)
{
    struct ListNode *res = malloc(sizeof(struct ListNode));

    while ((*l)->next != NULL)
    {
        addToList(&res, (*l)->val);
        *l = (*l)->next;
    }

    *l = res;
}

char *listToString(struct ListNode *l)
{
    int size = 0;
    char *str = malloc(size);

    while (l->next != NULL)
    {
        str = realloc(str, ++size);
        str[size - 1] = (char)l->val + '0';
        l = l->next;
    }

    return str;
}

struct ListNode *stringToList(char *str)
{
    struct ListNode *l = malloc(sizeof(struct ListNode));

    int i = 0;
    while (str[i] != '\0')
    {
        addToList(&l, str[i] - '0');
        i++;
    }

    return l;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    reverseLinkedList(&l1);
    reverseLinkedList(&l2);

    char *str1 = listToString(l1);
    char *str2 = listToString(l2);

    int num = atoi(str1) + atoi(str2);

    free(str1);
    free(str2);

    char str[50];
    sprintf(str, "%d", num);

    return stringToList(str);
}

int main()
{
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    struct ListNode *l2 = malloc(sizeof(struct ListNode));

    for (int i = 0; i < 7; i++)
        addToList(&l1, 9);
    for (int i = 0; i < 4; i++)
        addToList(&l2, 9);

    addToList(&l2, 4);
    addToList(&l2, 6);
    addToList(&l2, 5);

    struct ListNode *result = addTwoNumbers(l1, l2);

    printList(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
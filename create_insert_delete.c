#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *newnode, *tmp;

void create(int num)
{
    newnode = malloc(sizeof(struct node));
    if (head == NULL)
    {
        tmp = newnode;
        head = tmp;
    }
    else
    {
        tmp->next = newnode;
        tmp = newnode;
    }
    tmp->data = num;
    tmp->next = NULL;
}

void insert(int n, int num)
{
    newnode = malloc(sizeof(struct node));
    struct node *prev;
    int i = 0;
    if (n == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        tmp = head;
        while (i < n)
        {
            prev = tmp;
            tmp = tmp->next;
            i++;
        }
        newnode->next = tmp;
        prev->next = newnode;
    }
    newnode->data = num;
}

void printit()
{
    tmp = head;
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

void daleteNum(int n)
{
    int i = 0;
    if (n == 0)
    {
        head = head->next->next;
    }
    else
    {
        tmp = head;
        struct node *prev;
        while (i < n)
        {
            prev = tmp;
            tmp = tmp->next;
            i++;
        }
        prev->next = tmp->next;
    }
    //	tmp->data = num;
}

int main()
{
    create(10);
    create(100);
    create(101);
    create(102);
    create(103);
    create(104);
    create(105);
    create(106);
    insert(0, 1418);
    insert(1, 18132);
    daleteNum(2);
    printit();
    printf("\nEnd");
    return 0;
}
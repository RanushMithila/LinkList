#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
int main()
{
    struct node *head = NULL, *newnode, *tmp, *end;
    int num, count, i;

    printf("Number of items: ");
    scanf("%d", &count);
    i = 0;
    while (i < count)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter number: ");
        scanf("%d", &num);

        if (head == NULL)
        {
            tmp = newnode;
            tmp->prev = NULL;
            head = tmp;
        }
        else
        {
            tmp->next = newnode;
            newnode->prev = tmp;
            tmp = newnode;
        }
        tmp->data = num;
        tmp->next = NULL;
        i++;
    }

    tmp = head;
    printf("Forward Data:\n", tmp->data);
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        end = tmp;
        tmp = tmp->next;
    }

    tmp = end;
    printf("\nBackword Data:\n", tmp->data);
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }

    return 0;
}
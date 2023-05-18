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

    // This is the only thing I have to change in order to convert this into doubly circular linked list
    tmp->next = head;
    head->prev = tmp;

    return 0;
}
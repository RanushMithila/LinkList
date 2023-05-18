#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head = NULL, *newnode, *tmp;
    int num, count, i;
    int end = 0;
    char userInput;

    while (!end)
    {
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
                head = tmp;
            }
            else
            {
                tmp->next = newnode;
                tmp = newnode;
            }
            tmp->data = num;
            tmp->next = NULL;
            i++;
        }
        printf("Is that all (Y/N): ");
        scanf(" %c", &userInput);
        if (userInput == 'Y' || userInput == 'y')
        {
            end = 1;
        }
        else if (userInput == 'N' || userInput == 'n')
        {
            end = 0;
        }
    }
    // this is the only thing we have to do for convert this into singly circular linked list
    tmp->next = head;

    return 0;
}
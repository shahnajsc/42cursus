#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct node
    {
        int data;
        struct node * next;
    };
    int choice;
    struct node *head, *newnode, *temp;

    head = 0;
    choice = 0;
    while (choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d", &newnode->data);
        newnode ->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
        printf("do you want to continue(no = 0 / yes = 1)?");
        scanf("%d", &choice);
        temp = head;
        while (temp != 0)
        {
            printf("%d", temp ->data);
            temp1 = temp ->next;
        }


    }

    
} 
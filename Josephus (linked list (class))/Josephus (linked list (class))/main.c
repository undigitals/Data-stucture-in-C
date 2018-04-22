#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node snode;

snode *newnode, *first, *temp1;


snode *create_newnode(int data)
{
    newnode = (snode*) malloc(sizeof(snode));
    newnode->next = newnode;
    newnode->data = data;
    return newnode;
}

void Josephus(int m, int n)
{
    first = create_newnode(1);
    temp1=first;
    for (int i = 2; i <= n; i++)
    {
        temp1->next = create_newnode(i);
        temp1 = temp1->next;
    }
    temp1->next = first; // Connect last node to first
    
    /* while only one node is left in the linked list*/
    snode *ptr1 = first, *ptr2 = first;
    while (ptr1->next != ptr1)
    {
        // Find m-th node
        int count = 1;
        
        while (count != m)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }
        
        /* Remove the m-th node */
        ptr2->next = ptr1->next;
        printf("\n%d is out",ptr1->data);
        free(ptr1);
        ptr1 = ptr2->next;
        
    }
    
    printf ("\nSurvivor is %d\n ",ptr1->data);
}


int main()
{
    int n,m;
    printf("\nEnter total no. of players:");
    scanf("%d", &n);
    printf("\nEnter how many players to skip: ");
    scanf("%d", &m);
    Josephus(m, n);
    return 0;
}

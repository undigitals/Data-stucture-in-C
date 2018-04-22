#include <stdio.h>
#include<string.h>
#include<stdlib.h>



struct node
{
    char name[20];
    int age;
    float gpa;
    struct node* next;
    struct node* prev;
};

typedef struct node snode;

snode *first=NULL, *newnode, *temp1, *temp2, *temp3;

snode* create_node(char [], int , float );
void insert_node_first();
void insert_node_end();
void insert_node_position();
void delete_node_position();
void display();
void display_reverse();





int main()
{
    int choice;
    
    while(1)
    {
        printf("\n1.Insert at the beginning \n2.Insert at the end \n3.Insert at specific position \n4.Delete at specific position \n5.Display \n6.Display in reverse \n7 Exit ");
        printf("\nEnter your choice");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_node_first();
                break;
            case 2:
                insert_node_end();
                break;
            case 3:
                insert_node_position();
                break;
            case 4:
                delete_node_position();
                break;
            case 5:
                display();
                break;
            case 6:
                display_reverse();
                break;
            case 7:
                printf("\n Exiting");
                return 0;
            default:
                printf("Invalid Choice");
                
        }
        
    }
    return 0;
}

snode* create_node(char nm[], int ag, float gp)
{
    newnode=(snode*) malloc(sizeof(snode));
    newnode->next=NULL;
    newnode->prev=NULL;
    strcpy(newnode->name,nm);
    newnode->age=ag;
    newnode->gpa=gp;
    return newnode;
}



void insert_node_first()
{
    char name[20];int age;float gpa;
    
    printf("\nEnter the name:");
    scanf("%s",name);
    printf("Enter the age:");
    scanf("%d", &age);
    printf("Enter the gpa:");
    scanf("%f", &gpa);
    
    newnode=create_node(name,age,gpa);
    
    if (first == NULL)
    {
        first = newnode;
        first->next = NULL;
        first->prev = NULL;
    }
    else
    {
        temp1=first;
        newnode->next=first;
        first->prev=newnode;
        first=newnode;
    }
    
}

void insert_node_end()
{
    char name[20];int age;float gpa;
    
    printf("\nEnter the name:");
    scanf("%s",name);
    printf("Enter the age:");
    scanf("%d", &age);
    printf("Enter the gpa:");
    scanf("%f", &gpa);
    
    newnode=create_node(name,age,gpa);
    
    if (first == NULL)
    {
        first = newnode;
        first->next = NULL;
        first->prev = NULL;
    }
    else
    {
        temp1=first;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        
        temp1->next=newnode;
        newnode->prev=temp1;
    }
}


void insert_node_position()
{
    char name[20];int age,pos;float gpa;
    
    printf("\nEnter the name:");
    scanf("%s",name);
    printf("Enter the age:");
    scanf("%d", &age);
    printf("Enter the gpa:");
    scanf("%f", &gpa);
    
    printf("\nEnter the position to be inserted: ");
    scanf("%d",&pos);
    
    newnode=create_node(name,age,gpa);
    
    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        temp1=first;
        for(int i=1;i<pos;i++)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=newnode;
        temp1->prev=newnode;
        newnode->prev=temp2;
        newnode->next=temp1;
    }
}


void delete_node_position()
{
    int pos;
    printf("\nEnter the position to be deleted: ");
    scanf("%d",&pos);
    
    temp1=first;
    if (pos==1)
    {
        first=temp1->next;
        first->prev=NULL;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp3=temp1->next;
        temp2->next=temp3;
        temp3->prev=temp2;
    }
    free(temp1);
}


void display()
{
    for(temp1=first;temp1!=NULL;temp1=temp1->next)
    {
        printf("%s\t%d\t\%f\n",temp1->name,temp1->age,temp1->gpa);
    }
    
}
void display_reverse()
{
    temp1=first;
    while (temp1->next!=NULL)
    {temp1=temp1->next;}
    while (temp1!=NULL)
    {
        printf("%s\t%d\t\%f\n",temp1->name,temp1->age,temp1->gpa);
        temp1=temp1->prev;
    }
}

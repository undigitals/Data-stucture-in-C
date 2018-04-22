#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
/* push a character into stack */
void push(char a)
{
    top++;
    stack[top]  =  a;
}
/* delete an element in stack */
void pop()
{
    top--;
}


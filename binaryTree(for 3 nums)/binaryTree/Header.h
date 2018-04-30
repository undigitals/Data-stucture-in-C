#ifndef Header_h
#define Header_h

#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
    void* data;
    struct node *left;
    struct node *right;
}NODE;

NODE* newNode(void* data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    
    node->data = data;
    
    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return(node);
}




#endif /* Header_h */

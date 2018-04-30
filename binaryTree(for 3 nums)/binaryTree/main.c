#include "Header.h"

int main(){
   
    int head=1,leaf1=2,leaf2=3;
    
    NODE*root;
    root= newNode(&head);
    root->left = newNode(&leaf1);
    root->right = newNode(&leaf2);
    
    
    
    printf("%i\t %i\t %i\n", *(int*)root->data,*(int*)root->left->data,*(int*)root->right->data);
    
    return 0;
}

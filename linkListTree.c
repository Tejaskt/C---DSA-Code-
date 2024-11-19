#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;

struct node * memo(int data){
    
    struct node *link = (struct node *)malloc(1*sizeof(struct node));
    if(!link){
        printf("memory not allocated...!");
        exit(0);
    }
    
    link->data = data;
    link->right = NULL;
    link->left = NULL;
    
    return link;
}

void create(int data, struct node * root){
    
    if(root == NULL)
        return memo(data);
  
    else if(data<root->data)
        root->left=create(data, root->left);
  
    else
        root->right=create(data, root->right);
  
}

void print(){
    struct node *temp = root;
    if(temp == NULL)
        return;
    print(temp->left);
    printf("%d", temp->data);
    print(temp->right);
}

void main(){
    create(10, root);
    create(5, root);
    create(50, root);
    create(8, root);
    create(30, root);
    create(60, root);
    print();
}

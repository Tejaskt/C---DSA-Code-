#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *l;
    struct node *r;
}*root=NULL;

struct node * memo(int data){
    struct node *link = (struct node*)malloc(1*sizeof(struct node));

    if(!link){
        printf("memory not found");
        exit(0);
    }
    link->data =data;
    link->l = NULL;
    link->r = NULL;
    link->r = NULL;

    return link;
}

void create(int data,struct node *root){
    if(root == NULL){
        return memo(data);
    }
    else if(data<root->data){
        root->l = create(data,root->l);
    }
    else
        root->r = create(data,root->r);
}


int main()
{
    printf("Hello world!\n");
    return 0;
}

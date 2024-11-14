#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *getnode(int val){
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    temp->val=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void createBST(Node **x, int *tree, int n, int index){
    if(index>=n) return;
    if(tree[index]==-1) return;
    *x=getnode(tree[index]);
    createBST(&(*x)->left, tree, n, 2*index+1);
    createBST(&(*x)->right, tree, n, 2*index+2);
}

int isvalid(Node *x){
    int flag=1;
    if(x->left!=NULL){
        if(x->left->val>x->val) return 0;
        flag=isvalid(x->left);
        if(flag==0) return 0;
    }
    if(x->right!=NULL){
        if(x->right->val<=x->val) return 0;
        flag=isvalid(x->right);
        if(flag==0) return 0;
    }
    return flag;
}

void main(){
    Node *root=NULL;
    int *tree, n, i, valid;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    tree=(int *)malloc(n*sizeof(int));
    printf("Enter array: ");
    for(i=0; i<n; i++) scanf("%d", &tree[i]);
    createBST(&root, tree, n, 0);
    valid=isvalid(root);
    if(valid) printf("Valid BST\n");
    else printf("Invalid BST\n");
    free(tree);
}

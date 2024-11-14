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

// Creates a BST given the level traversal array
void createBST(Node **x, int *tree, int n, int index){
    if(index>=n) return;
    if(tree[index]==-1) return;
    *x=getnode(tree[index]);
    createBST(&(*x)->left, tree, n, 2*index+1);
    createBST(&(*x)->right, tree, n, 2*index+2);
}

// Code to find the Least Common Ancestor (LCA)
Node *lca(Node *x, Node*y, Node *root){
    if((x->val<=root->val) && (y->val>=root->val)) return root;
    if((x->val>=root->val) && (y->val<=root->val)) return root;
    if(x->val>root->val) return (lca(x, y, root->right));
    if(x->val<root->val) return (lca(x, y, root->left));
}

void main(){
    Node *root=NULL, *x=NULL, *y=NULL;
    int n, *tree, i, val;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    tree=(int *)malloc(n*sizeof(int));
    printf("Enter array: ");
    for(i=0; i<n; i++) scanf("%d", &tree[i]);
    createBST(&root, tree, n, 0);
    printf("Enter two nodes x and y: ");
    scanf("%d", &val);
    x=getnode(val);
    scanf("%d", &val);
    y=getnode(val);
    printf("Lowest Common Ancestor: %d\n", lca(x, y, root)->val);
    free(tree);
}

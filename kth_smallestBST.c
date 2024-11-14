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

void insert(Node **root, Node *newnode){
    Node *temp;
    temp=*root;
    if(temp==NULL){
        *root=newnode;
        return;
    }
    while(1){
        if(newnode->val<=temp->val){
            if(temp->left==NULL){
                temp->left=newnode;
                return;
            }
            else temp=temp->left;
        }
        if(newnode->val>temp->val){
            if(temp->right==NULL){
                temp->right=newnode;
                return;
            }
            else temp=temp->right;
        }
    }
}

void BST(Node **root, int *tree, int n){
    Node *x;
    int i;
    for(i=0; i<n; i++){
        x=getnode(tree[i]);
        insert(root, x);
    }
}

void order(Node *root, int *k){
    if(root==NULL) return;
    order(root->left, k);
    *k=*k-1;
    if(*k==0){
        printf("kth Smallest = %d\n", root->val);
        return;
    }
    order(root->right, k);
}

void main(){
    Node *root=NULL;
    int i, k, *tree, n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    tree=(int *)malloc(n*sizeof(int));
    printf("Enter array: ");
    for(i=0; i<n; i++) scanf("%d", &tree[i]);
    printf("k = ");
    scanf("%d", &k);
    BST(&root, tree, n);
    order(root, &k);
}

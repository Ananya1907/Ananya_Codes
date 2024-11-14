#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

// Initialize a node
Node *getnode(int val){
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    temp->val=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

// Insert the node in the correct position
void insert(Node **root, Node *newnode){
    Node *temp;
    temp=*root;
    while(1){
        if(newnode->val<temp->val){
            if(temp->left==NULL){
                temp->left=newnode;
                return;
            }
            temp=temp->left;
        }
        else{
            if(temp->right==NULL){
                temp->right=newnode;
                return;
            }
            temp=temp->right;
        }
    }
}

// Creates a height balanced BST
void heightbalancedBST(Node **root, int n, int *tree){
    Node *newnode;
    int i;
    newnode=*root;
    for(i=0; i<n; i++){
        if(tree[i]!=(*root)->val){
            newnode=getnode(tree[i]);
            insert(root, newnode);
        }
    }
}

// Traverses through the BST level-by-level and stores it in bst
void levelTraversal(Node *root, int *bst, int index, int n){
    if(root==NULL){
        if(index<n){
            bst[index]=-10001;
            return;
        }
        else return;
    }
    bst[index]=root->val;
    levelTraversal(root->left, bst, 2*(index)+1, n);
    levelTraversal(root->right, bst, 2*(index)+2, n);
}

void main(){
    Node *root;
    int n, i, *tree, midindex, *bst, maxlength;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    tree=(int *)malloc(n*sizeof(int));
    printf("Enter array: ");
    for(i=0; i<n; i++) scanf("%d", &tree[i]);
    if(n%2==0) midindex=n/2;                        // Since input array is in ascending order,
    else midindex=(n-1)/2;                          // midindex will be the root for a height-balanced BST
    root=getnode(tree[midindex]);
    heightbalancedBST(&root, n, tree);
    maxlength=(pow(2, midindex+1)-1);               // To find the max possible length of the height-balanced BST when doing level traversal
    bst=(int *)malloc(maxlength*sizeof(int));
    levelTraversal(root, bst, 0, maxlength);
    for(i=0; i<maxlength; i++){
        if(bst[i]==-10001) printf("NULL\t");
        else printf("%d\t", bst[i]);
    }
    printf("\n");
    free(bst);
    free(tree);
}

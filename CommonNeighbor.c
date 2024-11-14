#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "graph.c"

// Checks if two nodes (a and b) have a common neighbor
int common(Node **AdjLst, int n, int a, int b){
    Node *row1=AdjLst[a], *row2=AdjLst[b];
    Node *temp=row2;
    while(row1!=NULL){
        while(row2!=NULL){
            if(row1->val==row2->val){
                return 1;
            }
            else{
                row2=row2->next;
            }
        }
        row1=row1->next;
        row2=temp;
    }
    return 0;
}

void main(){
    int a, b, n, A[10][10], i;
    Node **AdjLst;
    printf("Input no. of nodes: ");
    scanf("%d", &n);
    InpAdjLst(n, A);																											// Inputs the Adjacency Matrix
    printf("Input 2 vertices(0 to %d): ", n-1);
    scanf("%d %d", &a, &b);
    AdjLst=(Node **)malloc(n*sizeof(Node *));
    for(i=0; i<n; i++) AdjLst[i]=NULL;
    AdjLst=MatToLst(AdjLst, n, A);																				// Converts the Adjacency Matrix to an Adjacency List
    printf("Common Neighbour? (1 or 0): %d\n", common(AdjLst, n, a, b));
    Free(AdjLst);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "graph.c"

// Checks if the graph has a triangle. A triangle is a set of 3 vertices that are mutually adjacent.
int triangle(Node **AdjLst, int n, int a, int b){
    Node *row1=AdjLst[a], *row2=AdjLst[b];
    Node *temp=row2;
    int flag[3]={0, 0, 0};                  // flag to check if the 3 nodes are mutually adjacent
    while(row1!=NULL){
        if(row1->val==b) flag[0]=1;
        if((flag[0]==1) && (flag[1]==1) && (flag[2]==1)) return 1;
        while(row2!=NULL){
            if(flag[2]==0){
                if(row1->val==row2->val){
                    flag[2]=1;
                }
            }
            if(flag[1]==0){
                if(row2->val==a) flag[1]=1;
            }
            if((flag[0]==1) && (flag[1]==1) && (flag[2]==1)) return 1;
            row2=row2->next;
        }
        row1=row1->next;
        row2=temp;
    }
    return 0;
}

void main(){
    Node **AdjLst;
    int n, A[10][10], flag=0;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    InpAdjLst(n, A);                            // Inputs the Adjacency Matrix
    AdjLst=(Node **)malloc(n*sizeof(Node *));
    MatToLst(AdjLst, n, A);                    // Converts the Adjacency Matrix to an Adjacency List
    for(int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            flag=triangle(AdjLst, n, i, j);
            if(flag==1){
                printf("A triangle EXISTS\n");
                Free(AdjLst);
                exit(0);
            }
        }
    }
    printf("A triangle does NOT exist\n");
    free (AdjLst);
}

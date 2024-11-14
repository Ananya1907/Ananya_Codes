#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "graph.c"

// Shortest Path in Binary Matrix (Lab 9)

void isclear(Node **AdjLst, int n, int *grid[100], int row, int col){
    int rowstart=row-1, rowfin=row+1, colstart=col-1, colfin=col+1;
    if(row==0) rowstart=0;
    if(row==n-1) rowfin=n-1;
    if(col==0) colstart=0;
    if(col==n-1) colfin=n-1;
    for(int i=rowstart; i<=rowfin; i++){
        for(int j=colstart; j<=colfin; j++){
            if((i!=row) | (j!=col)){
                if(grid[i][j]==0) AdjLst[row*n+col]=add(AdjLst[row*n+col], i*n+j);
            }
        }
    }
}

void createList(Node **AdjLst, int n, int *grid[100]){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(grid[i][j]==0) isclear(AdjLst, n, grid, i, j);
        }
    }
}

int path(Node **AdjLst, int n){
    int v, i, visited[100], s=0, count=1;
    Node *temp;
    struct Queue *Q;
    Q=initQueue(n);
    for(i=0; i<100; i++) visited[i]=0;
    Enqueue(Q, s);
    visited[s]=1;
    while (length(Q)!=0){
        v=Dequeue(Q);
        temp=AdjLst[v];
        while(temp!=NULL){
            if(visited[temp->val]==0){
                Enqueue(Q, temp->val);
                visited[temp->val]=1;
                if(temp->val==n-1) return(count+1);
            }
        temp=temp->next;
        }
        count+=1;
    }
    return -1;
}

void main(){
    int n, i, j, *grid[100];
    Node **AdjLst;
    printf("n = ");
    scanf("%d", &n);
    for(i=0; i<n; i++) grid[i]=(int *)malloc(n*sizeof(int));
    AdjLst=(Node **)malloc(n*n*sizeof(Node *));
    printf("Input binary matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++) scanf("%d", &grid[i][j]);
    }
    createList(AdjLst, n, grid);
    printf("Shortest Path = %d\n", path(AdjLst, n*n));
}

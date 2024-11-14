#include<stdio.h>
#include<stdlib.h>
#include "graph.c"

struct Queue *Q;

// BFS code for a graph stored in an Adjacency List
int *bfs(Node **AdjLst, int n, int start, int *visited){
    Node *temp=NULL;
    int i, val;
    Q=initQueue(n);
    Enqueue(Q, start);
    visited[start]=1;
    while(length(Q)!=0){
        val=Dequeue(Q);
        temp=AdjLst[val];
        while(temp!=NULL){
            val=temp->val;
            if(visited[val]==0){
                Enqueue(Q, val);
                visited[val]=1;
            }
            temp=temp->next;
        }
    }
    return (visited);
}

// Code to input an Adjacency List
Node **Inp(Node **AdjLst, int n){
    Node *newnode=NULL, *head, *top;
    int i, j, val;
    for(i=0; i<n; i++){
        printf("Vertices adjacent to %d: ", i);
        top=NULL;
        head=NULL;
        for(j=0; j<n; j++){
            scanf("%d", &val);
            if(val==-1) break;
            newnode=getnode(val);
            if(top==NULL) top=newnode;
            else head->next=newnode;
            head=newnode;
        }
        AdjLst[i]=top;
    }
    return (AdjLst);
}

void main(){
    Node **AdjLst=NULL;
    int n, *visited, i, j, count=0;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    AdjLst=(Node **)malloc(n*sizeof(Node *));
    visited=(int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++) visited[i]=0;
    AdjLst=Inp(AdjLst, n);
    for(i=0; i<n; i++){
        if(visited[i]==0){                        // If the node has not been visited by one iteration of bfs,
            visited=bfs(AdjLst, n, i, visited);   // that means that it belongs to a different connected component of the graph
            count+=1;
        }
    }
    printf("Number of connected components = %d\n", count);
    free(visited);
    Free(AdjLst, n);
}

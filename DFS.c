#include<stdio.h>
#include<stdlib.h>
#include "graph.c"

Node *Stack=NULL;

// Finds the unvisited neighbors of a node
int findUnvisited(struct Graph G, int current, int *visited){
    Node *temp;
    temp=G.AdjList[current];
    while(temp!=NULL){
        if(visited[temp->val]==0) return(temp->val);
        temp=temp->next;
    }
    return(-1);
}

// Code to perform Depth-First Search (DFS)
void dfs(struct Graph G, int startNode){
    int visited[100], i, current, x, a;
    for(i=0; i<G.n; i++) visited[i]=0;
    visited[startNode]=1;
    printf("Visited node %d\n", startNode);
    Stack=push(Stack, startNode);
    while(Stack!=NULL){
        current=Stack->val;
        x=findUnvisited(G, current, visited);
        if(x>-1){
            visited[x]=1;
            printf("Visited node %d\n", x);
            Stack=push(Stack, x);
        }
        else a=pop(&Stack);
    }
}

void main(){
  int n, A[10][10], s;
  struct Graph G;
  printf("Input no. of nodes: ");
  scanf("%d", &n);
  InpAdjLst(n, A);	
  G=initGraph(n, A);
  printf("Enter start node: ");
  scanf("%d", &s);
  dfs(G, s);
}

#include<stdio.h>
#include<stdlib.h>
#include "graph.c"

struct Queue *Q;

// Code to perform Breadth-First Search (BFS)
void bfs(Node** AdjLst, int s, int n){     // s start vertex, n number of vertices
  int v, i, visited[100];
  Node *temp;
  for (i=0; i<100; i++) visited[i]=0;
  Enqueue(Q, s);
  visited[s]=1;
  while (length(Q)!=0){
  	v=Dequeue(Q);
  	printf("Visited %d\n", v);
  	temp=AdjLst[v];
  	while(temp!=NULL){
  	 if(visited[temp->val]==0){
  	 	Enqueue(Q, temp->val);
  	 	visited[temp->val]=1;
  	 }
  	 temp=temp->next;
  	}
  }
  // To check if the graph is connected
  int count=0;
  for (i=0; i<n; i++){
    if(visited[i]==1) count+=1;
  }
  if(count==n) printf("\n\nGraph is connected");
  else printf("\n\nGraph is disconnected");
  // To count the number of edges
  count=0;
  Node *row;
  for (i=0; i<n; i++){
  	row=AdjLst[i];
    while(row!=NULL){
      count+=1;
      row=row->next;
    }
  }
  printf("\nNumber of edges = %d\n", count/2);
}

void main(){
  int n, i, A[10][10], s;
  Node **AdjLst;
	printf("Input no. of nodes: ");
	scanf("%d", &n);
	InpAdjLst(n, A);	
  AdjLst=(Node **)malloc(n*sizeof(Node *));
  for(i=0; i<n; i++) AdjLst[i]=NULL;
  AdjLst=MatToLst(AdjLst, n, A);
  Q=initQueue(n);
	print("Enter start node: ");
	scanf("%d", &s);
  bfs(AdjLst, s, n);
  Free(AdjLst, n);
  free(Q->QArr);
  free(Q);
}

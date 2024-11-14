#include<stdio.h>
#include<stdlib.h>
#include "graph.c"

// Finds degree of ith vertex
int deg(Node **AdjLst, int i){
  Node *ithrow=AdjLst[i];
  int count=0;
  while(ithrow!=NULL){
    count+=1;
    ithrow=ithrow->next;
  }
  return(count);
}

// Checks if an Euler tour exists (assume connected graph)
int Eulerian(Node **AdjLst, int n){
  for(int i=0; i<n; i++){
    if(deg(AdjLst, i)%2==1) return 0;
  }
  return 1;
}

void main(){
	Node **AdjLst;
  int n, A[10][10];
  printf("Input no. of nodes: ");
  scanf("%d", &n);
  InpAdjLst(n, A);
  AdjLst=(Node **)malloc(n*sizeof(Node *));
  for(int i=0; i<n; i++) AdjLst[i]=NULL;
  AdjLst=MatToLst(AdjLst, n, A);
  printf("\n Is the graph Eulerian (0 or 1): %d\n", Eulerian(AdjLst,n));
}

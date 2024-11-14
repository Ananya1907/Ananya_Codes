#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// This is a header file for other codes

// ****************** Linked List ******************

struct node{
    int val;
    struct node *next;
};

typedef struct node Node;

Node *getnode(int v){
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    temp->val=v;
    temp->next=NULL;
    return temp;
};

Node *add(Node *head, int v){
    Node *temp;
    temp=getnode(v);
    temp->next=head;
    head=temp;
    return head;
};

Node *delete(Node *head, int v){
  Node *temp;
  if(head==NULL){
  	return head;
  }
  if(head->val==v){
  	temp=head->next;
    free(head);
  	return temp;
  }
  head->next=delete(head->next, v); 
  return head;
};

void print(Node *head){
  while(head!=NULL){
      printf("%d  ", head->val);
      head=head->next;
    }
}

// ****************** Adjacency List ******************

void PrintAdjLst(Node **AdLst, int n){
  int i;
  for(i=0;i<n;i++){ 
  	printf("Vertices adjacent to %d: ",i); 
  	print(AdLst[i]);
    printf("\n");
  }
}

Node *addRow(Node *ithRow, int i, int n, int A[n][n]){
    for(int j=0; j<n; j++){
        if(A[i][j]==1){
            ithRow=add(ithRow, j);
        }
    }
    return(ithRow);
}

Node **MatToLst(Node **AdjLst, int n, int A[n][n]){
    for(int i=0; i<n; i++){
        AdjLst[i]=addRow(AdjLst[i], i, n, A);
    }
    return(AdjLst);
}

void InpAdjLst(int n, int A[n][n]){
    for (int i=0; i<n; i++){
        printf("Enter %d row values: ", i);
        for (int j=0; j<n; j++){
            scanf("%d", &A[i][j]);
        }
    }
}

void Free(Node **AdjLst, int n){
  Node *temp;
  for (int i=0; i<n; i++){
    while(AdjLst[i]!=NULL){
      temp=AdjLst[i];
      AdjLst[i]=AdjLst[i]->next;
      free(temp);
    }
  }
  free(AdjLst);
}

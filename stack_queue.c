#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// LINKED LIST

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
  while(head!=NULL)
    {
      printf("%d  ", head->val);
      head=head->next;
    }
}

// Matrix

void linTo2D(int *B, int n, int A[n][n]){
  int i, j;
  int k=0;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      A[i][j]=B[k];
      k++;
    }
  }
}

void printMat(int n, int A[n][n]){
  int i, j;
  for(i=0; i<n; i++){
    printf("\n");
    for(j=0; j<n; j++) printf("%d\t", A[i][j]);
  }
  printf("\n");
}

// Adjacency List

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

// STACK - LIFO

Node *push(Node *head, int v){
  return add(head, v);
}

int pop(Node **headP){
  int a;
  Node *temp;
  temp=*headP;
  if (temp==NULL){
    printf("Underflow");
    return -1;
  }
  *headP=temp->next;
  a=temp->val;
  free(temp);
  return a;
}

// QUEUE - FIFO

// Array Implementation

struct Queue{
 int* QArr;
 int capacity;
 int head;
 int tail;
};

struct Queue* initQueue(int capacity){
  struct Queue* Q;
  Q=(struct Queue *)malloc(sizeof(struct Queue));
  int i;
  Q->QArr=(int *)malloc(capacity*sizeof(int));
  Q->capacity=capacity;
  Q->head=0;
  Q->tail=0;
  for(i=0; i<Q->capacity; i++) Q->QArr[i]=-1;
  return Q;
}

int length(struct Queue* Q){ 
  int i;
  int l=0;
  for(i=0; i<Q->capacity; i++){
    if(Q->QArr[i]!=-1) l++;
  }
  return l;
}

void Enqueue(struct Queue* Q, int a){
  if((Q->head==Q->tail) && (Q->QArr[Q->head]!=-1)){
    printf("Overflow\n");
    return;
  }
  Q->QArr[Q->tail]=a;
  if (Q->tail == Q->capacity -1){
    Q->tail=0;
    return;
  }
  else Q->tail=Q->tail+1;
}

int Dequeue(struct Queue* Q){
  if((Q->head==Q->tail) && (Q->QArr[Q->head]==-1)){
    printf("Underflow\n");
    return -1;
  }
  int a;
  a=Q->QArr[Q->head];
  Q->QArr[Q->head]=-1;
  if(Q->head==Q->capacity-1) Q->head=0;
  else Q->head=Q->head+1;
  return a;
}

int PrintQ(struct Queue* Q){
  int i;
  printf("\nLength=%d head=%d tail=%d\n", length(Q), Q->head, Q->tail);
  for(i=0; i<Q->capacity; i++) printf("%d\t", Q->QArr[i]);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "graph.c"

// Checks if two words (word1 and word2) differ by 1 or more letters
// If it differs by exactly one letter, they are considered neighbors/adjacent (returns 1)
// If they differ by more than 1 letter, it returns 0
// If they are identical, it returns -1
int isAdj(char *word1, char *word2, int l){
    int count=0;
    for(int i=0; i<l; i++){
        if(word1[i]!=word2[i]){
            count+=1;
            if(count>1) return 0;
        }
    }
    if(count==0) return -1;
    return 1;
}

// Checks if a word is already in wordList. If it's not, it adds the word to wordList and updates the count.
// It is used to add the beginWord and endWord to wordList if they’re not already present.
// It returns the index of the word in wordList.
int wordcheck(char *word, char **wordList, int wordSize, int *wordCount){
    int i, check=0, u;
    for(i=0; i<*wordCount; i++){
        if(isAdj(word, wordList[i], wordSize)==-1){
            check+=1;
            u=i;
            return(u);
        }
    }
    wordList[*wordCount]=(char *)malloc(15*sizeof(char));
    strcpy(wordList[*wordCount], word);
    u=*wordCount;
    *wordCount+=1;
    return(u);
}

// This function uses Breadth-First Search (BFS) to find the shortest path from beginWord to endWord in the graph.
// u-> start node    v-> end node
// If no path exists between u and v, it returns 0
int ladderLength(Node **AdjLst, int u, int v) {
    int t, i, visited[100], count=0;
    Node *temp;
    struct Queue *Q;
    Q=initQueue(50);
    for (i=0; i<100; i++) visited[i]=0;
    Enqueue(Q, u);
    visited[u]=1;
    while (length(Q)!=0){
        t=Dequeue(Q);
        temp=AdjLst[t];
        while(temp!=NULL){
            if(visited[temp->val]==0){
                Enqueue(Q, temp->val);
                visited[temp->val]=1;
                if(temp->val==v) return(count+=1);
            }
            temp=temp->next;
        }
        count+=1;
    }
    return 0;
}

void main(){
    char beginWord[15], endWord[15], *wordList[100];
    int wordCount, wordSize, i, j, c, u=0, v=0;
    Node **AdjLst;
    printf("Enter number of words in the list: ");
    scanf("%d", &wordCount);
    for(i=0; i<wordCount; i++) wordList[i]=(char *)malloc(15*sizeof(char));
    printf("Enter word list:\n");
    for(i=0; i<wordCount; i++) scanf("%s", wordList[i]);
    printf("Enter beginWord: ");
    scanf("%s", beginWord);
    printf("Enter endWord: ");
    scanf("%s", endWord);
    wordSize=strlen(beginWord);
    u=wordcheck(beginWord, wordList, wordSize, &wordCount);        // checks if beginword is in wordlist
    v=wordcheck(endWord, wordList, wordSize, &wordCount);          // checks if endword is in wordlist
    if(v==wordCount-1){                                            // if endword was not initially part of wordlist, a path will not exist (this is a constraint)
        printf("0\n");
        for(i=0; i<wordCount; i++) free(wordList[i]);
        exit(0);
    }
    AdjLst=(Node **)malloc(wordCount*sizeof(Node *));
    for(i=0; i<wordCount; i++) AdjLst[i]=NULL;
    for(i=0; i<wordCount-1; i++){
        for(j=i+1; j<wordCount; j++){
            c=isAdj(wordList[i], wordList[j], wordSize);           // checks if the words are adjacent
            if(c==1){
                AdjLst[i]=add(AdjLst[i], j);                       // if yes, then they are added to the Adjacency List
                AdjLst[j]=add(AdjLst[j], i);
            }
        }
    }
    printf("%d\n", ladderLength(AdjLst, u, v));
    for(i=0; i<wordCount; i++) free(wordList[i]);
    Free(AdjLst, wordCount);
}

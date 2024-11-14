#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void main(){
    char letter, *str;
    int n, num, j, k, i=0;
    printf("Enter the string: ");
    scanf("%s", str);
    n=strlen(str);
    while(i<n){
        if(isalpha(str[i])){
            letter=str[i];
            i+=1;
        }
        else {
            num=0;
            while(isdigit(str[i])){
                num= num*10+(str[i]-'0');
                i+=1;
            }
            for(j=0; j<num; j++) printf("%c", letter);
        }
    }
    printf("\n");
}

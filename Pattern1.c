#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// Input: a3b5H2
// Output: aaabbbbbHH
void main(){
    char letter, *str;
    int n, num, j, k, i=0;
    printf("Enter the string: ");
    scanf("%s", str);
    n=strlen(str);
    while(i<n){
        if(isalpha(str[i])){        // checks if the input is an alphabet,
            letter=str[i];          // and stores it in letter to print later
            i+=1;
        }
        else {
            num=0;
            while(isdigit(str[i])){           // checks if input is a digit,
                num= num*10+(str[i]-'0');     // and stores the number of times letter is to be printed in num
                i+=1;
            }
            for(j=0; j<num; j++) printf("%c", letter);
        }
    }
    printf("\n");
}

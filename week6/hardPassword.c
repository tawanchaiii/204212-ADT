#include<stdio.h>
#include<string.h>
char A[100000];
int main(){
    scanf("%s",A);
    int i=0;
    int j=strlen(A)-2;
    while(!(A[i]=='x' || A[j]=='x')){
        if(A[i] != A[j]) {printf("0"); return 0;}
        i++; j--;   
    }
    if(i==j) printf("1");
    else printf("0");
    return 0;
}

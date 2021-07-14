#include<stdio.h>
#include<string.h>
int len,sublen,want;
char str[100001];
char substr[100001];
void solve(char str1[],char str2[]){
    printf("[");
    for(int k=0;k<sublen;k++){
        if (str1[k] == str2[k]) printf("%c",str1[k]);
        else printf("?");
    }
    printf("]");
}
void substrfunc(char* dest,char* src,size_t begin,size_t end){
    strncpy(dest,src+begin,end-begin);
    dest[end-begin] = '\0';
}
int main(){
    scanf("%d%d%d",&len,&sublen,&want);
    scanf("%s",str);
    scanf("%s",substr);
    int i = 0;
    char tempsub[sublen];
    while(i<len){
        int nub = 0;
        if (i>=len-sublen+1) {
            printf("%c",str[i]);
            i++;
        }
        else{
            for (int j=0;j<sublen;j++){
                if (str[i+j] != substr[j]) nub++;
            }
            if (nub <= want){
                substrfunc(tempsub,str,i,i+sublen);
                solve(tempsub,substr);
                memset(tempsub,0,sizeof(tempsub));
                i+=sublen;
            }
            else{
                printf("%c",str[i]);
                i++;
            } 
        }
    }
}
/*
18 3 0
acabababababcbabab
aba

18 3 1
acabababababcbabab
aba

19 3 3
acabababababcbababa
aba

15 4 2
AAAGTGTGTCTGATT
GTAT
*/
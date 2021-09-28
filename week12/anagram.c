#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(char str[],int l,int m,int r){
    int i,j,k;
    int nl = m-l+1;
    char L[nl];
    int nr = r-m;
    char R[nr];
    for(i=0;i<nl;i++) L[i] = str[l+i];
    for(j=0;j<nr;j++) R[j] = str[m+1+j];
    i=0,j=0,k=l;
    while(i <nl && j<nr)
        str[k++] = (L[i]<=R[j])? L[i++] : R[j++];
    while (i < nl)
        str[k++] = L[i++];
    while (j < nr)
        str[k++] = R[j++];
}
void merge_sort(char str[],int l,int r){
    if(l < r){
        int m = l + (r-l)/2;
        merge_sort(str,l,m);
        merge_sort(str,m+1,r);
        merge(str,l,m,r);
    }
}
int main(){
    int m,n; scanf("%d%d",&m,&n);
    char str[m][55];
    char sort_str[m][55];
    for(int i=0;i<m;i++){
        scanf("%s",str[i]);
        strcpy(sort_str[i],str[i]);
        merge_sort(sort_str[i],0,strlen(sort_str[i])-1);
        //printf("sort = %s\n",sort_str[i]);
    } 
    for(int i=0;i<n;i++){
        char test[55]; scanf("%s",test);
        merge_sort(test,0,strlen(test)-1);
        for(int j=0;j<m;j++){
            if(strcmp(test,sort_str[j]) == 0)
                printf("%s ",str[j]);
        }
        printf("\n");
    } 
}
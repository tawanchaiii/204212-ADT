#include<stdio.h>
int fac(int n){
    if (n==0) return 1;
    else return n*fac(n-1);
}
int A[1000001],t,i,w;
int check(int n){
    int ans = 0;
    while(n>0){
        ans+=fac(n%10);
        n = n/10;
    }
    return ans;
}
int main(){ 
    for(i=0;i<=1000000;i++){
        if (i == check(i)) A[i] = 1;
    }
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&w);
        for(i=w-1;;i--){
            if (A[i]==1) {
                printf("%d\n",i); break;
            }
        }
    }
    return 0;
}
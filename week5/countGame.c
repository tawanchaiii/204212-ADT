#include<stdio.h>
int n,k,cnt=0,nub=1,run=0;
int checkDigit(int x){
    int temp[10];
    for(int i = 0;i<8;i++) {temp[i] = x%10; x/=10;}
    for(int i=0;i<8;i++) {
        if (temp[i] == k) return 1;
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&k);
    int A[n];
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    while(1){
        if(A[run]>=0){ // simple nub
            if((nub%k == 0 || checkDigit(nub) == 1) ) A[run]--; //drink
            nub++;
            if (A[run]<0) cnt++;
            
        }
        if(n-cnt == 1) break;
        run++;
        if (run==n) run = 0;    
    }
    for(int i=0;;i++){
        if (A[i]>=0) {printf("%d",i+1); break;}
    }
    return 0;
}
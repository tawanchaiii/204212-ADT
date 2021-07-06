#include<stdio.h>
void solve(int n){
int value[] = {1000, 900, 500, 400,100, 90, 50, 40,10, 9, 5, 4,1};
char symb[][3] = {"M", "CM", "D", "CD","C", "XC", "L", "XL","X", "IX", "V", "IV","I"};
    int i=0;
    while(n>0){
        while(n>=value[i]){
            printf("%s",symb[i]);
            n-=value[i];
        }
        i++;
    }
    
    printf("\n");
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; 
        scanf("%d",&n);
        solve(n);
    }
}
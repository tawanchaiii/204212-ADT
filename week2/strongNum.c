#include<stdio.h>
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        if (n>40585) printf("40585\n");
        else if (n>145) printf("145\n");
        else if (n>2) printf("2\n");
        else if (n>1) printf("1\n");
    }
    return 0;
}
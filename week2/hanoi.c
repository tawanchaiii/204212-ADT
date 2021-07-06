#include<stdio.h>
void hanoi(int n,char from,char to,char aug){
    if(n==1){
        printf("%c -> %c\n",from,to);
        return;
    }
    hanoi(n-1,from,aug,to);
    hanoi(1,from,to,aug);
    hanoi(n-1,aug,to,from);
}
int main(){
    printf("Enter n: ");
    int n; scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}
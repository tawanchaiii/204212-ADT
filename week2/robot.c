#include<stdio.h>
#include<math.h>
long long ii[] = {0,1,0,-1};
long long jj[] = {1,0,-1,0};
int main(){
    int t,i; scanf("%d",&t);
    long long x=0,y=0;
    int status = 400000;
    char str[t];
    scanf("%s",str);
    for(i=0;i<t;i++){
        if (str[i] == 'L') status--;
        if (str[i] == 'R') status++;
        if (str[i] == 'F') {
            x += ii[status%4];
            y += jj[status%4];
        }
    }
    printf("%.4f",sqrt((x*x)+(y*y)));
    return 0;
}
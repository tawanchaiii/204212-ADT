#include<stdio.h>
#include<math.h>
double n,g,oldg,newg;
int main(){
    scanf("%lf %lf",&n,&g);
    oldg = g;
    while(1){
        newg = 0.5*(oldg+n/oldg);
        printf("%.10lf %.10lf %.10lf\n",newg,oldg,fabs(oldg-newg));
        if (fabs(oldg-newg) < 1e-10) break;
        oldg = newg;
    }
    printf("%.10lf",oldg);
}
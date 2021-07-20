#include<stdio.h>
#include<math.h>
int main(){
    long long n; scanf("%lld",&n);
    long long limit = (long long) sqrt(n) + 1 ;
    if (n==0 || n==1 ) {
        printf("0");
        return 0;
    }
    else{
        for (long long i = 2;i<limit;i++){
            if (n%i == 0) {
                printf("0");
                return 0;
            } 
        }
        printf("1");
        return 0;
    }
}
// complexity is O(sqrt(n))
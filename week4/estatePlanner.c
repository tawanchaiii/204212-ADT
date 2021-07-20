#include<stdio.h>
#include<math.h>
int m,n,mm,nn,use[20],ans=0;
int main(){
    scanf("%d%d",&m,&n); mm=m; nn=n;
    while(mm>0){
        int chk = mm&-mm; // find first least bit 
        use[(int)log2(chk)] = 1;
        ans+=n/chk;
        mm-=chk;
    }
    while(nn>0){
        int chk = nn&-nn; // find first least bit 
        ans+=m/chk;
        if (use[(int)log2(chk)]) ans-=1; 
        nn-=chk;
    }
    printf("%d",ans);
}

// complexity of this solution is O(lg(m)) + O(lg(n))= O(lg(mn))


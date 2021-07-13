#include<stdio.h>
#include<stdlib.h>
#define MAX_LIMIT 100
char A[1001][1001],junk;
int visit[1001][1001];
int n;
int ii[] = {0,1,0,-1};
int jj[] = {1,0,-1,0};
int found = 0;
void traverseMaze(int a,int b){
    visit[a][b] = 1;
    if(A[a][b] == 'G') {
        found = 1;
        return;
    }
    for(int k=0;k<4;k++){
        if (a+ii[k] >=1 && a+ii[k] <=n &&  b+jj[k] >=1 && b+jj[k] <=n ) {
            if (A[a+ii[k]][b+jj[k]] != '#' && visit[a+ii[k]][b+jj[k]] == 0){
                traverseMaze(a+ii[k],b+jj[k]);
                if (A[a][b] == ' ' && found ==1) {
                    A[a][b] = '.';
                    return;
                }
            }
        }
    }
    
}
int main(){
    scanf("%d",&n);
    char temp[MAX_LIMIT];
    fgets(temp, MAX_LIMIT, stdin);
    for(int i=0;i<n;i++){
        char temp[MAX_LIMIT];
        fgets(temp, MAX_LIMIT, stdin);
        //scanf("%[^\n]%*c", temp);
        if (i<n) {for(int j=0;j<n;j++) A[i+1][j+1] = temp[j];}
    }
    int check = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (A[i][j] == 'S') {
                traverseMaze(i,j);
                check = 1;
                break;
            }
        }
        if (check == 1) break;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}


/*
12
############
#   #      #
S # # #### #
### #    # #
#    ### # G
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
############

12
############
#   #      #
S # # #### #
### #    # #
#     ## # G
#### # # # #
#  # # # # #
## ### # # #
#        # #
###### ### #
#      #   #
############

12
############
#   #      #
S # ###### #
### #    # #
#        # G
#### # # # #
#  # # # # #
## ### # # #
#        # #
###### ### #
#          #
############
*/

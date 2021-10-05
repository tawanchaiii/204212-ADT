// implement by Floyd-Warshall Algorithm
#include <stdio.h>
#include <stdlib.h>
#define INF 1e9 
int dist[1000][1000];
int min(int x,int y){
    return x<y ? x : y;
}
int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }    
    }
    for(int i=0;i<p;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(dist[u][v]!=INF) printf("%d\n",dist[u][v]);
        else printf("-1\n");
    }
}
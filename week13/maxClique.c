#include <stdio.h>
int store[1000], node,edge;
int graph[1000][1000];
int max(int x,int y){
    return x>y ? x : y;
} 
int is_clique(int b)
{
    for (int i = 1; i < b; i++) {
        for (int j = i + 1; j < b; j++)
            if (graph[store[i]][store[j]] == 0)
                return 0;
    }
    return 1;
}
int maxCliques(int i, int l)
{
    int max_ = 0;
    for (int j = i + 1; j <= node; j++) {
        store[l] = j;
        if (is_clique(l + 1)) {
            max_ = max(max_, l);
            max_ = max(max_, maxCliques(j, l + 1));
        }
    }
    return max_;
}
int main()
{
    scanf("%d %d",&node,&edge);
    int edges[edge][2];
    for (int i = 0; i < edge; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        graph[u+1][v+1] = 1;
        graph[v+1][u+1] = 1;
    }
    printf("%d",maxCliques(0, 1));
    return 0;
}

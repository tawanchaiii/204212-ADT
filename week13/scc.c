#include <stdio.h>
int graph[100][100];
int graph_t[100][100];
int visited[105];
int visited2[105];
int node,edge;
int ex[1000][2];
int ex2[1000][2];
int cnt = 1;
int ans[1000];
int max = 0;
void dfs(int u){
    visited[u] = 1;
    ex[u][0] = cnt;
    cnt++;
    for(int i=0;i<node;i++){
        if(graph[u][i] == 1 && !visited[i])
            dfs(i);
    }
    ex[u][1] = cnt;
    cnt++;
}
void dfs2(int u,int len,int willans[]){
    //printf("%d ",u);
    visited2[u] = 1;
    willans[len] = u;
    for(int i=0;i<node;i++){
        if(graph_t[u][i] == 1 && !visited2[i])
            dfs2(i,len+1,willans);
    }   
    // update ans
    if(len+1>max){
        max = len+1;
        for(int i=0;i<max;i++){
            ans[i] = willans[i];
        }
    }
    
}
int main()
{
    scanf("%d %d",&node,&edge);
    int edges[edge][2];
    for (int i = 0; i < edge; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        graph[u][v] = 1;
        graph_t[v][u] = 1;
    }
    for(int i=0;i<node;i++){
        if(ex[i][0]==0)   
            dfs(i);
    }

    /*for(int i=0;i<node;i++){
       printf("%d %d\n",ex[i][0],ex[i][1]);
    }*/
    for(int j=0;j<node;j++){
        int maxx = 0;
        int savei = 0;
        for(int i=0;i<node;i++){
            if(ex[i][1] > maxx){
                savei = i;
                maxx = ex[i][1];
                ex[i][1] = 0;
            }
        }
        if(!visited2[savei]){
            int willans[node+1];
            dfs2(savei,0,willans);
            //printf("\n");
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            if(ans[i]<ans[j]){
                int temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
        }
    }
    for(int i=0;i<max;i++) printf("%d ",ans[i]);
    return 0;
}

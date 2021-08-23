#include<bits/stdc++.h>
using namespace std;
int visit[100];
vector<char>g[100];
void bfs(char s){
    queue<char> q;
    int visited[100] = {0};
    q.push(s);
    while(!q.empty()){
        char u = q.front();
        visited[u-'A'] = 1;
        printf("%c ",u);
        q.pop();
        int y = u-'A';
        for(auto v : g[y]){
            int x = v-'A';
            if(!visited[x]) q.push(v);
        }
    }
}
void dfs(char u){
    visit[u-'A'] = 1;
    printf("%c ",u);
    int y = u-'A';
    for(auto v: g[y]){
        int x = v-'A';
        if(!visit[x]) dfs(v);
    }
    return;
}
int main(){
    int n; scanf("%d",&n);
    while(n--){
        char a,b; scanf(" %c %c",&a,&b);
        g[a-'A'].push_back(b);
    }
    printf("BFS : ");
    bfs('r');
    printf("\n");
    printf("DFS : ");
    dfs('r');
    return 0;
}
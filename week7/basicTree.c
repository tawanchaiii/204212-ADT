// implement by using adjacency list
#include <stdio.h>
#include <stdlib.h>
int SIZE = 10000;
int globalroot = -1;
int showReverse[10000];
int showR;
struct node{
    int dest;
    struct node* next;
};
struct adj_list{
    struct node* head;
};
typedef struct tree_tt{
    int V;
    struct adj_list* array;
}tree_t;
typedef struct queue{
    int front;
    int back;
    int* arr;
}queue_t;

queue_t createQueue(){
    queue_t q = {0,-1,NULL};
    q.arr = (int*)malloc(SIZE*sizeof(int));
    return q;
}

struct node* createNode(int dest){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode; 
}


tree_t* createTree(){
    tree_t* tree = (tree_t*)malloc(sizeof(tree_t));
    tree->array = (struct adj_list*)malloc(SIZE * sizeof(struct adj_list));
    tree->V = SIZE;
    for(int i=0;i<SIZE;i++) {
        tree->array[i].head = NULL;
    }
    return tree;
}

tree_t* attach(tree_t* t,int src,int dest){
    if (t == NULL){
        t = createTree();
        globalroot = dest;
    } 
    if(src!=-1){
        struct node* newnode = createNode(dest);
        struct node* dummy = t->array[src].head;
        if (dummy == NULL){
            t->array[src].head = newnode;
        }
        else{
            while(dummy->next!=NULL)
                dummy = dummy->next;
            dummy->next = newnode;
        }
    }
    return t;
}
tree_t* detach(tree_t* t,int src){
    int jum[SIZE];
    int cnt = 0;
    queue_t q = createQueue();
    q.back++;
    q.arr[q.back] = src;
    while(q.front <= q.back){
        int u = q.arr[q.front];
        q.front++;
        jum[cnt] = u;
        cnt++;
        struct node* v = t->array[u].head;
        while(v)
        {
            q.back++;
            q.arr[q.back] = v->dest;
            v = v->next;
        }
    }
    for(int i=0;i<cnt;i++){
        t->array[jum[i]].head = NULL;
    }
    for(int i=0;i<SIZE;i++){
        if (t->array[i].head!=NULL){
            struct node* dummy = t->array[i].head;
            if (dummy->dest == src){
                t->array[i].head = dummy->next;
            }
            else{
                while(dummy->next!=NULL){
                    if(dummy->next->dest == src){
                        dummy->next = dummy->next->next;
                        break;
                    } 
                    dummy = dummy->next;
                }
            }
        }
    }
    return t;
}
void dfs2(tree_t* t,int u){
    printf("%d ",u);
    struct node* v = t->array[u].head;
    while(v)
    {
        dfs2(t,v->dest);
        v = v->next;
    }
}

void dfs(tree_t* t){
    dfs2(t,globalroot);
    printf("\n");
}
int dfs_for_search(tree_t* t,int u,int arg){
    if (u == arg) return 1;
    struct node* v = t->array[u].head;
    while(v)
    {
        int ch = dfs_for_search(t,v->dest,arg);
        if (ch) return 1;
        v = v->next;
    }
    return 0;
}
int search(tree_t* t,int arg){
    return dfs_for_search(t,globalroot,arg);
}
void bfs(tree_t* t){
    queue_t q = createQueue();
    q.back++;
    q.arr[q.back] = globalroot;
    while(q.front <= q.back){
        int u = q.arr[q.front];
        q.front++;
        printf("%d ",u);
        struct node* v = t->array[u].head;
        while(v)
        {
            q.back++;
            q.arr[q.back] = v->dest;
            v = v->next;
        }
    }
    printf("\n");
}
int degree(tree_t* t,int u){
    int cnt = 0;
    struct node* dummy = t->array[u].head;
    while(dummy!=NULL){
        cnt++;
        dummy = dummy->next;
    }
    return cnt; 
}
int is_root(tree_t* t,int u){
    if (u == globalroot) return 1;
    else return 0;
}
int is_leaf(tree_t* t,int u){
    struct node* dummy = t->array[u].head;
    if (dummy == NULL) return 1;
    else return 0;
}
void siblings(tree_t* t,int arg){
    queue_t q = createQueue();
    q.back++;
    q.arr[q.back] = globalroot;
    while(q.front <= q.back){
        int u = q.arr[q.front];
        q.front++;
        struct node* v = t->array[u].head;
        int arr[SIZE];
        int cnt = 0;
        while(v)
        {
            q.back++;
            q.arr[q.back] = v->dest;
            arr[cnt] = v->dest;
            cnt++;
            v = v->next;
        }
        int chk = 0;
        if(arg == globalroot) {printf("\n"); break;}
        for(int i = 0;i<cnt;i++){
            
            if(arg == arr[i]){
                chk = 1;
                 for(int j = 0;j<cnt;j++){
                     if(arg!=arr[j]) printf("%d ",arr[j]);
                 }
                 printf("\n");
            }
        }
        if (chk) break;

    }
}
void descendant(tree_t* t,int arg){
    queue_t q = createQueue();
    q.back++;
    q.arr[q.back] = arg;
    while(q.front <= q.back){
        int u = q.arr[q.front];
        q.front++;
        printf("%d ",u);
        struct node* v = t->array[u].head;
        while(v)
        {
            q.back++;
            q.arr[q.back] = v->dest;
            v = v->next;
        }
    }
    printf("\n");
}
int dfs_for_ancestor(tree_t* t,int u,int arg){
    if (u == arg) {
        return 1;
    }
    struct node* v = t->array[u].head;
    while(v)
    {
        int ch = dfs_for_ancestor(t,v->dest,arg);
        if (ch) {
            showReverse[showR] = v->dest;
            showR++;
            return 1;
        }
        v = v->next;
    }
    return 0;
}

int dfs_for_depth(tree_t* t,int u,int arg,int cnt){
     if (u == arg) {
        return cnt;
    }
    struct node* v = t->array[u].head;
    while(v)
    {
        int ch = dfs_for_depth(t,v->dest,arg,cnt+1);
        if (ch) {    
            return ch;
        }
        v = v->next;
    }
    return 0;
    
}
void ancestor(tree_t* t,int arg){
    dfs_for_ancestor(t,globalroot,arg);
    printf("%d ",globalroot);
    for (int i = showR-1;i>=0;i--){
        printf("%d ",showReverse[i]);
        showReverse[i] = 0;
    }
    showR = 0;
    printf("\n");
}
int depth(tree_t* t,int arg){
    return dfs_for_depth(t,globalroot,arg,0);
}
void print_path(tree_t* t,int from,int to){
    dfs_for_ancestor(t,from,to);
    printf("%d ",from);
    for (int i = showR-1;i>=0;i--){
        printf("%d ",showReverse[i]);
        showReverse[i] = 0;
    }
    showR = 0;
    printf("\n");
}
int path_length(tree_t* t,int from,int to){
    return dfs_for_depth(t,from,to,1);
}
void dfs_for_print(tree_t* t,int u){
    int x = depth(t,u);
    for(int i=0;i<x;i++) printf("    ");
    printf("%d\n",u);
    struct node* v = t->array[u].head;
    while(v)
    {
        dfs_for_print(t,v->dest);
        v = v->next;
    }
}
void print_tree(tree_t* t){
    dfs_for_print(t,globalroot);
}

int main(void)
{
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d %d", &parent, &child);
            t = attach(t, parent, child);
            break;
        case 2:
            scanf("%d", &node);
            t = detach(t, node);
            break;
        case 3:
            scanf("%d", &node);
            printf("%d\n", search(t, node));
            break;
        case 4:
            scanf("%d", &node);
            printf("%d\n", degree(t, node));
            break;
        case 5:
            scanf("%d", &node);
            printf("%d\n", is_root(t, node));
            break;
        case 6:
            scanf("%d", &node);
            printf("%d\n", is_leaf(t, node));
            break;
        case 7:
            scanf("%d", &node);
            siblings(t, node);
            break;
        case 8:
            scanf("%d", &node);
            printf("%d\n", depth(t, node));
            break;
        case 9:
            scanf("%d %d", &start, &end);
            print_path(t, start, end);
            break;
        case 10:
            scanf("%d %d", &start, &end);
            printf("%d\n", path_length(t, start, end));
            break;
        case 11:
            scanf("%d", &node);
            ancestor(t, node);
            break;
        case 12:
            scanf("%d", &node);
            descendant(t, node);
            break;
        case 13:
            bfs(t);
            break;
        case 14:
            dfs(t);
            break;
        case 15:
            print_tree(t);
            break;
        }
    }
    return 0;
}

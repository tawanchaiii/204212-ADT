#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int frequency;
    char word[20];
    struct node* left;
    struct node* right;
} node_t;
typedef struct heap
{
    node_t** head;
    int last_index;
} heap_t;

heap_t *init_heap(int m)
{
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
    heap->last_index = 0;
    heap->head = (node_t**)malloc(sizeof(node_t*) * (m+5));
    return heap;
}

void swap(heap_t *heap, int a, int b)
{
    node_t* temp = heap->head[a];
    heap->head[a] = heap->head[b];
    heap->head[b] = temp;
}
void check(heap_t *heap, int i)
{
    if (heap->last_index != 1)
    {
        int small, l, r;
        small = i;
        l = 2 * i + 1;
        r = 2 * i + 2;
        if (l < heap->last_index && heap->head[l]->frequency < heap->head[small]->frequency)
        {
            small = l;
        }
        if (r < heap->last_index && heap->head[r]->frequency < heap->head[small]->frequency)
        {
            small = r;
        }
        if (small != i)
        {
            swap(heap, i, small);
            check(heap, small);
        }
    }
}
void insert(heap_t *heap,char word[], int frequency)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->frequency = frequency;
    temp->left = NULL;
    temp->right = NULL;
    strcpy(temp->word,word);
    
    if (heap->last_index == 0)
    {
        heap->head[heap->last_index] = temp;
        heap->last_index++;
    }
    else
    {
        heap->head[heap->last_index] = temp;
        heap->last_index++;
        for (int i = heap->last_index / 2 - 1; i >= 0; i--)
            check(heap, i);
    }
}
node_t* delete_top(heap_t *heap)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    if (heap->last_index != 0)
    {
        temp = heap->head[0];
        swap(heap, 0, heap->last_index - 1);
        heap->head[heap->last_index-1] = NULL;
        heap->last_index -= 1;
        for (int i = heap->last_index / 2 - 1; i >= 0; i--)
            check(heap, i);
    }
    return temp;
}
void delete_2node(heap_t* heap){
    node_t* one = delete_top(heap);
    node_t* two = delete_top(heap);
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->left = one;
    temp->right = two;
    strcpy(temp->word,"$EMPTY$");
    temp->frequency = one->frequency+two->frequency;
    heap->head[heap->last_index] = temp;
    heap->last_index++;
    for (int i = heap->last_index / 2 - 1; i >= 0; i--)
        check(heap, i);
}
void dfs(node_t* head,char ans[]){
    if (head == NULL)
        return;
    char x[20];
    char y[20];
    strcpy(x,ans); strcpy(y,ans);
    strcat(x,"0"); strcat(y,"1");
    dfs(head->left,x);
    if(head->left==NULL && head->right==NULL)
        printf("%s: %s\n",head->word,ans);
    dfs(head->right,y);
}

int main(void)
{
    heap_t *heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;
    int size;
    scanf("%d", &m);
    heap = init_heap(m);
    for(int i=0;i<m;i++){
        char word[20]; 
        int frequency;
        scanf("%s %d",word,&frequency);
        insert(heap,word,frequency);
    }
    while(heap->last_index!=1){
        delete_2node(heap);
    }
    dfs(heap->head[0],"");
    return 0;
}
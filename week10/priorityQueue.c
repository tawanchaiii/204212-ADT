#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int *data;
    int last_index;
} heap_t;

heap_t *init_heap(int m)
{
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
    heap->last_index = 0;
    heap->data = (int *)malloc(sizeof(int) * 10001);
    return heap;
}

void swap(heap_t *heap, int a, int b)
{
    int temp = heap->data[a];
    heap->data[a] = heap->data[b];
    heap->data[b] = temp;
}
void check(heap_t *heap, int i)
{
    if (heap->last_index != 1)
    {
        int large, l, r;
        large = i;
        l = 2 * i + 1;
        r = 2 * i + 2;
        if (l < heap->last_index && heap->data[l] > heap->data[large])
        {
            large = l;
        }
        if (r < heap->last_index && heap->data[r] > heap->data[large])
        {
            large = r;
        }
        if (large != i)
        {
            swap(heap, i, large);
            check(heap, large);
        }
    }
}
void insert(heap_t *heap, int data)
{
    if (heap->last_index == 0)
    {
        heap->data[heap->last_index] = data;
        heap->last_index++;
    }
    else
    {
        heap->data[heap->last_index] = data;
        heap->last_index++;
        for (int i = heap->last_index / 2 - 1; i >= 0; i--)
            check(heap, i);
    }
}
int find_max(heap_t *heap)
{
    if (heap->last_index != 0)
        return heap->data[0];
    return -1;
}
void bfs(heap_t *max_heap)
{
    int cc[10000] = {0};
    int cnt = 0, i = 0;
    while (1)
    {
        int lchild = i * 2 + 1;
        int rchild = i * 2 + 2;
        if (!cc[i] && i < max_heap->last_index)
        {
            printf("%d ", max_heap->data[i]);
            cc[i] = 1;
            cnt++;
        }
        if (!cc[lchild] && lchild < max_heap->last_index)
        {
            printf("%d ", max_heap->data[lchild]);
            cc[lchild] = 1;
            cnt++;
        }
        if (!cc[rchild] && rchild < max_heap->last_index)
        {
            printf("%d ", max_heap->data[rchild]);
            cc[rchild] = 1;
            cnt++;
        }
        if (cnt == max_heap->last_index)
            break;
        i++;
    }
    printf("\n");
}
void delete_max(heap_t *heap)
{
    if (heap->last_index != 0)
    {
        swap(heap, 0, heap->last_index - 1);
        heap->last_index -= 1;
        for (int i = heap->last_index / 2 - 1; i >= 0; i--)
            check(heap, i);
    }
}
void update_key(heap_t *heap, int old_key, int new_key)
{
    for (int i = 0; i < heap->last_index; i++)
    {
        if (heap->data[i] == old_key)
        {
            heap->data[i] = new_key;
            break;
        }
    }
    for (int i = 0; i < heap->last_index; i++)
        check(heap, i);
}

int main(void)
{
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;

    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            insert(max_heap, data);
            break;
        case 2:
            delete_max(max_heap);
            break;
        case 3:
            printf("%d\n", find_max(max_heap));
            break;
        case 4:
            scanf("%d %d", &old_key, &new_key);
            update_key(max_heap, old_key, new_key);
            break;
        case 5:
            bfs(max_heap);
            break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} node_t;

node_t *push(node_t *s, char value)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->data = value;
    temp->next = NULL;
    node_t *dummy = s;
    if (dummy == NULL)
    {
        dummy = temp;
    }
    else
    {
        temp->next = dummy;
        dummy = temp;
    }
    return dummy;
}
char top(node_t *s)
{
    if (s != NULL)
        return s->data;
    else
        return 'N';
}

node_t *pop(node_t *s)
{
    if (s != NULL)
    {
        node_t *dummy = s->next;
        node_t *temp = s;
        free(s);
        return dummy;
    }
    return s;
}
int empty(node_t *s)
{
    if (s == NULL)
        return 1;
    else
        return 0;
}
int main(void)
{
    node_t *s = NULL;
    int n;
    scanf("%d", &n);
    char A[n];
    scanf("%s",A);
    for (int i = 0; i < n; i++)
    {
        if ((A[i] == ')' || A[i] == '}' || A[i] == ']') && empty(s)){
            printf("0"); return 0;
        }
        if (A[i] == '(' || A[i] == '{' || A[i] == '['){
            s = push(s,A[i]);
        }
        else if (A[i] == ')' || A[i] == '}' || A[i] == ']' && !empty(s)){
            if (A[i] == ')' && top(s) == '(') s = pop(s);
            else if (A[i] == '}' && top(s) == '{') s = pop(s);
            else if (A[i] == ']' && top(s) == '[') s = pop(s);
            else{
                printf("0"); return 0;
            }
        }
    }
    if(empty(s)) printf("1");
    else printf("0");
    return 0;
}
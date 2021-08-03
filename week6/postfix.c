#include <stdio.h>
#include <stdlib.h>
char A[1000000];
typedef struct node
{
    double data;
    struct node *next;
} node_t;

node_t *push(node_t *s, double value)
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

double top(node_t *s)
{
    if (s != NULL)
        return s->data;
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
    int n,i=0; scanf("%d",&n);
    scanf("%s",A);
    for(int i=0;i<n;i++){
        if('0'<=A[i] && A[i]<='9'){
            double temp = (double) A[i]-'0';
            s = push(s,temp);
        } 
        else{
            double b = top(s);
            s = pop(s);
            double a = top(s);
            s = pop(s);
            double result;
            if (A[i] == '+')
                result = a+b;
            else if (A[i] == '-')
                result = a-b;
            else if (A[i] == '*')
                result = a*b;
            else if (A[i] == '/')
                result = a/b;
            s = push(s,result);
        }
    }
    printf("%.2lf",top(s));
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node_t;

node_t* append(node_t** head,node_t** endNode,int x){
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->data = x;
    temp->next = NULL;
    if (*head == NULL){
        *head = temp;
        (*endNode) = *head;
    }
    else {
        (*endNode)->next = temp;
        (*endNode) = temp;
    }
    return *head;
}
void show(node_t* head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
void get(node_t* head,int x){
    int cnt = 0;
    while(head != NULL){
        if (cnt == x) printf("%d ",head->data);
        head = head->next;
        cnt++;
    }
    printf("\n");
}

node_t* reverse(node_t** head,node_t** endNode){
    int jum[100],cnt=0;
    while(*head != NULL){
        jum[cnt] = (*head)->data;
        (*head) = (*head)->next;
        cnt++;
    }
    *head = NULL; *endNode = NULL;
    for(int i = cnt-1;i>=0;i--){
        node_t* temp = (node_t*)malloc(sizeof(node_t));
        temp->data = jum[i];
        temp->next = NULL;
        if (*head == NULL){
            *head = temp;
            *endNode = *head;
        }
        else {
            (*endNode)->next = temp;
            *endNode = temp;
        }
    }
    return *head;
}

node_t* cut(node_t** head,node_t** endNode,int x,int y){
    for(int i = 0;i<x;i++) (*head) = (*head)->next;
    (*endNode) = (*head);
    for(int i = x+1;i<=y;i++) (*endNode) = (*endNode)->next;
    (*endNode)->next = NULL;
    return *head;
}

int main(void){
    node_t* startNode;
    node_t* endNode;
    int n,x,y;
    char command;
    startNode = NULL; endNode = NULL;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf(" %c",&command);
        if (command != 'S' && command != 'R') {
            scanf(" %d",&x);
            if (command == 'C') scanf(" %d",&y);
        }
        switch (command)
        {
        case 'A':
            startNode = append(&startNode,&endNode,x);
            break;
        case 'G':
            get(startNode,x);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(&startNode,&endNode);
            break;
        case 'C':
            startNode = cut(&startNode,&endNode,x,y);
            break;
        default:
            break;
        }
    }
}

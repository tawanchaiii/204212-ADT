#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node_t;

node_t* append(node_t* head){
    int x; scanf("%d",&x);
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    node_t* dummy = head;
    temp->data = x;
    temp->next = NULL;
    if (dummy == NULL){
        dummy = temp;
    }
    else {
        while(dummy->next!=NULL) dummy = dummy->next;
        dummy->next = temp;
        dummy = head;
    }
    return dummy;
}
void show(node_t* head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
void get(node_t* head){
    int x; scanf("%d",&x);
    int cnt = 0;
    while(head != NULL){
        if (cnt == x) printf("%d ",head->data);
        head = head->next;
        cnt++;
    }
    printf("\n");
}

node_t* reverse(node_t* dummy){
    node_t* head = dummy;
    int jum[100],cnt=0;
    while(head != NULL){
        jum[cnt] = head->data;
        node_t* tmp = head;
        head = head->next;
        free(tmp);
        cnt++;
    }
    head = NULL;
    for(int i = cnt-1;i>=0;i--){
        node_t* temp = (node_t*)malloc(sizeof(node_t));
        temp->data = jum[i];
        temp->next = NULL;
        if (head == NULL){
            head = temp;
            dummy = head;
        }
        else {
            head->next = temp;
            head = temp;
        }
    }   
    head = dummy;
    return head;
}

node_t* cut(node_t* head){
    int x,y; scanf("%d %d",&x,&y);
    for(int i = 0;i<x;i++) head = head->next;
    node_t* temp = head;
    for(int i = x+1;i<=y;i++) temp = temp->next;
    temp->next = NULL;
    return head;
}

int main(void){
    node_t* startNode = NULL;
    int n,x,y;
    char command;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf(" %c",&command);
        switch (command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        default:
            break;
        }
    }
    return 0;
}

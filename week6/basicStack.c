#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
}node_t;

typedef node_t stack_t;

node_t* push(node_t* s,int value){
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->data = value;
    temp->next = NULL;
    node_t* dummy = s;
    if (dummy == NULL) {
        dummy = temp;
    }
    else{
        temp->next = dummy;
        dummy = temp;
    }
    return dummy;
}

void top(node_t* s){
    if(s!=NULL) printf("%d\n",s->data);
    else printf("Stack is empty.\n");
}

node_t* pop(node_t* s){
    if(s!=NULL){
        node_t* dummy = s->next;
        node_t* temp = s;
        free(s);
        return dummy;
    } 
    return s;
    
}
void empty(node_t* s){
    if (s==NULL) printf("Stack is empty.\n");
    else printf("Stack is not empty.\n");
}

void size(node_t* s){
    int cnt = 0;
    while(s!=NULL){
        cnt++;
        s = s->next;
    } 
    printf("%d\n",cnt);
}
int main(void) {
  node_t *s = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        break;
      case 2:
        top(s);
        break;
      case 3:
        s = pop(s);
        break;
      case 4:
        empty(s);
        break;
      case 5:
        size(s);
        break;
      }
  }
  return 0;
}
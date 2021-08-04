#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
}node_t;

typedef node_t stack_t;

stack_t* push(stack_t* s,int value){
    stack_t* temp = (stack_t*)malloc(sizeof(stack_t));
    temp->data = value;
    temp->next = NULL;
    stack_t* dummy = s;
    if (dummy == NULL) {
        dummy = temp;
    }
    else{
        temp->next = dummy;
        dummy = temp;
    }
    return dummy;
}

void top(stack_t* s){
    if(s!=NULL) printf("%d\n",s->data);
    else printf("Stack is empty.\n");
}

stack_t* pop(stack_t* s){
    if(s!=NULL){
        stack_t* dummy = s->next;
        stack_t* temp = s;
        free(s);
        return dummy;
    } 
    return s;
    
}
void empty(stack_t* s){
    if (s==NULL) printf("Stack is empty.\n");
    else printf("Stack is not empty.\n");
}

void size(stack_t* s){
    int cnt = 0;
    while(s!=NULL){
        cnt++;
        s = s->next;
    } 
    printf("%d\n",cnt);
}
int main(void) {
  stack_t *s = NULL;
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
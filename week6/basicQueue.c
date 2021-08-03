#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t queue_t;
typedef struct queue {
  int          data;
  struct node *next;
} queue_tt;
node_t* enqueue(node_t* q,int value){
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->data = value;
    temp->next = NULL;
    node_t* dummy = q;
    if (dummy == NULL) {
        dummy = temp;
    }
    else{
        temp->next = dummy;
        dummy = temp;
    }
    return dummy;
}

int main(void) {
  node_t *q = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;
    }
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node_t;

typedef node_t queue_t;
queue_t *enqueue(queue_t *q, int value)
{
  queue_t *temp = (queue_t *)malloc(sizeof(queue_t));
  temp->data = value;
  temp->next = NULL;
  queue_t *dummy = q;
  if (dummy == NULL)
  {
    dummy = temp;
  }
  else
  {
    while (dummy->next != NULL)
    {
      dummy = dummy->next;
    }
    dummy->next = temp;
    dummy = q;
  }
  return dummy;
}

queue_t *dequeue(queue_t *q)
{
  queue_t *dummy = q;
  if (dummy == NULL)
  {
    printf("Queue is empty.\n");
    return dummy;
  }
  else
    printf("%d\n",dummy->data);
    dummy = dummy->next;
  return dummy;
}
void show(queue_t *q)
{
  if (q == NULL)
    printf("Queue is empty.\n");
  else
  {
    while (q != NULL)
    {
      printf("%d ", q->data);
      q = q->next;
    }
    printf("\n");
  }
}

void empty(queue_t *q)
{
  if (q == NULL)
  {
    printf("Queue is empty.\n");
  }
  else
    printf("Queue is not empty.\n");
}

void size(queue_t *q)
{
  int cnt = 0;
  while (q != NULL)
  {
    cnt++;
    q = q->next;
  }
  printf("%d\n", cnt);
}

int main(void)
{
  queue_t *q = NULL;
  int n, i, command, value;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &command);
    switch (command)
    {
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
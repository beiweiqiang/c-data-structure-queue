#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <stdbool.h>
#define MAX_QUEUE 10

typedef int Item;

typedef struct node {
  Item item;
  struct node * next;
} Node;

typedef struct queue {
  Node * front;
  Node * rear;
  int items;
} Queue;

void initialize_queue(Queue * pq);
bool queue_is_full(const Queue * pq);
bool queue_is_empty(const Queue * pq);
int queue_item_count(const Queue * pq);
bool en_queue(Item item, Queue * pq);
bool de_queue(Item * pItem, Queue * pq);
void empty_the_queue(Queue * pq);

#endif //QUEUE_QUEUE_H

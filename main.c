#include <stdio.h>
#include "./include/queue.h"

int main() {
  Queue q;
  Item item = 1;

  initialize_queue(&q);
  printf("%d \n", queue_item_count(&q));

  en_queue(item, &q);
  en_queue(item, &q);

  Item de_item;
  de_queue(&de_item, &q);
  printf("%d \n", de_item);

  empty_the_queue(&q);
  printf("%d \n", queue_item_count(&q));

  return 0;
}
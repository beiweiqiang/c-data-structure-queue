
#include <stdlib.h>
#include "../include/queue.h"

void cp_to_node(Item item, Node * pn);
void cp_to_item(Node * pn, Item * item);

void initialize_queue(Queue * pq) {
  pq->front = pq->rear = NULL;
  pq->items = 0;
}

bool queue_is_full(const Queue * pq) {
  return pq->items == MAX_QUEUE;
}

bool queue_is_empty(const Queue * pq) {
  return pq->items == 0;
}

int queue_item_count(const Queue * pq) {
  return pq->items;
}

/**
 * 1 创建一个新节点
 * 2 把 item 拷贝到节点中
 * 3 设置节点的 next 指针为 NULL
 * 4 把当前末尾节点的 next 指针指向新节点
 * 5 把 rear 指针指向新节点
 * 6 项数加 1
 *
 * @param item
 * @param pq
 * @return
 */
bool en_queue(Item item, Queue * pq) {
  Node * pnew;

  if (queue_is_full(pq)) {
    return false;
  }

  pnew = (Node *) malloc(sizeof(Node));
  if (pnew == NULL) {
    exit(1);
  }

  cp_to_node(item, pnew);
  pnew->next = NULL;

  if (queue_is_empty(pq)) {
    pq->front = pnew;
  } else {
    pq->rear->next = pnew;
  }

  pq->rear = pnew;
  pq->items++;

  return true;
}

/**
 * 1 把项拷贝到给定的变量中
 * 2 释放空出的节点内存
 * 3 重置首指针, 指向队列的下一个节点
 * 4 如果删除了最后一项, 把首指针和尾指针指向 NULL
 * 5 项数减 1
 *
 * @param pItem
 * @param pq
 * @return
 */
bool de_queue(Item * pItem, Queue * pq) {
  Node * pt;

  if (queue_is_empty(pq)) {
    return false;
  }
  cp_to_item(pq->front, pItem);

  // 先把 front 留下来
  pt = pq->front;
  // 重置 front
  pq->front = pq->front->next;
  free(pt);

  pq->items--;

  // 检查队列是否为空
  if (pq->items == 0) {
    pq->rear = NULL;
  }
  return true;
}

void empty_the_queue(Queue * pq) {
  Item dummy;
  while (!queue_is_empty(pq)) {
    de_queue(&dummy, pq);
  }
}

void cp_to_node(Item item, Node * pn) {
  pn->item = item;
}
void cp_to_item(Node * pn, Item * item) {
  *item = pn->item;
}


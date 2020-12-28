//Vibishan WIgneswaran
//5/1/2019
//time:3 hours
//purpose: create priority queue
#include "priority_queue.h"
#include "priority_queue.c"
#include <stdio.h>

int main(int argc, char* argv[]) {
  struct priority_queue hQueue;
  priority_queue_init_default(hQueue);
  priority_queue_insert(&hQueue, 2);
  priority_queue_insert(&hQueue, 4);
  priority_queue_insert(&hQueue, 6);
  priority_queue_is_empty(&hQueue);
  return 0;
}

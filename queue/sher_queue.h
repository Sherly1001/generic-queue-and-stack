#ifndef __sher_queue__
#define __sher_queue__

#include <stdlib.h>

typedef struct node_q {
    void *data;
    struct node_q *next;
} node_q;

typedef struct queue {
    node_q *first;
    node_q *last;
} queue_t;

void *q_copy_data(void *data); // user define to make a copy of data
void q_free_data(void *data); // user define to free a data
void *q_enqueue(queue_t *q, void *data);
void *q_dequeue(queue_t *q);

#endif
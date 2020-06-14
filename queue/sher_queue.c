#include "sher_queue.h"


void *q_enqueue(queue_t *q, void *data) {
    q->last = *(q->first ? &q->last->next : &q->first) = malloc(sizeof(node_q));

    q->last->data = q_copy_data(data);
    q->last->next = NULL;

    return q->last->data;
}

void *q_dequeue(queue_t *q) {
    if (q == NULL) return NULL;

    node_q *pop = q->first;
    void *data = pop ? pop->data : NULL;

    if (pop) {
        q->first = pop->next;
        free(pop);
    }

    return data;
}
#include "sher_pqueue.h"


void *pq_enqueue(pqueue_t *q, void *data, int priority) {
    q->last = *(q->first ? &q->last->next : &q->first) = malloc(sizeof(node_pq));

    q->last->data = pq_copy_data(data);
    q->last->priority = priority;
    q->last->next = NULL;

    return q->last->data;
}

void *pq_dequeue(pqueue_t *q) {
    if (q == NULL) return NULL;

    node_pq *pop = q->first, *pre = NULL;
    void *data = NULL;

    for (node_pq *cur = pop->next; cur; cur = cur->next) {
        if (cur && cur->priority > pop->priority) {
            pre = pop;
            pop = cur;
        }
    }

    if (pop) {
        data = pop->data;
        *(pre ? &pre->next : &q->first) = pop->next;

        free(pop);
    }

    return data;
}
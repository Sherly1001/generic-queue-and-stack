#include <stdio.h>
#include <string.h>
#include "sher_pqueue.h"

void *pq_copy_data(void *data) {
    char *s = malloc(50 * sizeof(char));
    strcpy(s, data);

    return s;
}

void pq_free_data(void *data) {
    free(data);
}

int main() {
    pqueue_t q = {0};

    pq_enqueue(&q, "Sherly", 1);
    pq_enqueue(&q, "Hi ", 7);
    pq_enqueue(&q, "1001", 1);

    while (q.first) {
        char *s = pq_dequeue(&q);
        printf("%s", s);
        pq_free_data(s);
    }
}
#include <stdio.h>
#include <string.h>
#include "sher_queue.h"

void *q_copy_data(void *data) {
    char *s = malloc(50 * sizeof(char));
    strcpy(s, data);

    return s;
}

void q_free_data(void *data) {
    free(data);
}

int main() {
    queue_t q = {0};

    q_enqueue(&q, "Sherly");
    q_enqueue(&q, "Hi ");
    q_enqueue(&q, "1001");

    while (q.first) {
        char *s = q_dequeue(&q);
        printf("%s", s);
        q_free_data(s);
    }
}
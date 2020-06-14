#include "sher_stack.h"


void *st_push(stack_t *st, void *data) {
    node_st *new = malloc(sizeof(node_st));
    new->data = st_copy_data(data);
    new->next = st->last;

    st->last = new;
    if (!st->first) st->first = new;

    return new->data;
}

void *st_pop(stack_t *st) {
    if (st->last) {
        node_st *pop = st->last;
        void *data = pop->data;

        if (st->first == st->last) st->first = st->last = NULL;
        st->last = pop->next;
        free(pop);

        return data;
    } else return NULL;
}
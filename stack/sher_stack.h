#ifndef __sher_stack__
#define __sher_stack__

#include <stdlib.h>

typedef struct node_st {
    void *data;
    struct node_st *next;
} node_st;

typedef struct stack {
    node_st *first;
    node_st *last;
} stack_t;


void *st_copy_data(void *data);
void st_free_data(void *data);
void *st_push(stack_t *st, void *data);
void *st_pop(stack_t *st);

#endif
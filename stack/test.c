#include <stdio.h>
#include <string.h>
#include "sher_stack.h"

void *st_copy_data(void *data) {
    char *s = malloc(50 * sizeof(char));
    strcpy(s, data);
    return s;
}

void st_free_data(void *data) {
    free(data);
}

int main() {
    stack_t st = {0};

    st_push(&st, "Hi");
    st_push(&st, "Sherly ");
    st_push(&st, "1001 ");

    while (st.first) {
        char *s = st_pop(&st);
        printf("%s", s);
        st_free_data(s);
    }
}
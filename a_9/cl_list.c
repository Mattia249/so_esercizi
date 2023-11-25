#include <stdio.h>
#include "cl_list.h"

list_cl l_add_cl(list_cl l, client p) {
    l_node *next = {1, p, NULL};
    
    l_node *tail = l.tail;
    tail->next = next;

    return l;
}


/*
list_cl l_rem_cl(list_cl l, client *p);
int l_is_empty(list_cl l);
list_cl l_clear(list_cl l);
 int l_length(list_cl l);
*/
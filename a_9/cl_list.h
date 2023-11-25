#include "./client.h"

typedef struct _node {
    unsigned int id;
    client person;
    struct _node *next;
} l_node;

typedef struct {
    l_node *head;
    l_node *tail;
} list_cl;


list_cl l_add_cl(list_cl l, client p);
list_cl l_rem_cl(list_cl l, client *p);
int l_is_empty(list_cl l);
list_cl l_clear(list_cl l);
int l_length(list_cl l);

#define L_EMPTYLIST_CL {NULL,NULL}
#include "functions.h"

#ifndef LIST_H
#define LIST_H

typedef struct list {
	fct_adr fct;
	struct list *next;
} *p_list, **dp_list;

void add(dp_list, fct_adr);
void alloc(dp_list);
void destroy(dp_list);
size_t list_size(dp_list);

#endif /* FUNCTION_H */

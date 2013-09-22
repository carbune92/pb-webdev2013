#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void allocate_mem (dp_list node, fct_adr f) {
	*node = malloc(sizeof(struct list));

	if(*node != NULL) {
		(*node)->fct = f;
		(*node)->next = NULL;
	} else {
		printf("Error allocating\n");
		exit(1);
	}
}

void add (dp_list start, fct_adr f) {
	p_list node;
	dp_list p;

	allocate_mem(&node, f);

	for(p = start; *p; p = &(*p)->next);
	*p = node;

}

void destroy (dp_list start) {
	for(; *start; start=&(*start)->next)
		free(*start);
}

size_t list_size (dp_list start) {
	size_t dim = 0;

	for(; *start; start=&(*start)->next)
		dim++;
	
	return dim;
}	

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "functions.h"
#include "list.h"

/* Primeste ca parametrii x si un numar variabil de pointeri la functii */
ret* modify_x(param x, ...);

/* Primeste ca parametrii x si o lista de pointeri la functii */
ret* modify_x_list(param x, dp_list functions);

/* Verificarea progr cu modify_x */
void check_1();

/* Verificarea progr cu modify_x_list */
void check_2();

/* Main */
int main() {
	check_1();
	check_2();
	return 0;
}

/* Modify_x */
ret* modify_x(param x, ...) {
	
	va_list arg;
	fct_adr f;
	ret* res;
	size_t dim = 0;
	size_t i = 0;

	va_start(arg, x);
	while((f = va_arg(arg, fct_adr)) != NULL) {	
		dim++;
	}
	
	res = malloc(dim*sizeof(ret));

	va_start(arg, x);
	while((f = va_arg(arg, fct_adr)) != NULL && i < dim) {	
		res[i++] = (*f)(x);
	}

	va_end(arg);
	return res;
}
/* Modify_x_list  */
ret* modify_x_list(param x, dp_list functions) {
	
	ret *res;
	size_t dim = 0;
	size_t i = 0;
	dp_list p;

	for(p = functions; *p; p = &(*p)->next)
		dim++;

	res = malloc(dim*sizeof(ret));

	for(p = functions; *p; p = &(*p)->next) {
		fct_adr f = (*p)->fct;
		res[i++] = (*f)(x);
	}

	return res;
}
/* Check_1 */
void check_1() {

	ret *result;

	printf("Argumente variabile:\n");

	printf("\tExemplul 1: ");
	result = modify_x(5, add_one, multiply_by_two, NULL);
	for( ; *result; result++) printf("%d ", *result);
	printf("\n\n");

	printf("\tExemplul 2: ");
	result = modify_x(4, divide_by_four, add_one, multiply_by_two, substract_three, NULL);
	for( ; *result; result++) printf("%d ", *result);
	printf("\n\n");

	printf("\tExemplul 3: ");
	result = modify_x(34, NULL);
	for( ; *result; result++) printf("%d ", *result);
	printf("\n\n");
}

/* Check_2 */
void check_2() {

	ret* result;	
	p_list lista1, lista2, lista3;	
	result = NULL;
	lista1 = lista2 = lista3 = NULL;
	
	printf("Lista de functii:\n");

	printf("\tExemplul 1: ");

	add(&lista1, add_one);
	add(&lista1, multiply_by_two);
	result = modify_x_list(5, &lista1);

	if(list_size(&lista1))
		for( ; *result; result++) printf("%d ", *result);

	if(lista1 != NULL) 
		destroy(&lista1);
	printf("\n\n");
	

	printf("\tExemplul 2: ");

	add(&lista2, divide_by_four);
	add(&lista2, add_one);
	add(&lista2, multiply_by_two);
	add(&lista2, substract_three);
	result = modify_x_list(4, &lista2);

	if(list_size(&lista2))
		for( ; *result; result++) printf("%d ", *result);

	if(lista2 != NULL) 
		destroy(&lista2);
	printf("\n\n");
	

	printf("\tExemplul 3: ");

	result = modify_x_list(34, &lista3);

	if(list_size(&lista3))
		for( ; *result; result++) printf("%d ", *result);

	if(lista3 != NULL) 
		destroy(&lista3);
	printf("\n\n");
}

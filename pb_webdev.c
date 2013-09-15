#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "functions.h"

/* Primeste ca parametrii x si o lista variabila de pointeri la functii */
ret* modify_x(param x, ...);

/* Verificarea progr */
void check();

/* Main */
int main() {
	check();
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

void check() {

	ret *result;

	printf("Exemplul 1: ");
	result = modify_x(5, add_one, multiply_by_two, NULL);
	for( ; *result; result++) printf("%d ", *result);
	printf("\n\n");

	printf("Exemplul 2: ");
	result = modify_x(4, divide_by_four, add_one, multiply_by_two, substract_three, NULL);
	for( ; *result; result++) printf("%d ", *result);
	printf("\n\n");

	printf("Exemplul 3: ");
	result = modify_x(34, NULL);
	for( ; *result; result++) printf("%d ", *result);
	printf("\n\n");
}

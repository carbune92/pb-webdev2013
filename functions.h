#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef int param;
typedef int ret;

/* Definirea var 'fct_adr' ca pointer la o functie de tipul 'ret' ce returneaza tipul 'param' */
typedef ret (*fct_adr)(param);

ret add_one(param);
ret multiply_by_two(param);
ret substract_three(param);
ret divide_by_four(param);

#endif /* FUNCTIONS_H */

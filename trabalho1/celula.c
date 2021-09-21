#include "celula.h"
#include <stdlib.h>
#include <stdio.h>

Cell *create_cell(int numero)
{
	Cell *a;
	a=malloc(sizeof(Cell));
	a->num=numero;
	a->proximo=NULL;
	return a;
}
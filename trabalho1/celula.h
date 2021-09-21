#ifndef __celula_h_
#define __celula_h_
//EX2
typedef struct celula
{
	int num;
	struct celula *proximo;
}Cell;

Cell *create_cell(int numero);
#endif
#ifndef __list_h_
#define __list_h_
//EX1
typedef struct no
{
	int num;
	struct no *proximo;
}Cell;
//EX2
typedef struct lista
{
	int tam;
	Cell *primeiro,*ultimo;
}List;

List *create_list();
Cell *create_cell(int info);
List *insert_first(List *lst,int info);
void print_cell(Cell *c);
void print_list(List *lst);
void free_cell(Cell *a);
void free_list(List *lst);
#endif
#ifndef __list_h_
#define __list_h_
//EX1-1
typedef struct no
{
	int num;
	struct no *proximo;
}Cell;
//EX2-1
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
int size_list(List *lst);
int search(List *lst, int info);
List *insert_last(List *lst,int info);
List *insert_list(List *lst,int info,int pos);
void remover(List* lst, int pos);
void seek_destroy(List* lst,int info);
void insert_ord(List *lst,int info);
#endif
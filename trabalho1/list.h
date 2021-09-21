#ifndef __list_h_
#define __list_h_
//EX1
typedef struct lista
{
	int tamanho;
	struct celula *primeiro;
	struct celula *ultimo;
}List;
//EX3_A
List* create_list();
//EX3_B
int size_list(List *lst);
//EX3_C
void insert_list(List *lst,int info, int pos);
//EX3_D
void remove_list(List*lst,int pos);
//EX3_E
void print_list(List *lst);
//EX3_F
void free_list(List *lst);
#endif
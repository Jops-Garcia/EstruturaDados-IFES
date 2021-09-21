#include "list.h"
#include <stdlib.h>
#include <stdio.h>
//EX3
List *create_list()
{
	List *lst;
	//alocando 
	lst=malloc(sizeof(List));
	//vazio
	lst->primeiro=NULL;
	lst->ultimo=NULL;
	
	return lst;
}
//EX4
Cell *create_cell(int info)
{
	Cell *a;
	a=malloc(sizeof(Cell));
	a->num=info;
	a->proximo=NULL;
	return a;
}
//EX5
List *insert_first(List *lst,int info)
{
	Cell *c,*aux;
	c=create_cell(info);
	aux=lst->primeiro;
	c->proximo=aux;
	lst->primeiro=c;
	return lst;
}


//EX6
void print_cell(Cell *c)
{
	printf("%d, ",c->num);
}

//EX7
void print_list(List *lst)
{
	Cell *test;
	test=lst->primeiro;
	while (test->proximo!=NULL)
	{
		print_cell(test);
		test=test->proximo;
	}
}
//ex8
void free_cell(Cell *a)
{
	free(a);
}
//ex9
void free_list(List *lst)
{
	Cell *aux,*aux3,*aux2;
	aux=lst->primeiro;
	aux3=lst->ultimo;
	while (aux->proximo!=aux3)
	{
		aux2=aux;
		free(aux2);
		aux=aux->proximo;
	}
	free(aux3);
	free(lst);
}

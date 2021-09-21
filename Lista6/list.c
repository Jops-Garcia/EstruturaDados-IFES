#include "list.h"
#include <stdlib.h>
#include <stdio.h>
//EX3-1
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
//EX4-1
Cell *create_cell(int info)
{
	Cell *a;
	a=malloc(sizeof(Cell));
	a->num=info;
	a->proximo=NULL;
	return a;
}
//EX5-1
List *insert_first(List *lst,int info)
{
	Cell *c,*aux;
	c=create_cell(info);
	if(lst->primeiro==NULL)
	{
		lst->primeiro=c;
		lst->ultimo=c;
		return lst;
	}
	aux=lst->primeiro;
	c->proximo=aux;
	lst->primeiro=c;
	return lst;
}
//EX6-1
void print_cell(Cell *c)
{
	printf("%d, ",c->num);
}
//EX7-1
void print_list(List *lst)
{
	Cell *test;
	test=lst->primeiro;
	while (test->proximo!=NULL)
	{
		print_cell(test);
		test=test->proximo;
	}
	print_cell(test);
}
//ex8-1
void free_cell(Cell *a)
{
	free(a);
}
//ex9-1
void free_list(List *lst)
{
	Cell *aux,*aux3,*aux2;
	aux=lst->primeiro;
	aux3=lst->ultimo;
	while (aux->proximo!=aux3)
	{
		aux2=aux->proximo;
		free(aux);
		aux=aux2;
	}
	free(aux);
	free(aux3);
	free(lst);
}
//EX1-2
int size_list(List *lst)
{
	Cell *auxiliar;
	int cont;
	cont =0;
	auxiliar=lst->primeiro;
	while(auxiliar->proximo!=NULL)
	{
		cont++;
		auxiliar=auxiliar->proximo;
	}
	cont++;
	return cont;
}
//EX2-2
int search(List *lst, int info)
{
	if (lst->primeiro==NULL)
	{
		return -1;
	}
	Cell *aux,*aux2;
	int cont;
	cont=0;
	aux=create_cell(info);
	aux2=lst->primeiro;
	while(aux2->proximo!=NULL)
	{
		cont++;
		if (aux2->num==aux->num)
		{
			free(aux);
			return cont;
		}
		aux2=aux2->proximo;
	}
	cont++;
	if (aux2->num==aux->num)
		{
			free(aux);
			return cont;
		}
	free(aux);
	return -1;
}
//EX3-2
List *insert_last(List *lst,int info)
{
	Cell *c,*aux;
	c=create_cell(info);
	if(lst->ultimo==NULL)
	{
		lst->primeiro=c;
		lst->ultimo=c;
		return lst;
	}
	aux=lst->ultimo;
	aux->proximo=c;
	lst->ultimo=c;
	return lst;
}
//EX4-2
List *insert_list(List *lst,int info,int pos)
{
	if(pos<=0 || pos==1)
	{
		lst=insert_first(lst,info);
		return lst;
	}
	if(pos>=size_list(lst))
	{
		lst=insert_last(lst,info);
		return lst;
	}
	int cont;
	Cell *aux,*aux2,*novo;
	novo=create_cell(info);
	aux=lst->primeiro;
	cont=pos;
	while(cont!=2)
	{
		aux=aux->proximo;
		cont--;
	}
	aux2=aux->proximo;
	aux->proximo=novo;
	novo->proximo=aux2;
	return lst;
}
//EX6-2
void remover(List* lst, int pos)
{
	if(pos<=0 || pos==1)
	{
		Cell *c,*aux;
		if(lst->primeiro==NULL)
		{
			return;
		}
		aux=lst->primeiro;
		c=aux->proximo;
		free(aux);
		lst->primeiro=c;
		return;
	}
	if(pos>=size_list(lst))
	{
		Cell *c,*aux;
		if(lst->ultimo==NULL)
		{
			return;
		}
		c=lst->primeiro;
		aux=lst->ultimo;
		while (c->proximo!=aux)
		{
			c=c->proximo;
		}
		c->proximo=NULL;
		lst->ultimo=c;
		free(aux);
		return;
	}
	int cont;
	Cell *aux,*aux2;
	aux=lst->primeiro;
	cont=pos;
	while(cont!=2)
	{
		aux=aux->proximo;
		cont--;
	}
	aux2=aux->proximo;
	aux->proximo=aux2->proximo;
	free(aux2);
}
//EX7-2
void seek_destroy(List* lst,int info)
{
	remover(lst,search(lst,info));
}
//EX8-2
void insert_ord(List *lst,int info)
{
	if(lst->primeiro==NULL)
	{
		insert_list(lst,info,0);
		return;
	}
	
	Cell *aux,*aux2;
	int cont;
	aux2=lst->ultimo;
	if(aux2->num<=info)
	{
		insert_list(lst,info,size_list(lst));
		return;
	}
	aux=lst->primeiro;
	if (aux->num>=info)
	{
		insert_list(lst,info,0);
		return;
	}
	cont=2;
	while(aux->proximo!=NULL)
	{
		aux=aux->proximo;
		if(aux->num>info)
		{
			insert_list(lst,info,cont);
			return;
		}
		cont++;
	}
}
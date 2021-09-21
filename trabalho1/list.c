#include "list.h"
#include "celula.h"
#include <stdlib.h>
#include <stdio.h>
//EX3_A
List* create_list()
{
	List *lista;
	//alocando memoria
	lista=malloc(sizeof(List));
	lista->tamanho=0;
	//iniciando uma lista vazia
	lista->primeiro=NULL;
	lista->ultimo=NULL;
	
	return lista;
}
//EX3_B
int size_list(List *lst)
{
	//criando uma auxiliar para percorrer
	Cell *aux1;
	int tam;
	tam=0;
	//caso lista vazia
	if (lst->primeiro==NULL)
	{
		return tam;
	}
	//recebendo a primeira celula
	aux1=lst->primeiro;
	//percorrendo a lista com o contador
	while (aux1!=lst->ultimo)
	{
		tam++;
		aux1=aux1->proximo;
	}
	tam++;
	return tam;
}
//EX3_C
void insert_list(List *lst,int info, int pos)
{
	//criando celula para receber info
	Cell *no;
	no=create_cell(info);
	//celulas para guardar celulas existentes
	Cell *aux,*aux2;
	//conferindo o tamanho da lista
	lst->tamanho=size_list(lst);
	//adicionando em primeiro
	if (pos<=1)
	{
		aux=lst->primeiro;
		lst->primeiro=no;
		no->proximo=aux;
		lst->tamanho++;
		return;
		
	}
	//adicionando em ultimo
	if (pos>lst->tamanho-1)
	{
		aux=lst->ultimo;
		aux->proximo=no;
		lst->ultimo=no;
		no->proximo=NULL;
		lst->tamanho++;
		return;
	}
	else
	{
		aux=lst->primeiro;
		//loop para achar a posicao na lista
		while (pos!=1)
		{
			aux=aux->proximo;
			pos--;
		}
		aux2=aux->proximo;
		aux->proximo=no;
		no->proximo=aux2;
		return;
	}
}
//EX3_D
void remove_list(List*lst,int pos)
{
	//conferindo o tamanho da lista
	lst->tamanho=size_list(lst);
	//caso nao exista posicao
	if (pos>lst->tamanho || pos<1)
	{
		printf("Posicao nao encontrada\n");
		return;
	}
	Cell *aux3,*aux4;
	aux3=lst->primeiro;
	//caso seja o primeiro
	if (pos==1)
	{
		aux4=lst->primeiro;
		lst->primeiro=aux4->proximo;
		free(aux4);
		return;
	}
	//caso seja o ultimo elemento
	if (pos==lst->tamanho)
	{
		aux3=lst->primeiro;
		//loop para pegar info do antepenultimo
		while(aux3->proximo!=lst->ultimo)
		{
			aux3=aux3->proximo;
		}
		aux3->proximo=NULL;
		free(lst->ultimo);
		lst->ultimo=aux3;
		return;
	}
	//loop ate chegar na posicao desejada
	while(pos!=1)
	{
		aux3=aux3->proximo;
		pos--;
	}
	aux4=aux3->proximo;
	aux3->proximo=aux4->proximo;
	
	free(aux4);
}
//EX3_E
void print_list(List *lst)
{
    Cell *aux5;
	aux5=lst->primeiro;
	printf("\nA lista eh: ");
	//loop percorrendo e printando a lista
    while(aux5!=lst->ultimo)
	{
        printf("%d, ", aux5->num);
        aux5=aux5->proximo;
    }
	printf("%d ", aux5->num);
}
//EX3_F
void free_list(List *lst)
{
	Cell *aux6,*aux7;
	/*int cont;
	cont=lst->tam;
	lista=lst;
	aux6=lst->primeiro;
	prox=aux6->proximo;
	free(aux6);*/
	aux6=lst->primeiro;
	while(aux6->proximo!=NULL)
	{
		aux7=aux6;
		aux6=aux6->proximo;
		free(aux7);	
	}
	free(lst);
}
#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
//cria discos para inserir na pilha
Disco *create_disk(info_t num)
{
	Disco *a;
	a=malloc(sizeof(Disco));
	a->posicao=num;
	a->proximo=NULL;
	return a;
}
//1 cria uma pilha vazia
Pilha *create_pilha()
{
	Pilha *b;
	b=malloc(sizeof(Pilha));
	b->topo=NULL;
	return b;
}
//liberando memoria alocada em uma pilha  e seus discos
void free_pilha(Pilha *p)
{
	Disco *aux,*aux2;
	if (p->topo==NULL)
	{
		free(p);
		return;
	}
	aux=p->topo;
	while(aux->proximo!=NULL)
	{
		aux2=aux;
		aux=aux->proximo;
		free(aux2);
	}
	free(aux);
	free(p);
}
//2 retorna o tamanho da pilha
info_t size(Pilha *p)
{
	info_t cont;
	Disco *aux8;
	//pilha vazia
	cont=0;
	if (p->topo==NULL)
	{
		return cont;
	}
	aux8=p->topo;
	//percorrendo e contando elementos
	while (aux8->proximo!=NULL)
	{
		cont++;
		aux8=aux8->proximo;
	}
	cont++;
	return cont;
}
//3 inserir um elemento no topo da pilha
void push(info_t num, Pilha *p)
{
	Disco *aux3,*aux4;

	//disco que será inserido
	aux3=create_disk(num);
	aux4=p->topo;
	p->topo=aux3;
	aux3->proximo=aux4;
}
//4 remove um elemento do topo da lista e retorna o numero para criar o disco em outra pilha
info_t pop(Pilha *p)
{
	info_t num;
	Disco *aux6,*aux9;
	aux6=p->topo;
	if (aux6->proximo!=NULL)
	{
		aux9=aux6->proximo;
		p->topo=aux9;
		num=aux6->posicao;
		free(aux6);
		return num;
	}
	num=aux6->posicao;
	p->topo=NULL;
	return num;
}
//5 retorna o elemento do topo da lista
info_t peek(Pilha *p)
{
	info_t num;
	Disco *aux7;
	aux7=p->topo;
	num=aux7->posicao;
	return num;
}
//6 print uma pilha
void print(Pilha *p)
{
	Disco *aux5;
	//pilha vazia
	if (p->topo==NULL)
	{
		return;
	}
	aux5=p->topo;
	//percorrendo e printando elementos
	while (aux5->proximo!=NULL)
	{
		printf(" %d", aux5->posicao);
		aux5=aux5->proximo;
	}
	printf(" %d", aux5->posicao);
}
//funcao para printar os movimentos necessarios para solucao
void moves(info_t num,char origem,char destino,char auxiliar)
{
	//quando sobra 1 disco
	if (num==1)
	{ 
		printf("Mova o disco 1 da pilha %c para a pilha %c \n",origem ,destino);
		return;
	}
	//movendo disco num-1 de A para B, usando C de aux
	moves(num-1,origem,auxiliar,destino);
	//movendo os discos restantes de A para C
	printf("Mova o disco %d da pilha %c para a pilha %c \n",num,origem,destino);
	//movendo num-1 discos de B para C usando A como aux
	moves(num-1,auxiliar,destino,origem);
}
//funcao para resolver o problema da torre de hanoi seguindo a mesma ideia do print
void solve(info_t num, Pilha *origem,Pilha *destino, Pilha *auxiliar)
{

	if (num==1)
	{ 
		push(pop(origem),destino);
		return;
	}
	//movendo disco num-1 de A para B, usando C de aux
	solve(num-1,origem,auxiliar,destino);
	//movendo os discos restantes de A para C
	push(pop(origem),destino);
	//movendo num-1 discos de B para C usando A como aux
	solve(num-1,auxiliar,destino,origem);
}
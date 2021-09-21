#ifndef __lib_h_
#define __lib_h_

//typedef
#define info_t int

typedef struct disco
{
	info_t posicao;
	struct disco *proximo;
}Disco;

typedef struct pilha
{
	Disco *topo;
}Pilha;

//cria discos para inserir na pilha
Disco *create_disk(info_t num);
//1 cria uma pilha vazia
Pilha *create_pilha();
//liberando memoria alocada em uma pilha  e seus discos
void free_pilha(Pilha *p);
//3 inserir um elemento no topo da pilha
void push(info_t num, Pilha *p);
//6 print uma pilha
void print(Pilha *p);
//2 retorna o tamanho da pilha
info_t size(Pilha *p);
//4 remove um elemento do topo da lista e retorna o numero para criar o disco em outra pilha
info_t pop(Pilha *p);
//5 retorna o elemento do topo da lista
info_t peek(Pilha *p);
//funcao para printar os movimentos necessarios para solucao
void moves(int num,char origem,char destino,char auxiliar);
//funcao para resolver o problema da torre de hanoi seguindo a mesma ideia do print
void solve(info_t tamanho, Pilha *origem,Pilha *destino, Pilha *auxiliar);
#endif
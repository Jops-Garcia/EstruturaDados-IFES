#ifndef __lib_h_
#define __lib_h_

typedef struct celula
{
	int linha,coluna;
	float valor;
	struct celula *proxLinha;
	struct celula *proxColuna;
}Cell;


typedef struct cabeca
{
	int tamanho;
	Cell **vetLinha;
	Cell **vetColuna;
}Head;

Cell *cria_elem(int linha,int coluna,float valor);
void cria_vetor(int tamanho, Cell *vetor[]);
Head *cria_head(Cell **vetLinha,Cell **vetColuna,int tamanho);
Head *free_matriz(Head *a);
void insere_valor(int posLinha, int posColuna, float valor,Head *a);
void print_matriz(Head *a);
void remove_valor(int posLinha, int posColuna, Head *a);
float get_elem(int posLinha,int posColuna,Head *a);
void soma_matriz(Head *mat, Head *mat2, Head *resultado,int tamanho);
#endif
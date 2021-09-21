#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

//cria um elemento da matriz
Cell *cria_elem(int linha,int coluna,float valor)
{
	Cell *a;
	a=(Cell*)malloc(sizeof(Cell));
	if(a!=NULL)
	{
		a->proxLinha=NULL;
		a->proxColuna=NULL;
		a->valor=valor;
		a->linha=linha;
		a->coluna=coluna;
	}
	return a;
}

//cria um vetor
void cria_vetor(int tamanho, Cell *vetor[])
{
	int i;
	for (i=0;i<tamanho;i++) 
	{
		vetor[i]=malloc(sizeof(Cell));
		vetor[i]=NULL;
	}
}
//inserir o valor em uma determinada posicao - EX2
void insere_valor(int posLinha, int posColuna, float valor,Head *a)
{
	//caso valor seja zero
	if (valor==0.0)
	{
		//apaga elemento
		remove_valor(posLinha,posColuna,a);
		return;
	}
	Cell **lin;
	lin=a->vetLinha;
	Cell *auxLinha, *auxColuna;
	Cell *elemento;
	int testador;
	testador=0;
	
	//inserindo um elemento na linha
	//caso nao exista HEAD na linha
	if(lin[posLinha]==NULL)
	{
		elemento=cria_elem(posLinha,posColuna,valor);
		lin[posLinha]=elemento;
	}
	//caso exista um HEAD
	else if(lin[posLinha]!=NULL)
	{
		auxLinha=lin[posLinha];
		//caso exista um head e esteja na mesma coluna
		if(auxLinha->coluna==posColuna)
		{
			auxLinha->valor=valor;
		}
		//caso nao esteja na mesma coluna, como a insercao estao ordenadas...
		else if (auxLinha->coluna!=posColuna)
		{
			//percorrendo a linha da matriz
			while(auxLinha->proxColuna!=NULL && testador==0)
			{
				//caso seja a mesma coluna
				if(auxLinha->coluna==posColuna)
				{
					auxLinha->valor=valor;
					testador++;
					continue;
				}
				auxLinha=auxLinha->proxColuna;
				
			}
			if(auxLinha->coluna==posColuna)
			{
				auxLinha->valor=valor;
				testador++;
			}
			//inserindo no final
			if(testador==0)
			{
				elemento=cria_elem(posLinha,posColuna,valor);
				auxLinha->proxColuna=elemento;
			}
		}
	}
	
	//inserindo na coluna
	testador=0;
	lin=a->vetColuna;
	//caso nao exista HEAD na coluna
	if(lin[posColuna]==NULL)
	{
		lin[posColuna]=elemento;
	}
	//caso exista um HEAD
	else if(lin[posColuna]!=NULL)
	{
		auxColuna=lin[posColuna];
		//caso exista um head e esteja na mesma linha
		if(auxColuna->linha==posLinha)
		{
			auxColuna->valor=valor;
		}
		//caso nao esteja na mesma linha, como a insercao estao ordenadas...
		else if (auxColuna->linha!=posLinha)
		{
			//percorrendo a coluna da matriz
			while(auxColuna->proxLinha!=NULL && testador==0)
			{
				//caso seja a mesma linha
				if(auxColuna->linha==posLinha)
				{
					auxColuna->valor=valor;
					testador++;
					continue;
				}
				auxColuna=auxColuna->proxLinha;
				
			}
			//caso seja a mesma linha
			if(auxColuna->linha==posLinha)
			{
				auxColuna->valor=valor;
				testador++;
			}
			//inserindo no final
			if(testador==0)
			{
				auxColuna->proxLinha=elemento;
			}
		}
	}
}
//criando matriz - EX1
Head *cria_head(Cell **vetLinha,Cell **vetColuna,int tamanho)
{
	Head *a;
	a=(Head*)malloc(sizeof(Head));
	a->tamanho=tamanho;
	a->vetLinha=vetLinha;
	a->vetColuna=vetColuna;
	return a;
}

//Imprime matriz - EX4
void print_matriz(Head *a)
{
	Cell **linha;
	linha=a->vetLinha;
	int i;
	Cell *aux;
	printf("%d\n",a->tamanho);
	//loop para percorrer a matriz atraves das linhas
	for(i=0;i<a->tamanho;i++)
	{
		aux=linha[i];
		//caso a linha esteja vazia
		if(linha[i]==NULL)
		{
			continue;
		}
		while(aux->proxColuna!=NULL)
		{
			printf("%d;%d;%g\n",aux->linha+1,aux->coluna+1,aux->valor);
			aux=aux->proxColuna;
		}
		printf("%d;%d;%g\n",aux->linha+1,aux->coluna+1,aux->valor);
	}
}
//remover um valor da matriz - EX3
void remove_valor(int posLinha, int posColuna, Head *a)
{
	Cell **lin;
	lin=a->vetLinha;
	Cell *auxLinha, *auxAnterior; //*auxColuna
	Cell *elemento;
	int testador;
	testador=0;
	
	//removendo um elemento na linha
	//caso nao exista HEAD na linha
	if(lin[posLinha]==NULL)
	{
		return;
	}
	//caso exista um HEAD
	else if(lin[posLinha]!=NULL)
	{
		auxLinha=lin[posLinha];
		//caso seja o head
		if(auxLinha->coluna==posColuna)
		{
			elemento=auxLinha;
			//caso nao tenha nenhum proximo
			if(auxLinha->proxColuna==NULL)
			{
				lin[posLinha]=NULL;
			}
			else
			{
				//o proximo sera o novo head
				auxLinha=auxLinha->proxColuna;
				lin[posLinha]=auxLinha;
			}
		}
		//caso nao esteja na mesma coluna, como a insercao estao ordenadas...
		else if (auxLinha->coluna!=posColuna)
		{
			//percorrendo a linha da matriz
			while(auxLinha->proxColuna!=NULL && testador==0)
			{
				auxAnterior=auxLinha;
				//achou o elemento
				if(auxLinha->coluna==posColuna)
				{
					elemento=auxLinha;
					auxAnterior->proxColuna=elemento->proxColuna;
					testador++;
					continue;
				}
				auxLinha=auxLinha->proxColuna;
			}
			//caso seja o ultimo elemento
			if(auxLinha->coluna==posColuna)
			{
				elemento=auxLinha;
				auxAnterior->proxColuna=NULL;
				testador++;
			}
			//nao achou
			if(testador==0)
			{
				return;
			}
		}
	}
	//REMOVENDO DA COLUNA
	testador=0;
	lin=a->vetColuna;
	
	//procurando o elemento na coluna
	if(lin[posColuna]!=NULL)
	{
		auxLinha=lin[posColuna];
		//caso seja o head
		if(auxLinha->linha==posLinha)
		{
			//caso nao tenha nenhum proximo
			if(auxLinha->proxLinha==NULL)
			{
				lin[posColuna]=NULL;
			}
			else
			{
				//o proximo sera o novo head
				auxLinha=auxLinha->proxLinha;
				lin[posColuna]=auxLinha;
			}
		}
		//caso nao esteja na mesma coluna, como a insercao estao ordenadas...
		else if (auxLinha->linha!=posLinha)
		{
			//percorrendo a linha da matriz
			while(auxLinha->proxLinha!=NULL && testador==0)
			{
				auxAnterior=auxLinha;
				//achou o elemento
				if(auxLinha->linha==posLinha)
				{
					auxAnterior->proxLinha=elemento->proxLinha;
					testador++;
					continue;
				}
				auxLinha=auxLinha->proxLinha;
			}
			//caso seja o ultimo elemento
			if(auxLinha->linha==posLinha)
			{
				auxAnterior->proxLinha=NULL;
				testador++;
			}
		}
	}
	elemento=NULL;
	free(elemento);
}
//soma duas matrizes - EX5
void soma_matriz(Head *mat, Head *mat2, Head *resultado,int tamanho)
{
	int linha,coluna;
	float num,num2;
	float num3;
	num3=0;
	//usando dois loops para percorrer todas as posicoes possiveis da nova matriz
	for (linha=0;linha<tamanho;linha++)
	{
		for (coluna=0;coluna<tamanho;coluna++)
		{
			//pegando o valor dos elementos em determinada posicao
			num=get_elem(linha,coluna,mat);
			num2=get_elem(linha,coluna,mat2);
			num3=num+num2;
			if(num3!=0)
			{
				//inserindo os elementos somados na nova matriz
				insere_valor(linha,coluna,num3,resultado);
			}
		}
	}
}
//func para ajudar na soma, retorna o valor da posicao

float get_elem(int posLinha,int posColuna,Head *a)
{
	Cell **linha;
	linha=a->vetLinha;
	Cell *auxLinha;
	auxLinha=linha[posLinha];
	float val;
	int cont;
	cont=0;
	//percorrendo a matriz ate achar o elemento
	while(cont==0 && auxLinha!=NULL)
	{
		//caso o elemento seja encontrado
		if (auxLinha->coluna==posColuna)
		{
			cont++;
			val=auxLinha->valor;
		}
		else
		{
			auxLinha=auxLinha->proxColuna;
		}
	}
	if (cont==0)
	{
		val=0;
	}
	return val;
}

//desalocando matriz - EX6
Head *free_matriz(Head *a)
{
	Cell **linha;
	linha=a->vetLinha;
	int i;
	Cell *aux,*aux2;
	//loop para percorrer a matriz atraves das linhas
	for(i=0;i<a->tamanho;i++)
	{
		aux=linha[i];
		//caso a linha esteja vazia
		if(linha[i]==NULL)
		{
			aux=NULL;
			free(aux);
			continue;
		}
		while(aux->proxColuna!=NULL)
		{
			aux2=aux->proxColuna;
			aux=NULL;
			free(aux);
			aux=aux2;
		}
		aux=NULL;
		free(aux);
	}
	a=NULL;
	free(a);
	return NULL;
}
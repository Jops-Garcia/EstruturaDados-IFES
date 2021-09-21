#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc,char **argv)
{
	//Executando os arquivos e os atribuindo a  variaveis
	FILE *arquivo,*arquivo2;
	arquivo=fopen(argv[1],"r");
	arquivo2=fopen(argv[2],"r");
	
	//Verificando se os arquivos foram inseridos corretamente
	if (arquivo==NULL)
	{
		printf("Nao foi possivel abrir este arquivo %s \n",argv[1]);
		return 0;
	}
	if (arquivo2==NULL)
	{
		printf("Nao foi possivel abrir este arquivo %s \n",argv[2]);
		return 0;
	}
	
	int tamanho,tamanho2;
	//verificando se as duas matrizes possuem o mesmo tamanho;
	fscanf(arquivo,"%i",&tamanho);
	fscanf(arquivo2,"%i",&tamanho2);
	if(tamanho!=tamanho2)
	{
		printf("Por favor insira duas matrizes de tamanhos iguais.\n");
		return 0;
	}
	
	Head *matriz,*matriz2,*matriz3;
	//criando os vetores para 3 matrizes
	Cell *lin1[tamanho];
	Cell *col1[tamanho];
	Cell *lin2[tamanho];
	Cell *col2[tamanho];
	Cell *lin3[tamanho];
	Cell *col3[tamanho];
	
	//variaaveis para insercao
	int linha,coluna;
	float valor;
	
	cria_vetor(tamanho,lin1);
	cria_vetor(tamanho,lin2);
	cria_vetor(tamanho,lin3);
	cria_vetor(tamanho,col1);
	cria_vetor(tamanho,col2);
	cria_vetor(tamanho,col3);
	
	//alocando as matrizes
	matriz=cria_head(lin1,col1,tamanho);
	matriz2=cria_head(lin2,col2,tamanho);
	matriz3=cria_head(lin3,col3,tamanho);
	
	while (fscanf(arquivo,"%d;%d;%g\n",&linha,&coluna,&valor)!=EOF)
	{
		insere_valor(linha-1,coluna-1,valor,matriz);
	}
	//lendo arquivo2
	while (fscanf(arquivo2,"%d;%d;%g\n",&linha,&coluna,&valor)!=EOF)
	{
		insere_valor(linha-1,coluna-1,valor,matriz2);
	}
	//somando
	soma_matriz(matriz,matriz2,matriz3,tamanho);
	//printando a matriz
	print_matriz(matriz3);
	//desalocando
	matriz=free_matriz(matriz);
	matriz2=free_matriz(matriz2);
	matriz3=free_matriz(matriz3);
	
}
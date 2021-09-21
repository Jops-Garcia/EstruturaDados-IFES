#include <stdio.h>
#include "lib.h"
int main(int argc, char **argv)
{
	float matriz[4][2];
	int linha;
	int coluna;
	
	//preenchendo a matriz
	for(linha=0;linha<4;linha++)
	{
		for(coluna=0;coluna<2;coluna++)
		{
			printf("Informe o numero da linha %d e coluna %d :", linha+1,coluna+1);
			scanf("%f", &matriz[linha][coluna]);
		}
	}
	
	//invertendo a mariz
	InverteMatriz(matriz);
	//printand a matriz
	printf("\nA matriz invertida eh: \n");
	for(linha=0;linha<4;linha++)
	{
		for(coluna=0;coluna<2;coluna++)
		{
			printf("%.2f ",matriz[linha][coluna]);
		}
		printf("\n");
	}
}
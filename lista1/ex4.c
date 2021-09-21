#include <stdio.h>
#include "lib.h"
int main(int argc, char **argv)
{
	float matriz[3][3];
	float maior;
	int linha;
	int coluna;
	
	maior=0;
	//preenchendo a matriz
	for(linha=0;linha<3;linha++)
	{
		for(coluna=0;coluna<3;coluna++)
		{
			printf("Informe o numero da linha %d e coluna %d :", linha+1,coluna+1);
			scanf("%f", &matriz[linha][coluna]);
			if(maior<matriz[linha][coluna])
			{
				maior=matriz[linha][coluna];
			}
		}
	}
	//normalizando a matriz
	printf("\nA matriz normalizada eh: \n");
	for(linha=0;linha<3;linha++)
	{
		for(coluna=0;coluna<3;coluna++)
		{
			matriz[linha][coluna]=matriz[linha][coluna]/maior;
		}
	}
	
	ImprimeMatriz(matriz,3,3);
}
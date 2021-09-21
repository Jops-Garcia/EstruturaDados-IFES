#include <stdio.h>

int main(int argc, char **argv)
{
	float matriz[4][2];
	int linha;
	int coluna;
	int aux[2];
	
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
	for(linha=0;linha<4;linha=linha+2)
	{
		aux[0]=matriz[linha][0];
		aux[1]=matriz[linha][1];
		matriz[linha][0]=matriz[linha+1][0];
		matriz[linha][1]=matriz[linha+1][1];
		matriz[linha+1][0]=aux[0];
		matriz[linha+1][1]=aux[1];
	}
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
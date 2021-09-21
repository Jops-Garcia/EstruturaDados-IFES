#include <stdio.h>
#include "lib.h"
int main(int argc, char **argv)
{
	int vetor[7];
	int cont;
	int aux;
	int i;
	cont=0;
	//preenchendo vetor
	for (i=0;i<7;i++)
	{
		//inserindo os zeros faltando e parando o loop
		if(cont+i==7)
		{
			
			while (cont>0)
			{
				vetor[i]=0;
				i++;
				cont--;
			}
			break;
		}
		printf("informe o inteiro a ser inserido: \n");
		scanf("%d", &aux);
		//vendo se o numero eh zero para inserir no final
		if(aux==0)
		{
			i--;
			cont++;
		}
		else
		{
			vetor[i]=aux;
		}
		
	}
	//printando vetor
	printf(" Seu vetor eh: ");
	ImprimeVetor(7,vetor);
}
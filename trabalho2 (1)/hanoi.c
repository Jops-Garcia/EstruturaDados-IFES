#include <stdio.h>
#include "lib.h"
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[])
{
	//inteiro para receber numero da func atoi
	info_t tam,tam2;
	//criando as 3 pilhas
	Pilha *a,*b,*c;
	//Utilizando atoi estou limitado apenas aos inteiros
	//para numeros maiores usaria atol ou atoll
	tam=atoi(argv[1]);
	if (tam<1)
	{
		printf("Insira um numero inteiro valido \n");
		return 0;
	}
	tam2=tam;
	//criando as 3 pilhas
	a=create_pilha();
	b=create_pilha();
	c=create_pilha();
	//loop para adicionar os discos na pilha A
	while (tam!=0)
	{
		push(tam,a);
		tam--;
	}

	//comparando -v e printando movimentos
	if(argv[2]!=0)
	{
		if(strcmp(argv[2],"-v")==0)
		{
			printf("=> Resolvendo torre de Hanoi com %d discos.\n", tam2);
			
			printf("=> Configuracao inicial:\n");
			printf("\nA:");
			print(a);
			printf("\nB:");
			print(b);
			printf("\nC:");
			print(c);
			
			printf("\n\n=> Movimentos: \n\n");
			moves(tam2,'A','C','B');
		}
	}
	solve(tam2,a,c,b);
	
	if(argv[2]!=0)
	{
		if(strcmp(argv[2],"-v")==0)
		{
			printf("\n=> Configuracao Final:\n");
			printf("\nA:");
			print(a);
			printf("\nB:");
			print(b);
			printf("\nC:");
			print(c);
		}
	}
	free_pilha(a);
	free_pilha(b);
	free_pilha(c);

	return 0;
}
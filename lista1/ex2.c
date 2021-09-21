#include <stdio.h>
#include "lib.h"

int main(int argc, char **argv)
{
	int cont;
	int perfeitos[3];
	int num;
	num=2;
	cont=0;
	//while para 4 numeros
	while(cont<=3)
	{
		if(Perfeito(num)==1)
		{
			perfeitos[cont]=num;
			cont++;
		}
		num++;
	}
	printf( "os primeiros 4 numeros perfeitos sao: %d, %d, %d, %d.",perfeitos[0],perfeitos[1],perfeitos[2],perfeitos[3]);
}
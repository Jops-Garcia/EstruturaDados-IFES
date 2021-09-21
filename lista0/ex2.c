#include <stdio.h>

int main(int argc, char **argv)
{
	int cont;
	int somadiv;
	int perfeitos[3];
	int num;
	int aux;
	num=2;
	cont=0;
	//while para 4 numeros
	while(cont<=3)
	{
		
		somadiv=0;
		aux=1;
		//testando divisoes de resultado 0 ate o numero
		while(aux<num)
		{
			if(num%aux==0)
			{
				//somando os divisores
				somadiv=somadiv+aux;
			}
			aux++;
		}
		//verificando se o numero eh igual ao divisores e adicionando no vetor
		if(somadiv==num)
		{
			perfeitos[cont]=num;
			cont++;
		}
		num++;
	}
	printf( "os primeiros 4 numeros perfeitos sao: %d, %d, %d, %d.",perfeitos[0],perfeitos[1],perfeitos[2],perfeitos[3]);
}
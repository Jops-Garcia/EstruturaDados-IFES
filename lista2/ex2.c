#include <stdio.h>

void imprime(int *v,int tam)
{
	int aux;
	for(aux=0;aux<tam;aux++)
	{
		printf("%d, ", v[aux]);
	}
}
int main(int argc,char **argv)
{
	int vetor[20],tamVetor,cont;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamVetor);
	while(tamVetor>cont)
	{
		printf("Informe o valor do vetor na posicao %d: ", cont);
	scanf("%d", &vetor[cont]);
		cont++;
	}
	imprime(vetor,tamVetor);
}
#include <stdio.h>

float MediaEscolar(int qtdProvas)
{
	float aux;
	float notas;
	int i;
	//for para receber notas e somar
	for (i=1; i<=qtdProvas;i++)
	{
		printf("Informe o valor da prova %d: ",i);
		scanf("%f",&aux);
		notas=notas+aux;
	}
	//media
	notas=notas/qtdProvas;
	return notas;
}
int Perfeito(int num)
{
	int somadiv;
	int aux;
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
		return 1;
	}
	return 0;
}
void ImprimeVetor(int tamanho,int *vetor)
{
	int i;
	for(i=0;i<tamanho;i++)
	{
		printf(" %d,",vetor[i]);
	}
}
void ImprimeMatriz(float matriz[][3],int qtdLinhas,int qtdColunas)
{
	int linha;
	int coluna;
	
	for(linha=0;linha<qtdLinhas;linha++)
	{
		for(coluna=0;coluna<qtdColunas;coluna++)
		{
			printf("%.2f ",matriz[linha][coluna]);
		}
		printf("\n");
	}
}
float InverteMatriz(float matriz[][2])
{
	int linha;
	int aux[2];
	
	for(linha=0;linha<4;linha=linha+2)
	{
		aux[0]=matriz[linha][0];
		aux[1]=matriz[linha][1];
		matriz[linha][0]=matriz[linha+1][0];
		matriz[linha][1]=matriz[linha+1][1];
		matriz[linha+1][0]=aux[0];
		matriz[linha+1][1]=aux[1];
	}
	return matriz[4][2];
}
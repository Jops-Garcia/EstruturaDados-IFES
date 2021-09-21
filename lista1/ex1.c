#include <stdio.h>
#include "lib.h"
int main(int argc, char **argv)
{
	char nome[30];
	int provas;
	float notas;
	char lixo;
	//recebendo o nome
	printf("Informe o nome do aluno: ");
	scanf("%[^\n]s",nome);
	//recebendo qtd provas
	printf("Informe a quantidade de provas: ");
	//Professor, esta foi uma solucao que encontrei para resolver o "enter" sobrando na leitura com espacos. quero saber se existe uma forma melhor pois pareceu uma gambiarra.
	scanf("%d%c",&provas,&lixo);
	notas=MediaEscolar(provas);
	printf("O aluno %s obteve media %.2f",nome,notas);
}
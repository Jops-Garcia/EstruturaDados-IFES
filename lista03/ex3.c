#include <stdio.h>
//Nota para o prof: professor fiz com funcao para imprimir e scanear desde o primeiro ex. entao o ex3 já está aqui tbm 

struct stDados
{
	char nome[30];
	char endereco[40];
};
struct telefone
{
	int ddd;
	char tipo[7];
	int numero;
};
void scanst(struct stDados *x,struct telefone *y)
{
	char clixo;
	printf("Informe o nome da pessoa: ");
	scanf("%[^\n]s",x->nome);
	scanf("%c",&clixo);
	printf("Informe o endereco da pessoa: ");
	scanf("%[^\n]s", x->endereco);
	scanf("%c",&clixo);
	printf("Informe o ddd do telefone da pessoa: ");
	scanf("%d",&y->ddd);
	scanf("%c",&clixo);
	printf("Informe o tipo do telefone (celular ou fixo): ");
	scanf("%s",y->tipo);
	printf("Informe o numero de telefone: ");
	scanf("%d",&y->numero);
	scanf("%c",&clixo);
}
void imprime(struct stDados x,struct telefone y)
{
	printf("Este é o nome: %s endereco: %s telefone:(%s) %d%d \n",x.nome,x.endereco,y.tipo,y.ddd,y.numero);
}

int main(int argc,char **argv)
{
	struct stDados dados1,dados2,dados3;
	struct telefone tel1,tel2,tel3;
	
	scanst(&dados1,&tel1);
	scanst(&dados2,&tel2);
	scanst(&dados3,&tel3);
	printf("\n");
	imprime(dados1,tel1);
	imprime(dados2,tel2);
	imprime(dados3,tel3);
}
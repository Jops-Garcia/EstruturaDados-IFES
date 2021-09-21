#include <stdio.h>

struct stDados
{
	char nome[30];
	char endereco[40];
	int telefone;
};
void scanst(struct stDados *x)
{
	char clixo;
	printf("Informe o nome da pessoa: ");
	scanf("%[^\n]s",x->nome);
	scanf("%c",&clixo);
	printf("Informe o endereco da pessoa: ");
	scanf("%[^\n]s", x->endereco);
	scanf("%c",&clixo);
	printf("Informe o telefone da pessoa: ");
	scanf("%d",&x->telefone);
	scanf("%c",&clixo);
}
void imprime(struct stDados x)
{
	printf("Este é o nome: %s endereco: %s telefone: %d \n",x.nome,x.endereco,x.telefone);
}

int main(int argc,char **argv)
{
	struct stDados dados1,dados2,dados3;
	
	scanst(&dados1);
	scanst(&dados2);
	scanst(&dados3);
	printf("\n");
	imprime(dados1);
	imprime(dados2);
	imprime(dados3);
}
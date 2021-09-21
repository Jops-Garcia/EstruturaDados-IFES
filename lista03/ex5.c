#include <stdio.h>
#include <string.h>
struct elem
{
    int x;
    char s[100];
    float f[50];
};
int iguais(struct elem x,struct elem y)
{
	int aux;
    if (x.x==y.x)
    {
		for(aux=0;aux<100;aux++)
		{
			if (x.s[aux]!=y.s[aux])
			{
				 printf("As duas variaveis sao diferentes.");
				 return 0;
			}
		}
		for (aux=0;aux<50;aux++)
		{
			if (x.f[aux]!=y.f[aux])
			{
				printf("As duas variaveis sao diferentes.");
				 return 0;
			}
		}
    }
    printf("As duas variaveis sao diferentes.");
    return 0;
}

int main(int argc,char **argv)
{
    struct elem test1,test2;
	/*test1.x=1;
    test2.x=1;
    strcpy(test1.s,"alo");
    strcpy(test2.s,"alo");
    test1.f[0]=1;
    test2.f[0]=1;*/
    iguais(test1,test2);
}
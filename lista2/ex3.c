#include <stdio.h>

void swap(int *a,int *b)
{
	int aux;
	aux=*a;
	*a = *b;
	*b = aux;
}
int main(int argc,char **argv)
{
	int a,b;
	printf("Informe o valor de a: ");
	scanf("%d",&a);
	printf("Informe o valor de b: ");
	scanf("%d",&b);
	swap(&a,&b);
	printf(" A: %d  B: %d",a,b);
}
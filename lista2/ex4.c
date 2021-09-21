#include <stdio.h>

int main(int argc,char **argv)
{
	int matriz[5][4],cont,l,c;
	
	
	cont=0;
	for(l=0;l<5;l++)
	{
		for(c=0;c<4;c++)
		{
			matriz[l][c]=cont;
			cont++;
		}
	}
	//imprimindo
	for(l=0;l<5;l++)
	{
		for(c=0;c<4;c++)
		{
			printf("%d ",matriz[l][c]);
		}
		printf("\n");
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_str.h"
//EX3
void memaloc(String *s)
{
	s=malloc(sizeof(s));
}
//EX4

void fill(String *s,char *c, int len)
{
	s->vetor=malloc(sizeof(s->vetor)*len+1);
	strcpy(s->vetor,c);
	s->tam=len;
}
//EX5
void prints(String *s)
{
	printf("Esta eh sua string: %s, seu tamanho eh: %d\n",s->vetor,s->tam);
	
}
//EX6
void destroi(String *s)
{
	free(s->vetor);
	free(s);
}
//EX7
void concatena(String *s,String *s2,String *s3)
{

	fill(s3,strcat(s->vetor,s2->vetor),s2->tam+s->tam);

}
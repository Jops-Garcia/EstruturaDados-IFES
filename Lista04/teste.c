#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_str.h"

int main(int agrc, char **argv)
{
	char aux[100];
	String *s;
	String *s2;
	String *s3;
	
	s=malloc(sizeof(s));
	s2=malloc(sizeof(s2));
	s3=malloc(sizeof(s3));
	scanf("%s", aux);
	
	
	fill(s,aux, strlen(aux));
	fill(s2,aux, strlen(aux));
	concatena(s,s2,s3);
	
	prints(s);
	prints(s2);
	prints(s3);
	
	destroi(s);
	destroi(s2);
	destroi(s3);

}
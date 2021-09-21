#ifndef __list_h_
#define __list_h_
//ex1
typedef struct Vchar
{
	char *vetor;
	int tam;

}String;

void memaloc(String *s);
void fill(String *s,char *c, int len);
void prints(String *s);
void destroi(String *s);
void concatena(String *s,String *s2,String *s3);
#endif
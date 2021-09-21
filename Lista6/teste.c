#include <stdio.h>
#include "list.h"
#include <stdlib.h>

int main(int argc,char **argv)
{
	List *lista;
	Cell *a,*b;

	lista=create_list();

	b=create_cell(2);
	a=create_cell(1);
	
	print_cell(a);
	print_cell(b);
	printf("\n");

	lista=insert_first(lista,5);
	lista=insert_first(lista,4);
	//lista=insert_first(lista,3);
	lista=insert_first(lista,2);
	lista=insert_first(lista,1);
	lista=insert_last(lista,6);
	print_list(lista);
	printf("\n%d",size_list(lista));
	printf("\n%d",search(lista,3));
	printf("\n");
	lista=insert_list(lista,3,3);
	remover(lista,3);
	print_list(lista);
	printf("\n");
	remover(lista,1);
	print_list(lista);
	printf("\n");
	remover(lista,110);
	print_list(lista);
	seek_destroy(lista,4);
	printf("\n");
	print_list(lista);
	insert_ord(lista,6);
	printf("\n");
	print_list(lista);
	insert_ord(lista,1);
	printf("\n");
	print_list(lista);
	insert_ord(lista,3);
	printf("\n");
	print_list(lista);
	free_cell(b);
	free_cell(a);

	free_list(lista);
	
}
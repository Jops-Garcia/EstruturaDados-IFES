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
	
	lista=insert_first(lista,5);
	lista=insert_first(lista,4);
	lista=insert_first(lista,3);
	lista=insert_first(lista,2);
	lista=insert_first(lista,1);
	print_list(lista);
	
	free_cell(b);
	free_cell(a);

	free_list(lista);
	
}
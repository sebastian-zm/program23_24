#include <stdio.h>
#include <stdlib.h>
#include "diska.h"
#include "menua.h"
#include "list_helper.h"

int main()
{
	DISKA *d = NULL;
	LIST_HELPER_NODE *node = NULL;
	int aukera = 0;

	printf("===============DISKEN ARIKETA===============\n");

	while ((aukera = MENUA_aukera_eskatu())) {
		//1- elementua sortu
		DISKA_sortu(&d);

		//2- zerrenda sartu
		LIST_HELPER_create(&node, d, node);
	};

	LIST_HELPER_each(node, DISKA_bistaratu);

	LIST_HELPER_free(node, free);
}

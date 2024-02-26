#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "product.h"
#include "console_helper.h"
#include "client_menu.h"

int CLIENT_MENU_main(PRODUCT_VECTOR * products)
{
	char *option;
	bool irten = false;

	printf("KLIENTE MENU\n");
	printf("1. Produktuak bilatu\n");
	printf("2. Produktua erosi\n");
	printf("3. Irten\n");

	do { option = CONSOLE_HELPER_string_eskatu("Eman zure aukera: "); } while (!option);

	switch (option[0]) {
	case '1':
		CLIENT_MENU_bilatu(products);
		break;
	case '2':
		CLIENT_MENU_erosi(products);
		break;
	case '3':
		irten = true;
		break;
	default:
		printf("Errorea gertatu da aukera prozesatzean.\n");
	}
	free(option);

	CONSOLE_HELPER_itxaron("Sakatu return jarraitzeko...");
	system("clear");
	return !irten;
}

void CLIENT_MENU_bilatu(PRODUCT_VECTOR * products)
{
	char *name;
	char *desc;
	int len = PRODUCT_VECTOR_length(products);
	bool name_matches;
	bool matches;
	do name = CONSOLE_HELPER_string_eskatu("Eman produktuaren izenaren parte bat (zuriz guztiak ikusteko): "); while (!name);
	do desc = CONSOLE_HELPER_string_eskatu("Eman produktuaren deskripzioaren parte bat (zuriz guztiak ikusteko): ");while (!desc);

	for (int i = 0; i < len; ++i) {
		PRODUCT p = PRODUCT_VECTOR_get(products, i);
		name_matches = !!strstr(p.name, name);
		matches = name_matches && strstr(p.desc, desc);
		if (matches) {
			printf("Indizea: %d; Izena: %s; Deskripzioa: %s; Stock: %d\n", i, p.name, p.desc,
			       p.stock);
		}
	}

	free(name);
	free(desc);
}

void CLIENT_MENU_erosi(PRODUCT_VECTOR * products)
{
	char *name = CONSOLE_HELPER_string_eskatu("Eman produktuaren indizea: ");
	int idx;
	int len = PRODUCT_VECTOR_length(products);
	bool error = false;
	PRODUCT prod;
	if (name && name[0]) {
		sscanf(name, "%d", &idx);
		if (idx >= 0 && idx < len) {
			prod = PRODUCT_VECTOR_get(products, idx);
			if (0 >= --prod.stock) {
				PRODUCT_VECTOR_remove(products, idx);
			} else {
				PRODUCT_VECTOR_set(products, prod, idx);
			}
		} else {
			error = true;
		}
	} else {
		error = true;
	}
	if (name) free(name);
	if (error) printf("Errorea gertatu da.\n");
}

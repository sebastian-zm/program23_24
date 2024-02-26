#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "client_menu.h"
#include "console_helper.h"
#include "retail_menu.h"

int RETAIL_MENU_main(PRODUCT_VECTOR * products)
{
	char *option;
	bool irten = false;

	printf("SALTZAILE MENU\n");
	printf("1. Produktuak bilatu\n");
	printf("2. Produktua sortu\n");
	printf("3. Produktua aldatu\n");
	printf("4. Produktua kendu\n");
	printf("5. Irten\n");

	do option = CONSOLE_HELPER_string_eskatu("Eman zure aukera: "); while (!option);

	switch (option[0]) {
	case '1':
		CLIENT_MENU_bilatu(products);
		break;
	case '2':
		RETAIL_MENU_sortu(products);
		break;
	case '3':
		RETAIL_MENU_aldatu(products);
		break;
	case '4':
		RETAIL_MENU_kendu(products);
		break;
	case '5':
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

PRODUCT RETAIL_MENU_produktua_eskatu()
{
	PRODUCT prod;
	char* buffer;
	do {
		prod.name = CONSOLE_HELPER_string_eskatu("Eman produktuaren izena: ");
	} while (!prod.name);
	do {
		prod.desc = CONSOLE_HELPER_string_eskatu("Eman produktuaren deskripzioa: ");
	} while (!prod.desc);
	do {
		prod.stock = 0;
		buffer = CONSOLE_HELPER_string_eskatu("Eman produktuaren stock kopurua: ");
		if (buffer) {
			sscanf(buffer, "%d", &prod.stock);
			free(buffer);
		}
	} while (prod.stock <= 0);
	return prod;
}

void RETAIL_MENU_sortu(PRODUCT_VECTOR * products)
{
	PRODUCT prod = RETAIL_MENU_produktua_eskatu();
	PRODUCT_VECTOR_add(products, prod);
}

void RETAIL_MENU_aldatu(PRODUCT_VECTOR * products)
{
	int len = PRODUCT_VECTOR_length(products);
	char *buffer;
       	do { buffer = CONSOLE_HELPER_string_eskatu("Eman indizea: "); } while (!buffer);
	int idx;
	PRODUCT product;

	sscanf(buffer, "%d", &idx);
	free(buffer);

	if (idx >= 0 && idx < len) {
		product = PRODUCT_VECTOR_get(products, idx);
		free(product.name);
		free(product.desc);

		product = RETAIL_MENU_produktua_eskatu();

		PRODUCT_VECTOR_set(products, product, idx);
	}
}

void RETAIL_MENU_kendu(PRODUCT_VECTOR * products)
{
	int len = PRODUCT_VECTOR_length(products);
	char* buffer;
       	do { buffer = CONSOLE_HELPER_string_eskatu("Eman indizea: "); } while (!buffer);
	int idx;
	PRODUCT old_product;

	sscanf(buffer, "%d", &idx);
	free(buffer);

	if (idx >= 0 && idx < len) {
		old_product = PRODUCT_VECTOR_get(products, idx);
		free(old_product.name);
		free(old_product.desc);

		PRODUCT_VECTOR_remove(products, idx);
	}
}

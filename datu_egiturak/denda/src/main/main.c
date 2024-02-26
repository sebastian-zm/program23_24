#include <stdlib.h>
#include <stdbool.h>

#define UNUSED(x) do (void) x; while (0)

#include <stdio.h>
#include "user.h"
#include "product.h"
#include "admin_menu.h"
#include "client_menu.h"
#include "retail_menu.h"
#include "console_helper.h"

int main(int argc, char **argv)
{
	USER_VECTOR *users = USER_VECTOR_create();
	PRODUCT_VECTOR *products = PRODUCT_VECTOR_create();
	USER user;
	USER_TYPE type;
	bool exit = false;
	bool success;
	int retries;
	UNUSED(argc);
	UNUSED(argv);

	while (!exit) {
		retries = 3;
		success = false;
		if (USER_VECTOR_length(users)) {
			while (!success && retries > 0) {
				user.name = CONSOLE_HELPER_string_eskatu("Erabiltzailea: ");
				user.password = CONSOLE_HELPER_string_eskatu("Pasahitza: ");
				success = USER_login(users, &user);
				if (!success) {
					printf("Erabiltzaile ala pasahitza okerra.\n");
					CONSOLE_HELPER_itxaron("Sakatu return jarraitzeko...");
					system("clear");
				} else {
					type = user.type;
				}
				free(user.name);
				free(user.password);
				--retries;
			}
		} else {
			type = USER_ADMIN;
			success = true;
		}
		if (success) {
			system("clear");
			switch (type) {
			case USER_ADMIN:
				do {
				} while (ADMIN_MENU_main(users));
				break;
			case USER_RETAIL:
				do {
				} while (RETAIL_MENU_main(products));
				break;
			case USER_CLIENT:
				do {
				} while (CLIENT_MENU_main(products));
				break;
			default:
				printf("Ez implementatua.\n");
				CONSOLE_HELPER_itxaron("Sakatu return jarraitzeko...");
			}
			system("clear");
		} else {
			printf("Saiakera gehiegi. Irtetzen...\n");
			exit = 1;
		}
	}

	USER_VECTOR_destroy(users);
	PRODUCT_VECTOR_destroy(products);

	CONSOLE_HELPER_itxaron("Sakatu return bukatzeko...");
	return EXIT_SUCCESS;
}

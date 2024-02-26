#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "user.h"
#include "console_helper.h"
#include "admin_menu.h"

int ADMIN_MENU_main(USER_VECTOR * users)
{
	char *option;
	bool irten = false;

	printf("ADMIN MENU\n");
	printf("1. Erabiltzailea sortu\n");
	printf("2. Erabiltzailea aldatu\n");
	printf("3. Erabiltzailea kendu\n");
	printf("4. Erabiltzaileak bistaratu\n");
	printf("5. Irten\n");

	do option = CONSOLE_HELPER_string_eskatu("Eman zure aukera: "); while (!option);

	switch (option[0]) {
	case '1':
		ADMIN_MENU_sortu(users);
		break;
	case '2':
		ADMIN_MENU_aldatu(users);
		break;
	case '3':
		ADMIN_MENU_kendu(users);
		break;
	case '4':
		ADMIN_MENU_guztiak_ikusi(users);
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

USER ADMIN_MENU_erabiltzailea_eskatu()
{
	USER user;
	char *buffer;

	do user.name = CONSOLE_HELPER_string_eskatu("Eman izena: "); while (!user.name);
	do user.password = CONSOLE_HELPER_string_eskatu("Eman pasahitza: "); while (!user.password);

	bool success = false;
	while (!success) {
		buffer = CONSOLE_HELPER_string_eskatu("Eman mota (1: admin; 2: dendari; 3: kliente): ");
		if (!buffer) {
			printf("Ez dut lortu zure aukera prozesatzea. Saiatu berriro.\n");
		} else {
			switch (buffer[0]) {
			case '1':
				user.type = USER_ADMIN;
				success = true;
				break;
			case '2':
				user.type = USER_RETAIL;
				success = true;
				break;
			case '3':
				user.type = USER_CLIENT;
				success = true;
				break;
			default:
				printf("Ez dizut ulertu. Saiatu berriro.\n");
			}
			free(buffer);
		}
	}
	return user;
}

void ADMIN_MENU_sortu(USER_VECTOR * users)
{
	USER user = ADMIN_MENU_erabiltzailea_eskatu();
	USER_VECTOR_add(users, user);
}

void ADMIN_MENU_aldatu(USER_VECTOR * users)
{
	int len = USER_VECTOR_length(users);
	char *buffer;
	do buffer = CONSOLE_HELPER_string_eskatu("Eman indizea: "); while (!buffer);
	int idx;
	USER user;

	sscanf(buffer, "%d", &idx);
	free(buffer);

	if (idx >= 0 && idx < len) {
		USER old_user = USER_VECTOR_get(users, idx);
		free(old_user.name);
		free(old_user.password);

		user = ADMIN_MENU_erabiltzailea_eskatu();

		USER_VECTOR_set(users, user, idx);
	}
}

void ADMIN_MENU_kendu(USER_VECTOR * users)
{
	int len = USER_VECTOR_length(users);
	char *buffer;
	int idx;
	USER old_user;

	do buffer = CONSOLE_HELPER_string_eskatu("Eman indizea: "); while (!buffer);
	sscanf(buffer, "%d", &idx);
	free(buffer);

	if (idx >= 0 && idx < len) {
		old_user = USER_VECTOR_get(users, idx);
		free(old_user.name);
		free(old_user.password);

		USER_VECTOR_remove(users, idx);
	}
}

void ADMIN_MENU_guztiak_ikusi(USER_VECTOR * users)
{
	int len = USER_VECTOR_length(users);
	USER user;
	char *type;

	for (int i = 0; i < len; ++i) {
		user = USER_VECTOR_get(users, i);

		type = USER_type2str(user.type);
		printf("Indizea: %d; Izena: %s; Pasahitza: %s; Mota: %s\n", i, user.name, user.password, type);
	}
}

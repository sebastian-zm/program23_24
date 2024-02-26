#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "login.h"
#include "console_helper.h"

#define LOGIN_MAX_USER_LENGTH 63
#define LOGIN_MAX_PASS_LENGTH 63
#define LOGIN_MAX_FORMAT_LENGTH 20
#define LOGIN_TO_STR(x) #x
#define LOGIN_STR_FORMAT(x) "%" LOGIN_TO_STR(x) "s"

bool LOGIN_main(char *erabiltzaile_path)
{
	bool success;

	char username[LOGIN_MAX_USER_LENGTH + 1];
	char password[LOGIN_MAX_PASS_LENGTH + 1];

	fprintf(stdout, "Ongi etorri login orrira!\n");

	fprintf(stdout, "Erabiltzailea: ");
	CONSOLE_HELPER_eskatu_str(username, sizeof(username));

	fprintf(stdout, "Pasahitza: ");
	CONSOLE_HELPER_eskatu_str(password, sizeof(password));

	success = LOGIN_find_user(username, password, erabiltzaile_path);
	return success;
}

bool LOGIN_find_user(char *username, char *password, char *erabiltzaile_path)
{
	FILE *passwords_file = fopen(erabiltzaile_path, "r");
	char password_line[LOGIN_MAX_USER_LENGTH + LOGIN_MAX_PASS_LENGTH + 2];
	bool resolved = false;
	bool resolution = false;

	char current_username[LOGIN_MAX_USER_LENGTH + 1] = "";
	char current_password[LOGIN_MAX_PASS_LENGTH + 1] = "";

	while (!resolved
	       && fgets(password_line, sizeof(password_line), passwords_file)) {
		sscanf(password_line,
		       LOGIN_STR_FORMAT(LOGIN_MAX_USER_LENGTH) " "
		       LOGIN_STR_FORMAT(LOGIN_MAX_PASS_LENGTH),
		       current_username, current_password);

		resolved = strcmp(current_username, username) == 0;
		if (resolved) {
			resolution = strcmp(current_password, password) == 0;
		}
	}

	fclose(passwords_file);

	return resolution;
}

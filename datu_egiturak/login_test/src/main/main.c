#include <stdio.h>
#include <stdbool.h>
#include "login.h"
#include "params.h"
#include "console_helper.h"

int main(int argc, char **argv)
{
	char *erabiltzaile_path;

	read_params(argc, argv, &erabiltzaile_path);

	while (!LOGIN_main(erabiltzaile_path)) {
		fprintf(stdout, "Erabiltzaile ala pasahitza okerra!\n\n");
	}

	fprintf(stdout, "Ongi etorri aplikaziora!\n");

	CONSOLE_HELPER_itxaron("Sakatu return bukatzeko....");

	return 0;
}

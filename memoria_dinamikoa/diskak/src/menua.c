#include <stdio.h>
#include "console_helper.h"
#include "menua.h"

int MENUA_aukera_eskatu()
{
	int aukera = 0;
	printf("0. Irten\n");
	printf("1. Bat gehitu\n");

	CONSOLE_HELPER_aukera_eskatu(&aukera, 2, "Eman zure aukera: ", "Ez dizut ulertu. Saiatu berriro.");
	return aukera;
}

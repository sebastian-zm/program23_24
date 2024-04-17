#include <stdio.h>
#include <string.h>
#include "menua.h"

int MENUA_aukera_eskatu()
{
	char buffer[80];
	int ret;
	printf("Eman aukera: \n");
	printf("0. Irten\n");
	printf("1. Herrialdea gehitu\n");
	printf("2. Ip bat aldatu\n");
	printf("3. Herrialdeen datuak ikusi\n");
	printf("4. Trafiko datuak irakurri\n");
	printf("5. HTTPS konexioak zenbatu\n");
	printf("Eman aukera: ");

	fgets(buffer, sizeof buffer * sizeof buffer[0], stdin);

	if (strchr("012345", buffer[0])) {
		ret = buffer[0] - '0';
	} else {
		ret = -1;
	}

	return ret;
}

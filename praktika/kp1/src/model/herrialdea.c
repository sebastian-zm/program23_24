#include <stdio.h>
#include <string.h>
#include "array_helper.h"
#include "herrialdea.h"

ARRAY_HELPER_CREATE_ARRAY(HERRIALDEAK, HERRIALDEA, HERRIALDEAK_MAX)

HERRIALDEA HERRIALDEA_irakurri(FILE *fp)
{
	HERRIALDEA herr;
	if (5 > fscanf(fp, "%d.%d.%d.%d %s", herr.ip, herr.ip + 1, herr.ip + 2, herr.ip + 3, herr.izena)) {
		herr.izena[0] = '\0';
	}

	return herr;
}

HERRIALDEAK HERRIALDEAK_irakurri(FILE *fp)
{
	HERRIALDEAK herrk = HERRIALDEAK_create();
	HERRIALDEA herr;

	do {
		herr = HERRIALDEA_irakurri(fp);
		if (herr.izena[0]) {
			herrk = HERRIALDEAK_add(herrk, herr);
		}
	} while (herr.izena[0]);

	return herrk;
}

int HERRIALDEAK_izena_aurkitu(HERRIALDEAK herrk, char izena[])
{
	int i = 0;
	while (i < herrk.length && strcmp(herrk.data[i].izena, izena)) {
		++i;
	}

	if (i >= herrk.length) {
		i = -1;
	}

	return i;
}

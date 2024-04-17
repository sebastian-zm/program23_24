#include <stdio.h>
#include <string.h>
#include "array_helper.h"
#include "find_by_helper.h"
#include "herrialdea.h"


ARRAY_HELPER_CREATE_ARRAY(HERRIALDEAK, HERRIALDEA, HERRIALDEAK_MAX)

int HERRIALDEAK_find_by_net(HERRIALDEAK herrk, int ip[])
{
	int idx = 0;
	while (idx < herrk.length && memcmp(herrk.data[idx].ip, ip, 3 * sizeof(ip[0]))) {
		++idx;
	}
	if (idx == herrk.length) {
		idx = -1;
	}
	return idx;
}

int HERRIALDEAK_find_by_name(HERRIALDEAK herrk, char name[])
{
	int idx = 0;
	while (idx < herrk.length && strcmp(herrk.data[idx].izena, name)) {
		++idx;
	}
	if (idx == herrk.length) {
		idx = -1;
	}
	return idx;
}

HERRIALDEA HERRIALDEA_irakurri(FILE* fp)
{
	HERRIALDEA herr;

	if (5 > fscanf(fp, "%d.%d.%d.%d %s", &herr.ip[0], &herr.ip[1], &herr.ip[2], &herr.ip[3], herr.izena)) {
		herr.izena[0] = '\0'; // herri ez erabilgarria
	}

	return herr;
}

HERRIALDEAK HERRIALDEAK_irakurri(FILE* fp)
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



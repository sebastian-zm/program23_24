#ifndef HERRIALDEA_H
#define HERRIALDEA_H

#include <stdio.h>
#include "array_helper.h"

#define HERRIALDEA_MAX_STR 64
#define HERRIALDEAK_MAX 20

typedef struct HERRIALDEA_s {
	int ip[4];
	char izena[HERRIALDEA_MAX_STR];
} HERRIALDEA;

ARRAY_HELPER_CREATE_ARRAY_HEADER(HERRIALDEAK, HERRIALDEA, HERRIALDEAK_MAX)

HERRIALDEA HERRIALDEA_irakurri(FILE *fp);
HERRIALDEAK HERRIALDEAK_irakurri(FILE *fp);
int HERRIALDEAK_izena_aurkitu(HERRIALDEAK herrk, char izena[]);

#endif

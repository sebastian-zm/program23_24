#ifndef HERRIALDEA_H
#define HERRIALDEA_H

#define HERRIALDEA_MAX_STR 50
#define HERRIALDEAK_MAX 10

#include <stdio.h>
#include "array_helper.h"

typedef struct HERRIALDEA_s {
	char izena[HERRIALDEA_MAX_STR];
	int ip[4];
	int bisitak;
} HERRIALDEA;

ARRAY_HELPER_CREATE_ARRAY_HEADER(HERRIALDEAK, HERRIALDEA, HERRIALDEAK_MAX)

HERRIALDEA HERRIALDEA_irakurri(FILE* fp);
HERRIALDEAK HERRIALDEAK_irakurri(FILE* fp);
int HERRIALDEAK_find_by_name(HERRIALDEAK herrk, char name[]);
int HERRIALDEAK_find_by_net(HERRIALDEAK herrk, int ip[]);

#endif

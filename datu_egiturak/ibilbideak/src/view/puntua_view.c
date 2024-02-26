#include <math.h>
#include <stdio.h>
#include "puntua.h"
#include "puntua_view.h"


void PUNTUA_erakutsi(PUNTUA p)
{
	printf("%f, %f\n", p.x, p.y);
}

void PUNTUAK_erakutsi(PUNTUAK pk)
{
	int len = PUNTUAK_length(pk);
	int i;
	PUNTUA p;

	printf("Puntuak:\n");

	for (i = 0; i < len; ++i) {
		p = PUNTUAK_get(pk, i);
		PUNTUA_erakutsi(p);
	}
}

PUNTUA PUNTUA_eskatu()
{
	PUNTUA ret;
	char buffer[PUNTUA_MAX_STR + 1];

	printf("Eman x: ");
	fgets(buffer, PUNTUA_MAX_STR + 1, stdin);
	sscanf(buffer, "%lf", &ret.x);

	printf("Eman y: ");
	fgets(buffer, PUNTUA_MAX_STR + 1, stdin);
	sscanf(buffer, "%lf", &ret.y);

	return ret;
}

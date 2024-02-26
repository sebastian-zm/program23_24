#ifndef PUNTUA_H
#define PUNTUA_H

#include "array_helper.h"

#define PUNTUA_MAX_PUNTUAK 128
#define PUNTUA_MAX_STR 127

typedef struct PUNTUA_s {
	double x;
	double y;
} PUNTUA;

ARRAY_HELPER_CREATE_ARRAY_HEADER(PUNTUAK, PUNTUA, PUNTUA_MAX_PUNTUAK)

double PUNTUA_distantzia(PUNTUA p1, PUNTUA p2);

double PUNTUAK_luzera(PUNTUAK puntuak);

#endif // PUNTUA_H

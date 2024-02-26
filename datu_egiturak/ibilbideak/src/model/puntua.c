#include <math.h>
#include "puntua.h"

ARRAY_HELPER_CREATE_ARRAY(PUNTUAK, PUNTUA, PUNTUA_MAX_PUNTUAK)

double PUNTUA_distantzia(PUNTUA p1, PUNTUA p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}

double PUNTUAK_luzera(PUNTUAK puntuak)
{
	double ret = 0.0;
	for (int i = PUNTUAK_length(puntuak) - 1; i > 0; --i) {
		PUNTUA p1 = PUNTUAK_get(puntuak, i-1);
		PUNTUA p2 = PUNTUAK_get(puntuak, i);
		ret += PUNTUA_distantzia(p1, p2);
	}
	return ret;
}

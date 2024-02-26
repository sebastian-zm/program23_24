#ifndef IBILBIDEA_H
#define IBILBIDEA_H

#define IBILBIDEA_MAX_STR 127
#define IBILBIDEA_MAX_IBILBIDEAK 128

#include "array_helper.h"
#include "user.h"
#include "puntua.h"

typedef struct IBILBIDEA_s {
	int id;
	char izena[IBILBIDEA_MAX_STR + 1];
	char herria[IBILBIDEA_MAX_STR + 1];
	PUNTUAK puntuak;
	int user_id;
} IBILBIDEA;

ARRAY_HELPER_CREATE_ARRAY_HEADER(IBILBIDEAK, IBILBIDEA, IBILBIDEA_MAX_IBILBIDEAK)

int IBILBIDEA_belongs_to_user(IBILBIDEA i, USER user);
int IBILBIDEAK_aurkitu_id(IBILBIDEAK ibik, int id);
int IBILBIDEA_id_sortu(IBILBIDEAK ibik);



#endif // IBILBIDEA_H

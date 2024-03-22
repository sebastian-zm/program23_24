#ifndef ESKAERA_H
#define ESKAERA_H

#include <stdio.h>
#include "array_helper.h"

#define ESKAERAK_MAX 30
#define ESKAERA_MOTA_MAX_STR 5

#define ESKAERA_MOTAK_X \
	ESKAERA_MOTA_X(ESKAERA_MOTA_I3, "i3")\
	ESKAERA_MOTA_X(ESKAERA_MOTA_I5, "i5")\
	ESKAERA_MOTA_X(ESKAERA_MOTA_I7, "i7")\
	ESKAERA_MOTA_X(ESKAERA_MOTA_I9, "i9")\


typedef enum ESKAERA_MOTA_e {
#define ESKAERA_MOTA_X(mota, balioa) mota,
	ESKAERA_MOTAK_X
#undef ESKAERA_MOTA_X
} ESKAERA_MOTA;

typedef struct ESKAERA_s {
	int id;
	char mota;
	int kop;
} ESKAERA;

ARRAY_HELPER_CREATE_ARRAY_HEADER(ESKAERAK, ESKAERA, ESKAERAK_MAX)

ESKAERA ESKAERA_irakurri(FILE* fp);
ESKAERAK ESKAERAK_irakurri(FILE* fp);
void ESKAERA_MOTA_to_str(char str[], size_t size, ESKAERA_MOTA mota);
int ESKAERA_MOTA_from_str(char str[]);

#endif

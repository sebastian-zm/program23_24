#ifndef ALDERDIA_H
#define ALDERDIA_H

#include "array_helper.h"
#include "herria.h"

#define ALDERDIA_MAX_STR 50
#define ALDERDIAK_MAX 15

typedef struct ALDERDIA_s {
	int botoak;
	char izena[ALDERDIA_MAX_STR];
} ALDERDIA;

int ALDERDIAK_cmp(const void *a1, const void *a2);
void ALDERDIAK_irakurri(FILE* fp, ALDERDIA alderdiak[]);
void ALDERDIAK_ini(ALDERDIA alderdiak[]);
void ALDERDIAK_bozkatu(ALDERDIA alderdiak[], HERRIAK herrk);
void ALDERDIAK_idatzi(FILE* fp, ALDERDIA alderdiak[]);
void ALDERDIAK_idatzi_orden(FILE* fp, ALDERDIA alderdiak[]);


#endif

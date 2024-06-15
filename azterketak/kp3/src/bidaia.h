#ifndef BIDAIA_H
#define BIDAIA_H

#include "time_helper.h"
#include "console_helper.h"

#define BIDAIA_METROAK 120

typedef struct BIDAIA_s {
	TIME_HELPER_TIME ordua;
	int pisua;
	int pisuak;
} BIDAIA;

BIDAIA *BIDAIA_hasiera();
BIDAIA *BIDAIA_sortu();
char *BIDAIA_semaforoa(int metroak);
void BIDAIA_bistaratu(BIDAIA *bidaia);



#endif

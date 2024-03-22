#include <stdio.h>
#include "eskaera.h"
#include "aginduak.h"

void AGINDUAK_idatzi(FILE* fp, ESKAERAK eskaerak)
{
	int sum;
	int i;

#define ESKAERA_MOTA_X(MOTA, BALIOA) \
	sum = 0;\
	for (i = 0; i < ESKAERAK_length(eskaerak); ++i) {\
		ESKAERA esk = ESKAERAK_get(eskaerak, i);\
		if (esk.mota == MOTA) {\
			sum += esk.kop;\
		}\
	}\
	fprintf(fp, "%s %d\n", BALIOA, sum);

	ESKAERA_MOTAK_X
#undef ESKAERA_MOTA_X
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "array_helper.h"
#include "eskaera.h"

ARRAY_HELPER_CREATE_ARRAY(ESKAERAK, ESKAERA, ESKAERAK_MAX)

ESKAERA ESKAERA_irakurri(FILE* fp)
{
	ESKAERA esk;
	char mota[ESKAERA_MOTA_MAX_STR];
	bool ondo;
	int mota_int = -1;

	ondo = 3 == fscanf(fp, "%d %s %d\n", &esk.id, mota, &esk.kop);

	if (ondo) mota_int = ESKAERA_MOTA_from_str(mota);

	ondo = ondo && 0 >= mota_int;

       	if (ondo) {
		esk.mota = mota_int;
	} else {
		esk.id = -1;
	}

	return esk;
}

ESKAERAK ESKAERAK_irakurri(FILE* fp)
{
	ESKAERAK eskk = ESKAERAK_create();
	bool stop = false;

	do {
		ESKAERA esk = ESKAERA_irakurri(fp);
		stop = esk.id == -1;
		if (!stop)
			eskk = ESKAERAK_add(eskk, esk);
	} while (!stop);

	return eskk;
}

void ESKAERA_MOTA_to_str(char str[], size_t size, ESKAERA_MOTA mota)
{
#define ESKAERA_MOTA_X(MOTA, BALIOA) \
	if (mota == MOTA) {\
		strncpy(str, BALIOA, size);\
		str[size - 1] = '\0';\
	}

	ESKAERA_MOTAK_X
#undef ESKAERA_MOTA_X
}

int ESKAERA_MOTA_from_str(char str[])
{
	int ret = -1;
#define ESKAERA_MOTA_X(MOTA, BALIOA) \
	if (!strcmp(BALIOA, str)) {\
		ret = MOTA;\
	}

	ESKAERA_MOTAK_X
#undef ESKAERA_MOTA_X

	return ret;
}

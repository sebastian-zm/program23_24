#include <stdlib.h>
#include <stdbool.h>
#include "elur_datu.h"

int ELUR_DATUAK_idz_aurkitu(ELUR_DATUAK datuak, int id)
{
	bool aurkitua = false;
	int i = 0;
	while (!aurkitua && i < datuak.len) {
		if (datuak.arr[i].id == id) {
			aurkitua = true;
		} else {
			++i;
		}
	}

	if (i >= datuak.len) {
		i = -1;
	}

	return i;
}

int ELUR_DATUAK_id_sortu(ELUR_DATUAK datuak)
{
	int id;

	do {
		id = rand();
	} while (ELUR_DATUAK_idz_aurkitu(datuak, id) != -1);

	return id;
}

ELUR_DATUAK ELUR_DATUAK_add(ELUR_DATUAK datuak, ELUR_DATU datu)
{
	if (datuak.len < ELUR_DATUAK_MAX) {
		datuak.arr[datuak.len] = datu;
		++datuak.len;
	}

	return datuak;
}

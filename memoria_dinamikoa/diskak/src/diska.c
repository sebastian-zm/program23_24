#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console_helper.h"
#include "diska.h"

float DISKA_getPrezioa(DISKA d)
{
	return (float) d.prezioa / 100.0f;
}

void DISKA_setPrezioa(DISKA *d, float prezioa)
{
	d->prezioa = (int) (prezioa * 100.0f + 0.5f);
}

void DISKA_bistaratu(void *d)
{
	DISKA *disk = d;
	float prezioa = DISKA_getPrezioa(*disk);
	printf("DISKA:\n");
	printf("Izenburua: %s\n", disk->izenburua);
	printf("Taldea: %s\n", disk->taldea);
	printf("Urtea: %d\n", disk->urtea);
	printf("Estiloa: %s\n", disk->estiloa);
	printf("Prezioa: %.2f\n", prezioa);
	printf("\n");
}

int DISKA_sortu(DISKA **d)
{
	int ret;
	float prezioa;
	DISKA *diska;
	*d = malloc(sizeof(**d));
	if (*d) {
		prezioa = 1000000; // Erabiltzaileak prezioa gaizki sartzen badu
		diska = *d;

		CONSOLE_HELPER_string_eskatu(diska->izenburua, DISKA_MAX_STR, "Idatzi diskaren izenburua: ");
		CONSOLE_HELPER_string_eskatu(diska->taldea, DISKA_MAX_STR, "Idatzi taldearen izena: ");
		CONSOLE_HELPER_osoa_eskatu(&diska->urtea, "Idatzi diskaren edizio urtea: ", "Ez dizut ulertu, saiatu berriro.");
		CONSOLE_HELPER_string_eskatu(diska->estiloa, DISKA_MAX_STR, "Idatzi diskaren estiloa: ");
		CONSOLE_HELPER_float_eskatu(&prezioa, "Idatzi diskaren prezioa: ", "Ez dizut ulertu, saiatu berriro.");

		DISKA_setPrezioa(diska, prezioa);

		ret = 1;
	}else{
		ret = 0;
	}

	return ret;
}

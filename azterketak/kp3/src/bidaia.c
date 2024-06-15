#include <stdlib.h>
#include <stdio.h>
#include "bidaia.h"

BIDAIA *BIDAIA_hasiera()
{
	BIDAIA *bidaia = malloc(sizeof *bidaia);
	bidaia->pisuak = 0;
	bidaia->ordua.hour = 0;
	bidaia->ordua.min = 0;
	bidaia->ordua.sec = 0;
	bidaia->pisua = 0;
	return bidaia;
}

BIDAIA *BIDAIA_sortu()
{
	char buffer[128];
	int ondo;

	BIDAIA *bidaia = malloc(sizeof *bidaia);
	bidaia->pisuak = 0;
	do {
		printf("Zein da ordua? ");
		fgets(buffer, sizeof buffer / sizeof buffer[0], stdin);
		ondo = 3 == sscanf(buffer, "%d:%d:%d\n", &bidaia->ordua.hour, &bidaia->ordua.min, &bidaia->ordua.sec) && bidaia->ordua.hour >= 0 && bidaia->ordua.hour <= 24 && bidaia->ordua.min >= 0 && bidaia->ordua.min <= 60 && bidaia->ordua.sec >= 0 && bidaia->ordua.sec <= 60;
		if (!ondo) {
			printf("Ez dizut ulertu. Saiatu berriro.\n");
		}
	} while (!ondo);
	do {
		printf("Zein da pisua? ");
		fgets(buffer, sizeof buffer / sizeof buffer[0], stdin);
		ondo = 1 == sscanf(buffer, "%d\n", &bidaia->pisua);
		if (!ondo) {
			printf("Ez dizut ulertu. Saiatu berriro.\n");
		}
	} while (!ondo);

	return bidaia;
}

char *BIDAIA_semaforoa(int metroak)
{
	char *ret;
	if (metroak < 0.7 * BIDAIA_METROAK) {
		ret = "SEMAFORO BERDEA";
	} else if (metroak < 0.9 * BIDAIA_METROAK) {
		ret = "SEMAFORO LARANJA";
	} else {
		ret = "SEMAFORO GORRIA";
	}
	return ret;
}

void BIDAIA_bistaratu(BIDAIA *bidaia)
{
	printf("BIDAIA: Ordua: %d:%d:%d Pisua: %d\n", bidaia->ordua.hour, bidaia->ordua.min, bidaia->ordua.sec, bidaia->pisua);
}

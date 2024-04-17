#include <stdio.h>
#include <string.h>
#include "menua.h"
#include "herrialdea_view.h"

HERRIALDEAK MENUA(HERRIALDEAK herrk)
{
	int aukera;
	int idx;
	HERRIALDEA herr;

	while ((aukera = MENUA_aukera_eskatu())) {
		switch (aukera) {
			case 1:
				herr = HERRIALDEA_VIEW_eskatu();
				herrk = HERRIALDEAK_add(herrk, herr);
				break;
			case 2:
				idx = HERRIALDEA_VIEW_find_by_name(herrk);
				if (idx < 0) {
					printf("Ez da herrialdea aurkitu\n");
				} else {
					herr = HERRIALDEAK_get(herrk, idx);
					HERRIALDEA_VIEW_ip_aldatu(herr.ip);
					herrk = HERRIALDEAK_set(herrk, herr, idx);
				}
				break;
			case 3:
				HERRIALDEA_VIEW_danak_bistaratu(herrk);
				break;
			case 4:
				break;
			case 5:
				break;
		}
	}
	return herrk;
}

int MENUA_aukera_eskatu()
{
	int ret;
	int tmp;

	printf("0. Irten\n");
	printf("1. Herrialdea gehitu\n");
	printf("2. Ip aldatu\n");
	printf("3. Herrialdeak bistaratu\n");
	printf("4. Trafikoa kargatu\n");
	printf("5. HTTPS bezeroak kalkulatu\n");

	printf("\nEman aukera: ");
	
	do {
		ret = getchar();
	} while (ret != EOF && !strchr("012345", ret));
	
	do { // to discard until newline
		tmp = getchar();
	} while (tmp != EOF && tmp != '\n');

	if (ret == EOF) {
		ret = 0;
	} else { // to turn into int
		ret = ret - '0';
	}

	return ret;
}

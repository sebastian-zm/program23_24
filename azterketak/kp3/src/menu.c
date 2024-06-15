#include <stdio.h>
#include <stdlib.h>
#include "console_helper.h"
#include "menu_helper.h"
#include "list_helper.h"
#include "bidaia.h"
#include "igogailua.h"
#include "menu.h"

IGOGAILUA *MENU_igogailua_eskatu(LIST_HELPER_NODE *igogailuak)
{

	int ondo;
	int jarraitu;
	int id;
	IGOGAILUA *igogailua;
	do {
		jarraitu = CONSOLE_HELPER_osoa_eskatu(&id, "Eman id: ", "Ez dizut ulertu.");
		igogailua = LIST_HELPER_findWith(igogailuak, IGOGAILUA_has_this_id, &id);
		ondo = jarraitu && igogailua;
		if (!ondo) {
			printf("Ez dut igogailua aurkitu.\n");
		}
	} while (jarraitu && !ondo);
	return igogailua;
}

void MENU_bidaia_sortu(LIST_HELPER_NODE *igogailuak)
{
	IGOGAILUA *igogailua = MENU_igogailua_eskatu(igogailuak);
	BIDAIA *bidaia;

	if (igogailua) {
		bidaia = BIDAIA_sortu();
		LIST_HELPER_create(&igogailua->bidaiak, bidaia, igogailua->bidaiak);
	}

}

void MENU_bidaiak_bistaratu(LIST_HELPER_NODE *list)
{
	IGOGAILUA *igogailua = MENU_igogailua_eskatu(list);
	LIST_HELPER_NODE *bidaiak = igogailua->bidaiak;
	while (bidaiak) {
		BIDAIA_bistaratu(bidaiak->data);
		bidaiak = bidaiak->next;
	}
}

void MENU_pisuak_kalkulatu(LIST_HELPER_NODE *list)
{
	int diff;
	BIDAIA *b1, *b2;
	if (list && list->next) {
		MENU_pisuak_kalkulatu(list->next);
		b1 = list->data;
		b2 = list->next->data;
		diff = b1->pisua - b2->pisua;
		b1->pisuak = b2->pisuak + (diff < 0 ? -diff : diff);
	}
}

void MENU_semaforoa_erakutsi(LIST_HELPER_NODE *list)
{
	BIDAIA *bidaia;
	IGOGAILUA *igogailua = MENU_igogailua_eskatu(list);
	char *semaforoa;
	LIST_HELPER_NODE *bidaiak = igogailua->bidaiak;
	if (bidaiak) {
		bidaia = bidaiak->data;
		MENU_pisuak_kalkulatu(bidaiak);
		semaforoa = BIDAIA_semaforoa(4 * bidaia->pisuak);
		printf("Ibilbidea %d pisu izan dira eta %d metro.\n%s\n", bidaia->pisuak, 4 * bidaia->pisuak, semaforoa);
	}
}

void MENU_mantenketa(LIST_HELPER_NODE *list)
{
	BIDAIA *b;
	IGOGAILUA *igogailua = MENU_igogailua_eskatu(list);
	LIST_HELPER_NODE *bidaiak = igogailua->bidaiak;
	if (bidaiak) {
		if (bidaiak->next) {
			LIST_HELPER_free(bidaiak->next, free);
			bidaiak->next = NULL;
		}
		b = bidaiak->data;
		b->pisuak = 0;
	}
}

void MENU()
{
	LIST_HELPER_NODE *list = IGOGAILUAK_sortu();
	char *aukerak[] = {
		"Bidaia sortu",
		"Bidaiak bistaratu",
		"Metroak kalkulatu",
		"Mantenketa egin"
	};
	int aukerakKop = sizeof aukerak / sizeof aukerak[0];
	int aukera;

	while (MENU_HELPER_menua(&aukera, aukerak, aukerakKop, "Eman aukera: ", "Ez dizut ulertu. Saiatu berriro.") && aukera) {
		switch(aukera) {
			case 1:
				MENU_bidaia_sortu(list);
				break;
			case 2:
				MENU_bidaiak_bistaratu(list);
				break;
			case 3:
				MENU_semaforoa_erakutsi(list);
				break;
			case 4:
				MENU_mantenketa(list);
				break;
		}
	}

	LIST_HELPER_free(list, IGOGAILUA_free);
}


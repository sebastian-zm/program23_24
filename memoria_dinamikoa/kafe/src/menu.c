#include <stdio.h>
#include <stdlib.h>
#include "console_helper.h"
#include "time_helper.h"
#include "menu_helper.h"
#include "list_helper.h"
#include "kafe.h"
#include "menu.h"

int MENU_kafeDataGtr(void *k1, void *k2) {
	KAFE *kaf1 = k1;
	KAFE *kaf2 = k2;
	return 0 > TIME_HELPER_DATE_cmp(kaf1->data, kaf2->data);
	
}

void MENU_gehitu(LIST_HELPER_NODE **list)
{
	KAFE *kaf = KAFE_sortu();
	LIST_HELPER_insertBefore(list, kaf, MENU_kafeDataGtr, kaf);
}

void MENU_produkzioAzkena(LIST_HELPER_NODE *list)
{
	KAFE *curr;
	KAFE *next;
	if (list && list->next) {
		curr = list->data;
		next = list->next->data;
		printf("Gaur produkzioa %+fKg-koa izan da\n", curr->kiloak - next->kiloak);
	 } else {
		 printf("Ez dituzu kafe egun nahiko\n");
	 }
}

void MENU_produkzioa(LIST_HELPER_NODE *list)
{
	while (list && list->next) {
		MENU_produkzioAzkena(list);
		list = list->next;
	}
}

void MENU_bistaratu(LIST_HELPER_NODE *list)
{
	
	int n = 0;
	CONSOLE_HELPER_osoa_eskatu(&n, "Eman kopurua: ", "Hori ez da kopurua.");
	if (!n) {
		while (list) {
			KAFE_bistaratu(list->data);
			list = list->next;
		}
	} else {
		while (list && n > 0) {
			KAFE_bistaratu(list->data);
			list = list->next;
			--n;
		}
	}
}

void MENU()
{
	LIST_HELPER_NODE *list = NULL;
	char *aukerak[] = {
		"Kafe bat gehitu",
		"Azken egunetako produkzioa bistaratu",
		"Azken eguneko produkzio diferentzia bistaratu",
		"egun guztietako produkzio diferentzia bistaratu"
	};
	int aukerakKop = sizeof aukerak / sizeof aukerak[0];
	int aukera;

	while (MENU_HELPER_menua(&aukera, aukerak, aukerakKop, "Eman aukera: ", "Ez dizut ulertu. Saiatu berriro.") && aukera) {
		switch(aukera) {
			case 1:
				MENU_gehitu(&list);
				break;
			case 2:
				MENU_bistaratu(list);
				break;
			case 3:
				MENU_produkzioAzkena(list);
				break;
			case 4:
				MENU_produkzioa(list);
				break;
		}
	}

	LIST_HELPER_free(list, free);
}


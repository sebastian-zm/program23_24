#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "herrialdea.h"
#include "console_helper.h"
#include "menua.h"
#include "herrialdea_view.h"
#include "herrialdea.h"

#define HERRIALDEAK_PATH "herrialdeak.txt"

int main()
{
	FILE* herrk_fp = fopen(HERRIALDEAK_PATH, "r");
	HERRIALDEAK herrk;
	HERRIALDEA herr;
	char buffer[80];
	int auk;
	int idx;

	if (herrk_fp) {
		herrk = HERRIALDEAK_irakurri(herrk_fp);
		fclose(herrk_fp);
	} else {
		printf("%s fitxategia ez da existitzen.\n", HERRIALDEAK_PATH);
		exit(EXIT_FAILURE);
	}

	do {
		system("clear");
		switch (auk = MENUA_aukera_eskatu()) {
			case 0:
				break;
			case 1:
				herr = HERRIALDEA_VIEW_eskatu();
				herrk = HERRIALDEAK_add(herrk, herr);
				break;
			case 2:
				printf("Eman herrialdearen izena: ");
				fgets(buffer, sizeof buffer / sizeof buffer[0], stdin);
				idx = HERRIALDEAK_izena_aurkitu(herrk, buffer);
				if (idx == -1) {
					printf("Ez dut herrialdea aurkitu.\n");
				} else {
					HERRIALDEA_VIEW_ip_eskatu(herrk.data[idx].ip);
				}
				break;
			case 3:
				HERRIALDEAK_bistaratu(herrk);
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				printf("Ez dut aukera ulertu!\n");
				break;
		}
		CONSOLE_HELPER_itxaron("Sakatu return jarraitzeko...\n");
	} while (auk);

	return 0;
}

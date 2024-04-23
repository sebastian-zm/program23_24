#include <stdlib.h>
#include <stdio.h>
#include "filesystem_helper.h"
#include "console_helper.h"
#include "array_funcs_helper.h"
#include "kp1_helper.h"
#include "gasolindegia.h"


int main()
{
	FILESYSTEM_HELPER_cd_base_path();

	int id, idx, id_exis, ondo, add_litro;
	char buffer[KP1_HELPER_MAX_STR];
	FILE* gasolindegiak_fp = fopen("assets/gasolindegiak.txt", "r");

	if (!gasolindegiak_fp) {
		puts("fitxategia falta da: assets/gasolindegiak.txt");
		exit(EXIT_FAILURE);
	}

	GASOLINDEGIAK gasolindegiak = GASOLINDEGIAK_scan(gasolindegiak_fp); 
	GASOLINDEGIAK zabalik; 
	fclose(gasolindegiak_fp);


	FILE* batazbestekoa_fp = fopen("mediak.txt", "w");
	if (!batazbestekoa_fp) {
		puts("Errorea: mediak.txt");
		exit(EXIT_FAILURE);
	}
	GASOLINDEGIAK_VIEW_batazbeste_saldu(batazbestekoa_fp, gasolindegiak);
	fclose(batazbestekoa_fp);

	gasolindegiak = GASOLINDEGIAK_VIEW_osatu(gasolindegiak);

	FILE* egoera_fp = fopen("assets/egoera.txt", "r");
	if (!egoera_fp) {
		puts("fitxategia falta da: assets/egoera.txt");
		exit(EXIT_FAILURE);
	}

	gasolindegiak = GASOLINDEGIAK_osatu_zabalik(egoera_fp, gasolindegiak);
	fclose(egoera_fp);

	zabalik = gasolindegiak;
	GASOLINDEGIAK_print(stdout, gasolindegiak);
	ARRAY_FUNCS_HELPER_keep_if(zabalik.data, &zabalik.length, sizeof zabalik.data[0], GASOLINDEGIA_zabalik);
	GASOLINDEGIAK_VIEW_batazbeste_saldu(stdout, zabalik);

	do {
		id_exis = 0;
		do {
			ondo = CONSOLE_HELPER_osoa_eskatu(&id, "Sartu errekargatzeko id (zero bukatzeko): ", "Ez dizut ulertu. Saiatu berriro.\n");
			ondo = !!id;
			if (ondo) {
				idx = GASOLINDEGIAK_idz_aurkitu(id, gasolindegiak);
				id_exis = 0 <= idx;
				if (!id_exis) printf("Ez dut id-a aurkitu.\n");
			}
		} while (ondo && !id_exis);
		if (ondo) {
			CONSOLE_HELPER_osoa_eskatu(&add_litro, "Eman litroak (osoa): ", "Ez dizut ulertu. Saiatu berriro.\n");

			printf("Eman gasolina (g) ala gasoiloa(beste edozer): ");
			fgets(buffer, KP1_HELPER_MAX_STR, stdin);
			switch (buffer[0]) {
				case 'g':
				case 'G':
					gasolindegiak.data[idx].gasolina.litro += add_litro;
					break;
				default:
					gasolindegiak.data[idx].gasoila.litro += add_litro;
					break;
			}
			
			GASOLINDEGIAK_print(stdout, gasolindegiak);
		}
	} while (ondo);

	return EXIT_SUCCESS;
}

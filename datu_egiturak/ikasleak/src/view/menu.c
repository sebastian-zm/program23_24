#include <stdio.h>
#include "gela_view.h"
#include "menu.h"

int MENU_aukera_eskatu()
{
	char buffer[MENU_MAX_STR];
	int ret = -1;

	printf("---MENUA---\n");
	printf("0. Irten\n");
	printf("1. Gehitu ikaslea eta bere notak\n");
	printf("2. Borratu ikasle baten notak\n");
	printf("3. Eguneratu ikasle baten notak\n");
	printf("4. Bistaratu ikasle guztien notak\n");
	printf("5. Bistaratu klaseko noten batazbestekoa\n");
	printf("6. Bistaratu ikasgaia gainditu duten ikasleak\n");
	printf("7. Bistaratu gaindituen %%\n");
	printf("8. ID bidez ikasle bat bilatu\n");
	printf("\n");
	printf("Sartu aukera bat: ");

	fgets(buffer, MENU_MAX_STR, stdin);
	sscanf(buffer, "%i", &ret);

	if (ret < 0 || ret > 8) {
		ret = -1;
	}
	return ret;
}

GELA MENU_menu(GELA gela, int aukera)
{
	int idx;
	double nota;
	double gaindituen_ehunekoa;
	IKASLEA ik;
	IKASLEA gaindituak[GELA_MAX_IKASLEAK];
	int gaindituak_kop = 0;

	switch (aukera) {
		case 1:
			gela = GELA_VIEW_ikaslea_jaso(gela);
			break;
		case 2:
			idx = GELA_VIEW_ikaslea_bilatu(gela);
			if (idx >= 0) gela.ikasleak[idx] = IKASLEA_notak_borratu(gela.ikasleak[idx]);
			else printf("Ez dut aurkitu. =(\n");
			break;
		case 3:
			printf("Not implemented.\n");
			break;
		case 4:
			for (idx = 0; idx < gela.ikasle_kop; ++idx) {
				ik = gela.ikasleak[idx];
				printf("Izena: %s\n", ik.izena);
				for (int j = 1; j <= ik.kp_kop; ++j) {
					printf("kp%i nota: %f\n", j, ik.kp[j-1]);
				}
			}
			break;
		case 5:
			nota = GELA_batazbesteko_finala(gela);
			printf("Klaseko batazbestekoa: %f\n", nota);
			break;
		case 6:
			gaindituak_kop = GELA_gainditutako_ikasleak(gela, gaindituak, GELA_MAX_IKASLEAK);
			for (idx = 0; idx < gaindituak_kop; ++idx) {
				ik = gaindituak[idx];
				printf("Izena: %s\n", ik.izena);
			}
			break;
		case 7:
			gaindituen_ehunekoa = GELA_gaindituen_ehunekoa(gela);
			printf("%f%%\n", gaindituen_ehunekoa);
			break;
		case 8:
			idx = GELA_VIEW_ikaslea_bilatu(gela);
			if (idx >= 0) {
				ik = gela.ikasleak[idx];
				printf("Izena: %s\n", ik.izena);
			} else {
				printf("Ez dut aurkitu. =(\n");
			}
			break;
	}
	return gela;
}

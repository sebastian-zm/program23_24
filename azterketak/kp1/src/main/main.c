#include "menua.h"
#include "herrialdea_view.h"

int main()
{
	int aukera;
	int idx;
	FILE* herrk_fp = fopen("herrialdeak.txt", "r");
	HERRIALDEAK herrk = HERRIALDEAK_irakurri(herrk_fp);

	fclose(herrk_fp);

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
}

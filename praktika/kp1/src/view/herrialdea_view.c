#include "herrialdea.h"
#include "herrialdea_view.h"

HERRIALDEA HERRIALDEA_VIEW_eskatu()
{
	HERRIALDEA herr;
	printf("Eman herrialdearen izena: ");
	fgets(herr.izena, sizeof herr.izena / sizeof herr.izena[0], stdin);

	HERRIALDEA_VIEW_ip_eskatu(herr.ip);
	
	return herr;
}
void HERRIALDEA_VIEW_ip_eskatu(int ip[])
{
	char buffer[30];
	int ondo;
	do {
		printf("Eman herrialdearen ip-a (xxx.xxx.xxx.xxx): ");
		fgets(buffer, sizeof buffer / sizeof buffer[0], stdin);
		ondo = 4 <= sscanf(buffer, "%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
		if (!ondo) {
			printf("Ez dizut ulertu. ");
		}
	} while (!ondo);
}

void HERRIALDEA_bistaratu(HERRIALDEA herr)
{
		printf("herrialdea: %s; ip: %d.%d.%d.%d\n", herr.izena, herr.ip[0], herr.ip[1], herr.ip[2], herr.ip[3]);
}

void HERRIALDEAK_bistaratu(HERRIALDEAK herrk)
{
	int i;
	for (i = 0; i < herrk.length; ++i) {
		HERRIALDEA_bistaratu(herrk.data[i]);
	}
}
